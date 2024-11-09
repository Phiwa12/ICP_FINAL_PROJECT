#pragma once
class CLoginDialog : public CDialog
{
public:
    CLoginDialog(CWnd* pParent = NULL);
    enum { IDD = IDD_LOGIN };
protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    CString m_strUsername;
    CString m_strPassword;
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedLogin();
};