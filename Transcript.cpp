// Transcript.cpp

#include "pch.h"
#include "Transcript.h"
#include "Resource.h"
#include "DatabaseManager.h"  // Hypothetical class for interacting with the database

IMPLEMENT_DYNCREATE(CTranscriptForm, CFormView)

BEGIN_MESSAGE_MAP(CTranscriptForm, CFormView)
    ON_BN_CLICKED(IDC_PRINT_TRANSCRIPT, &CTranscriptForm::OnPrintTranscript)  // Handler for the print button
END_MESSAGE_MAP()

// Constructor
CTranscriptForm::CTranscriptForm() : CFormView(IDD_TRANSCRIPTFORM)
{
}

// Data exchange between controls and data members
void CTranscriptForm::DoDataExchange(CDataExchange* pDX)
{
    CFormView::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_STUDENT_ID, m_strStudentID);  // Binds student ID edit control
    DDX_Control(pDX, IDC_GRADE_LIST, m_GradeList);  // Binds grade list control
}

// Load transcript data for the specified student
void CTranscriptForm::LoadTranscript()
{
    m_GradeList.DeleteAllItems();  // Clear any existing data in the list control

    // Example database interaction: Retrieve transcript for a specific student
    CString studentID;
    GetDlgItemText(IDC_STUDENT_ID, studentID);  // Get the entered student ID

    DatabaseManager db;  // Hypothetical class for database operations
    auto grades = db.GetGrades(studentID);  // Retrieve grades from database for the student

    int nItem = 0;
    for (const auto& grade : grades)
    {
        nItem = m_GradeList.InsertItem(nItem, grade.courseName);          // Insert course name
        m_GradeList.SetItemText(nItem, 1, grade.grade);                   // Insert grade
        m_GradeList.SetItemText(nItem, 2, grade.gpa);                     // Insert GPA
        nItem++;
    }
}

// Event handler for the print transcript button
void CTranscriptForm::OnPrintTranscript()
{
    PrintTranscript();
}

// Method to print the transcript
void CTranscriptForm::PrintTranscript()
{
    CDC dc;
    CPrintDialog printDlg(FALSE);

    if (printDlg.DoModal() == IDOK)
    {
        dc.Attach(printDlg.GetPrinterDC());
        dc.StartDoc(_T("Transcript Document"));

        // Setup font for printing
        CFont font;
        font.CreatePointFont(120, _T("Arial"), &dc);
        CFont* pOldFont = dc.SelectObject(&font);

        int yPos = 100;  // Y-position for printing

        // Print header information
        dc.TextOut(100, yPos, _T("Transcript for Student: ") + m_strStudentID);
        yPos += 200;

        // Loop through the grades and print each entry
        for (int i = 0; i < m_GradeList.GetItemCount(); i++)
        {
            CString course = m_GradeList.GetItemText(i, 0);
            CString grade = m_GradeList.GetItemText(i, 1);
            CString gpa = m_GradeList.GetItemText(i, 2);

            dc.TextOut(100, yPos, course + _T(" - ") + grade + _T(" (GPA: ") + gpa + _T(")"));
            yPos += 200;  // Move down for the next line
        }

        // Clean up
        dc.SelectObject(pOldFont);
        dc.EndDoc();
        dc.Detach();
    }
}
