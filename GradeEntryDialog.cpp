// GradeEntryDialog.cpp
#include "GradeEntryDialog.h"
#include "DatabaseConnection.h"

CGradeEntryDialog::CGradeEntryDialog(CWnd* pParent)
    : CDialog(IDD_GRADE_ENTRY, pParent), m_dGrade(0.0)
{
}

void CGradeEntryDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_GRADE, m_dGrade);
    DDV_MinMaxDouble(pDX, m_dGrade, 0.0, 4.0);
}

void CGradeEntryDialog::SetStudentAndCourse(const CString& studentID, const CString& courseID)
{
    m_strStudentID = studentID;
    m_strCourseID = courseID;
}

void CGradeEntryDialog::OnBnClickedSave()
{
    UpdateData(TRUE);

    CDatabaseConnection* db = CDatabaseConnection::GetInstance();
    if (!db->GetDB()->IsOpen())
        return;

    try
    {
        CString sql;
        sql.Format(_T("UPDATE Enrollments SET Grade = %.2f WHERE StudentID = '%s' AND CourseID = '%s'"),
            m_dGrade, m_strStudentID, m_strCourseID);

        db->GetDB()->ExecuteSQL(sql);
        EndDialog(IDOK);
    }
    catch (CDBException* e)
    {
        AfxMessageBox(e->m_strError);
        e->Delete();
    }
}