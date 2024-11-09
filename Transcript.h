#pragma once
// TranscriptForm.h
class CTranscriptForm : public CFormView
{
    DECLARE_DYNCREATE(CTranscriptForm)
protected:
    CTranscriptForm();
public:
    enum { IDD = IDD_TRANSCRIPTFORM };
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    CString m_strStudentID;
    CListCtrl m_GradeList;

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnPrintTranscript();
    void LoadTranscript();
    void PrintTranscript();
};