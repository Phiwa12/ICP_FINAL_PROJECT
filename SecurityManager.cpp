// SecurityManager.cpp
#include "SecurityManager.h"
#include "DatabaseConnection.h"
#include <openssl/sha.h> // bycript algo

CSecurityManager* CSecurityManager::m_instance = nullptr;

CSecurityManager* CSecurityManager::GetInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new CSecurityManager();
    }
    return m_instance;
}

bool CSecurityManager::ValidateUser(const CString& username, const CString& password)
{
    CDatabaseConnection* db = CDatabaseConnection::GetInstance();
    if (!db->GetDB()->IsOpen())
        return false;

    try
    {
        // Hash password
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, password.GetBuffer(), password.GetLength());
        SHA256_Final(hash, &sha256);

        CString hashedPassword;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        {
            CString hex;
            hex.Format(_T("%02x"), hash[i]);
            hashedPassword += hex;
        }

        CRecordset recset(db->GetDB());
        CString sql;
        sql.Format(_T("SELECT UserID, UserType FROM Users WHERE Email = '%s' AND Password = '%s'"),
            username, hashedPassword);

        if (recset.Open(CRecordset::forwardOnly, sql))
        {
            if (!recset.IsEOF())
            {
                recset.GetFieldValue(_T("UserID"), m_currentUserID);
                recset.GetFieldValue(_T("UserType"), m_userType);
                recset.Close();
                return true;
            }
        }
    }
    catch (CDBException* e)
    {
        AfxMessageBox(e->m_strError);
        e->Delete();
    }

    return false;
}

// TranscriptPrinting Implementation
void CTranscriptForm::PrintTranscript()
{
    CPrintDialog printDlg(FALSE);
    if (printDlg.DoModal() == IDCANCEL)
        return;

    CDC dc;
    dc.Attach(printDlg.GetPrinterDC());

    int nHorizRes = dc.GetDeviceCaps(HORZRES);
    int nVertRes = dc.GetDeviceCaps(VERTRES);

    dc.StartDoc(_T("Student Transcript"));
    dc.StartPage();

    // Print header
    CFont headerFont;
    headerFont.CreateFont(36, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0,
        ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));

    CFont* pOldFont = dc.SelectObject(&headerFont);
    dc.TextOut(100, 100, _T("Official Transcript"));

    // Print student info
    CFont normalFont;
    normalFont.CreateFont(24, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0,
        ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));

    dc.SelectObject(&normalFont);

    CString studentInfo;
    studentInfo.Format(_T("Student ID: %s"), m_strStudentID);
    dc.TextOut(100, 200, studentInfo);

    // Print grades
    int y = 300;
    for (int i = 0; i < m_GradeList.GetItemCount(); i++)
    {
        CString course = m_GradeList.GetItemText(i, 0);
        CString grade = m_GradeList.GetItemText(i, 1);
        CString line;
        line.Format(_T("%s: %s"), course, grade);
        dc.TextOut(100, y, line);
        y += 30;
    }

    dc.SelectObject(pOldFont);
    dc.EndPage();
    dc.EndDoc();
    dc.Detach();
}

// Report Generation Implementation
void CAdminForm::GenerateReport()
{
    CDatabaseConnection* db = CDatabaseConnection::GetInstance();
    if (!db->GetDB()->IsOpen())
        return;

    try
    {
        // Get enrollment statistics
        CRecordset recset(db->GetDB());
        CString sql = _T("SELECT COUNT(*) as StudentCount, AVG(Grade) as AvgGrade, CourseID \
                         FROM Enrollments GROUP BY CourseID");

        if (recset.Open(CRecordset::forwardOnly, sql))
        {
            CStdioFile file;
            if (file.Open(_T("EnrollmentReport.csv"), CFile::modeCreate | CFile::modeWrite))
            {
                file.WriteString(_T("Course,Student Count,Average Grade\n"));

                while (!recset.IsEOF())
                {
                    CString courseID, studentCount, avgGrade;
                    recset.GetFieldValue(_T("CourseID"), courseID);
                    recset.GetFieldValue(_T("StudentCount"), studentCount);
                    recset.GetFieldValue(_T("AvgGrade"), avgGrade);

                    CString line;
                    line.Format(_T("%s,%s,%s\n"), courseID, studentCount, avgGrade);
                    file.WriteString(line);

                    recset.MoveNext();
                }

                file.Close();
                AfxMessageBox(_T("Report generated successfully!"));
            }
        }
    }
    catch (CDBException* e)
    {
        AfxMessageBox(e->m_strError);
        e->Delete();
    }
}

// Add Audit Trail functionality
class CAuditTrail
{
public:
    static void LogAction(const CString& userID, const CString& action)
    {
        CDatabaseConnection* db = CDatabaseConnection::GetInstance();
        if (!db->GetDB()->IsOpen())
            return;

        try
        {
            CString sql;
            sql.Format(_T("INSERT INTO AuditTrail (UserID, Action, ActionDate) \
                          VALUES ('%s', '%s', GETDATE())"),
                userID, action);
            db->GetDB()->ExecuteSQL(sql);
        }
        catch (CDBException* e)
        {
            // Log error but don't show to user
            TRACE(_T("Audit trail error: %s\n"), e->m_strError);
            e->Delete();
        }
    }
};
