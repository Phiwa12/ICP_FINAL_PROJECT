// DatabaseConnection.cpp
#include "DatabaseConnection.h"

CDatabaseConnection* CDatabaseConnection::m_instance = nullptr;

CDatabaseConnection::CDatabaseConnection()
{
}

CDatabaseConnection* CDatabaseConnection::GetInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new CDatabaseConnection();
    }
    return m_instance;
}

bool CDatabaseConnection::Connect()
{
    try
    {
        CString connectionString = _T("DRIVER={SQL Server};SERVER=localhost;DATABASE=UniversityDB;Trusted_Connection=yes;");
        return m_database.OpenEx(connectionString, CDatabase::noOdbcDialog);
    }
    catch (CDBException* e)
    {
        AfxMessageBox(e->m_strError);
        e->Delete();
        return false;
    }
}

void CDatabaseConnection::Disconnect()
{
    if (m_database.IsOpen())
        m_database.Close();
}