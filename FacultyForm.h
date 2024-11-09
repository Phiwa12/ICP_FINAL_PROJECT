#pragma once
// FacultyForm.h
class CFacultyForm : public CFormView
{
    DECLARE_DYNCREATE(CFacultyForm)
protected:
    CFacultyForm();
public:
    enum { IDD = IDD_FACULTYFORM };
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    CString m_strFacultyID;
    CString m_strName;
    CListCtrl m_StudentList;
    CComboBox m_CourseCombo;

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnEnterGrades();
    afx_msg void OnViewRoster();
    afx_msg void OnCourseSelect();
    void LoadCourses();
    void LoadStudents();
};
