#include "stdafx.h"
#include "MainWnd.h"
#include "MfcWndUI.h"

#define IDC_BTN_MFC 10086
CMainWnd::CMainWnd( LPCTSTR pszXMLPath, HWND hWnd) : CXMLBaseWnd(pszXMLPath)
{
	m_hWnd = hWnd;
	m_nCount = 0;
}

CMainWnd::~CMainWnd(void)
{
}

void CMainWnd::InitWindow()
{
	//duilib 中使用 MFC中的按钮可以直接加入位置,大小等
	CMfcWndUI *pUI   = new CMfcWndUI();     
	CButton *pButton = new CButton();
	pButton->Create("MFC", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, CRect(100, 50, 200, 80), CWnd::FromHandle(m_PaintManager.GetPaintWindow()), IDC_BTN_MFC);
	pUI->Attach(pButton->GetSafeHwnd()); 
}

LRESULT CMainWnd::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	__super::OnCreate(uMsg, wParam, lParam, bHandled);
	m_WndShadow.Create(GetHWND());
	m_WndShadow.SetSize(10);  
	m_WndShadow.SetPosition(0, 0);
	m_WndShadow.SetColor(RGB(0xA6, 0xA6, 0xA6));
	return 0;
}

void CMainWnd::Notify(TNotifyUI& msg)
{
	__super::Notify(msg);
}

void CMainWnd::OnClick(TNotifyUI& msg)
{
	CDuiString szName = msg.pSender->GetName();
	if (szName == "TextBtn")
	{
		MessageBox(NULL, "MFC使用duilib", "", 0);
	}
	if (szName == "closebtn")
	{
		::SendMessage(m_hWnd, WM_CLOSE, NULL, NULL);
	}
	__super::OnClick(msg);
}

LRESULT CMainWnd::HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	LRESULT lRes = 0;
	bHandled = FALSE;
	switch (uMsg)
	{
		case WM_COMMAND:
			if (wParam == IDC_BTN_MFC)
			{
				AfxMessageBox("123");
				/*CMainWnd *pFirstWnd = new CMainWnd("MainWnd.xml");
				pFirstWnd->Create(NULL, "Duilib", UI_WNDSTYLE_DIALOG, WS_EX_WINDOWEDGE);
				pFirstWnd->CenterWindow();
				pFirstWnd->ShowModal();*/
			}
			break;
		default:
			break;
	}
	return 0;
}

