// FacultyForm.cpp
#include "FacultyForm.h"
#include "DatabaseConnection.h"

IMPLEMENT_DYNCREATE(CFacultyForm, CFormView)

CFacultyForm::CFacultyForm() : CFormView(CFacultyForm::IDD)
{
    m_strFacultyID = _T("");
    m_strName = _T("");
}

void CFacultyForm::DoDataExchange(CDataExchange* pDX)
{
    CFormView::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_FACULTY_ID, m_strFacultyID);
    DDX_Text(pDX, IDC_FACULTY_NAME, m_strName);
    DDX_Control(pDX, IDC_STUDENT_LIST, m_StudentList);
    DDX_Control(pDX, IDC_COURSE_COMBO, m_CourseCombo);
}

BEGIN_MESSAGE_MAP(CFacultyForm, CFormView)
    ON_BN_CLICKED(IDC_ENTER_GRADES, &CFacultyForm::OnEnterGrades)
    ON_BN_CLICKED(IDC_VIEW_ROSTER, &CFacultyForm::OnViewRoster)
    ON_CBN_SELCHANGE(IDC_COURSE_COMBO, &CFacultyForm::OnCourseSelect)
END_MESSAGE_MAP()

void CFacultyForm::LoadCourses()
{
    m_CourseCombo.ResetContent();

    CDatabaseConnection* db = CDatabaseConnection::GetInstance();
    if (!db->GetDB()->IsOpen())
        return;

    CRecordset recset(db->GetDB());
    CString sql = _T("SELECT CourseID, CourseName FROM Courses WHERE FacultyID = '") + m_strFacultyID + _T("'");

    if (recset.Open(CRecordset::forwardOnly, sql))
    {
        while (!recset.IsEOF())
        {
            CString courseID, courseName;
            recset.GetFieldValue(_T("CourseID"), courseID);
            recset.GetFieldValue(_T("CourseName"), courseName);
            m_CourseCombo.AddString(courseID + _T(" - ") + courseName);
            recset.MoveNext();
        }
        recset.Close();
    }
}