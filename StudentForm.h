#pragma once
// StudentForm.h
class CStudentForm : public CFormView
{
    DECLARE_DYNCREATE(CStudentForm)
protected:
    CStudentForm();
public:
    enum { IDD = IDD_STUDENTFORM };
    virtual void DoDataExchange(CDataExchange* pDX);
protected:
    CString m_strStudentID;
    CString m_strName;
    CListBox m_CourseList;
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnEnrollCourse();
    afx_msg void OnViewGrades();
};