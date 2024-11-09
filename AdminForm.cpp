// AdminForm.cpp

#include "pch.h"
#include "AdminForm.h"
#include "Resource.h"

IMPLEMENT_DYNCREATE(CAdminForm, CFormView)

BEGIN_MESSAGE_MAP(CAdminForm, CFormView)
    ON_BN_CLICKED(IDC_ADD_USER, &CAdminForm::OnAddUser)
    ON_BN_CLICKED(IDC_EDIT_USER, &CAdminForm::OnEditUser)
    ON_BN_CLICKED(IDC_DELETE_USER, &CAdminForm::OnDeleteUser)
    ON_BN_CLICKED(IDC_GENERATE_REPORT, &CAdminForm::OnGenerateReport)
END_MESSAGE_MAP()

// Constructor
CAdminForm::CAdminForm() : CFormView(IDD_ADMINFORM)
{
}

// Data exchange between controls and data members
void CAdminForm::DoDataExchange(CDataExchange* pDX)
{
    CFormView::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_USER_LIST, m_UserList);
    DDX_Control(pDX, IDC_USER_TYPE_COMBO, m_UserTypeCombo);
}

// Load users into the list control
void CAdminForm::LoadUsers()
{
    // Clear existing items
    m_UserList.DeleteAllItems();

    // Sample code to add items to the list (replace with actual database retrieval)
    int nItem = m_UserList.InsertItem(0, _T("UserID001"));
    m_UserList.SetItemText(nItem, 1, _T("John Doe"));
    m_UserList.SetItemText(nItem, 2, _T("Admin"));

    // Additional code to retrieve and load user data from the database goes here
}

// Event handler for adding a new user
void CAdminForm::OnAddUser()
{
    // Implement logic to open a dialog for adding a new user
    AfxMessageBox(_T("Add User button clicked"));

    // Code for database insertion or form actions goes here
}

// Event handler for editing an existing user
void CAdminForm::OnEditUser()
{
    // Implement logic to edit the selected user
    AfxMessageBox(_T("Edit User button clicked"));

    // Code for retrieving user data and updating database goes here
}

// Event handler for deleting a user
void CAdminForm::OnDeleteUser()
{
    // Confirm deletion
    if (AfxMessageBox(_T("Are you sure you want to delete this user?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
    {
        // Logic to delete user from database goes here
        AfxMessageBox(_T("User deleted"));

        // Refresh the user list after deletion
        LoadUsers();
    }
}

// Event handler for generating a report
void CAdminForm::OnGenerateReport()
{
    // Implement logic to generate a report
    AfxMessageBox(_T("Generate Report button clicked"));

    // Code for report generation and export goes here
}
