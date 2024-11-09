// LoginDialog.cpp
#include "LoginDialog.h"
#include "Resource.h"
#include <afxdb.h>

CLoginDialog::CLoginDialog(CWnd* pParent) : CDialog(IDD_LOGIN, pParent)
{
    m_strUsername = _T("");
    m_strPassword = _T("");
}

void CLoginDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_USERNAME, m_strUsername);
    DDX_Text(pDX, IDC_PASSWORD, m_strPassword);
}

BEGIN_MESSAGE_MAP(CLoginDialog, CDialog)
    ON_BN_CLICKED(IDC_LOGIN, &CLoginDialog::OnBnClickedLogin)
END_MESSAGE_MAP()

void CLoginDialog::OnBnClickedLogin()
{
    UpdateData(TRUE);

    // TODO: we have to Add database authentication logic here
    // used  placeholder validation for now
    if (!m_strUsername.IsEmpty() && !m_strPassword.IsEmpty())
    {
        EndDialog(IDOK);
    }
    else
    {
        MessageBox(_T("Please enter username and password"), _T("Login Error"), MB_ICONERROR);
    }
}
