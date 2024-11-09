#pragma once
// SecurityManager.h
class CSecurityManager
{
private:
    static CSecurityManager* m_instance;
    CString m_currentUserID;
    CString m_userType;

    CSecurityManager();

public:
    static CSecurityManager* GetInstance();
    bool ValidateUser(const CString& username, const CString& password);
    bool HasPermission(const CString& operation);
    CString GetCurrentUserID() { return m_currentUserID; }
    CString GetUserType() { return m_userType; }
};