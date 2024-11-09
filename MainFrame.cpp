#include "MainFrame.h"
#include "Resource.h"

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
    ON_WM_CREATE()
END_MESSAGE_MAP()

CMainFrame::CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;

    // Create Toolbr
    if (!m_wndToolBar.CreateEx(this) ||
        !m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
    {
        return -1;
    }

    // Creat Status bar
    if (!m_wndStatusBar.Create(this))
    {
        return -1;
    }

    // Positioning the toolbar
    m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
    EnableDocking(CBRS_ALIGN_ANY);
    DockControlBar(&m_wndToolBar);

    return 0;
}