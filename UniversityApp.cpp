// UniversityApp.cpp
#include "UniversityApp.h"
#include "MainFrame.h"
#include "LoginDialog.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
using namespace std;

BEGIN_MESSAGE_MAP(CUniversityApp, CWinApp)
END_MESSAGE_MAP()

CUniversityApp::CUniversityApp()
{
}

void connectToDatabase() {
    try {
        // Create a connection to the MySQL server
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection* con = driver->connect("tcp://127.0.0.1:3306", "root", "");  
        con->setSchema("UniversityDB");

        cout << "Connected to the database successfully!" << endl;

        // Clean up
        delete con;
    }
    catch (sql::SQLException& e) {
        cerr << "Error connecting to MySQL: " << e.what() << endl;
    }
}

BOOL CUniversityApp::InitInstance() {
    CWinApp::InitInstance();

    // Show login dialog first
    CLoginDialog loginDlg;
    if (loginDlg.DoModal() != IDOK) {
        return FALSE;
    }

    // After login, fetch user role from database 
    string userType = loginDlg.getUserType(); // Assume this method gets the UserType from the database

    if (userType == "Student") {
        // Initialize Student UI
        CStudentFrame* pStudentFrame = new CStudentFrame;
        pStudentFrame->ShowWindow(SW_SHOW);
    }
    else if (userType == "Faculty") {
        // Initialize Faculty UI
        CFacultyFrame* pFacultyFrame = new CFacultyFrame;
        pFacultyFrame->ShowWindow(SW_SHOW);
    }
    else if (userType == "Admin") {
        // Initialize Admin UI
        CAdminFrame* pAdminFrame = new CAdminFrame;
        pAdminFrame->ShowWindow(SW_SHOW);
    }

    return TRUE;
}

