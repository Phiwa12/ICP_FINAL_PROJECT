#pragma once
#include <afxdb.h>

class CDatabaseConnection
{
private:
    static CDatabaseConnection* m_instance;
    CDatabase m_database;
    CDatabaseConnection();

public:
    static CDatabaseConnection* GetInstance();
    bool Connect();
    void Disconnect();
    CDatabase* GetDB() { return &m_database; }
};