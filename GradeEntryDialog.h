#pragma once
class CGradeEntryDialog : public CDialog
{
public:
    CGradeEntryDialog(CWnd* pParent = NULL);
    enum { IDD = IDD_GRADE_ENTRY };
protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    CString m_strStudentID;
    CString m_strCourseID;
    double m_dGrade;
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedSave();
    void SetStudentAndCourse(const CString& studentID, const CString& courseID);
};