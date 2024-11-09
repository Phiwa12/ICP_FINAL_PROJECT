#pragma once
// AdminForm.h
class CAdminForm : public CFormView
{
    DECLARE_DYNCREATE(CAdminForm)
protected:
    CAdminForm();
public:
    enum { IDD = IDD_ADMINFORM };
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    CListCtrl m_UserList;
    CComboBox m_UserTypeCombo;

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnAddUser();
    afx_msg void OnEditUser();
    afx_msg void OnDeleteUser();
    afx_msg void OnGenerateReport();
    void LoadUsers();
};
