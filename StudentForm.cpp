// StudentForm.cpp
#include "StudentForm.h"

IMPLEMENT_DYNCREATE(CStudentForm, CFormView)

CStudentForm::CStudentForm() : CFormView(CStudentForm::IDD)
{
    m_strStudentID = _T("");
    m_strName = _T("");
}

void CStudentForm::DoDataExchange(CDataExchange* pDX)
{
    CFormView::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_STUDENT_ID, m_strStudentID);
    DDX_Text(pDX, IDC_STUDENT_NAME, m_strName);
    DDX_Control(pDX, IDC_COURSE_LIST, m_CourseList);
}

BEGIN_MESSAGE_MAP(CStudentForm, CFormView)
    ON_BN_CLICKED(IDC_ENROLL, &CStudentForm::OnEnrollCourse)
    ON_BN_CLICKED(IDC_VIEW_GRADES, &CStudentForm::OnViewGrades)
END_MESSAGE_MAP()

void CStudentForm::OnEnrollCourse()
{
    // TODO: we have to implement course enrollment logic
}

void CStudentForm::OnViewGrades()
{
    // TODO: we have to implement grade viewing logic
}