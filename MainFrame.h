// MainFrame.h
#pragma once
#include <afxwin.h>
#include <afxext.h>

class CMainFrame : public CMDIFrameWnd
{
    DECLARE_DYNAMIC(CMainFrame)
public:
    CMainFrame();
protected:
    CStatusBar m_wndStatusBar;
    CToolBar m_wndToolBar;
    DECLARE_MESSAGE_MAP()
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

