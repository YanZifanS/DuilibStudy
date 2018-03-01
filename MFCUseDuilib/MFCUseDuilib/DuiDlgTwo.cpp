#include "stdafx.h"
#include "MFCUseDuilib.h"
#include "DuiDlgTwo.h"
#include "MainWnd.h"

IMPLEMENT_DYNAMIC(CDuiDlgTwo, CDialog)

CDuiDlgTwo::CDuiDlgTwo(CWnd* pParent)
	: CDialog(CDuiDlgTwo::IDD, pParent)
{
	m_nNum = 0;
}

CDuiDlgTwo::~CDuiDlgTwo()
{
}

void CDuiDlgTwo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDuiDlgTwo, CDialog)
END_MESSAGE_MAP()


BOOL CDuiDlgTwo::OnInitDialog()
{
	CDialog::OnInitDialog();
	/*
	DWORD dwStyle = GetStyle();
	DWORD dwNewStyle = WS_OVERLAPPED | WS_VISIBLE| WS_SYSMENU |WS_MINIMIZEBOX|WS_MAXIMIZEBOX|WS_CLIPCHILDREN|WS_CLIPSIBLINGS;    
	dwNewStyle&=dwStyle;   
	SetWindowLong(m_hWnd,GWL_STYLE,dwNewStyle);  
	DWORD dwExStyle = GetExStyle();   
	DWORD dwNewExStyle = WS_EX_LEFT |WS_EX_LTRREADING |WS_EX_RIGHTSCROLLBAR;    
	dwNewExStyle&=dwExStyle;    
	SetWindowLong(m_hWnd,GWL_EXSTYLE,dwNewExStyle);   
	SetWindowPos(NULL,0,0,0,0,SWP_NOZORDER|SWP_NOMOVE|SWP_NOSIZE|SWP_FRAMECHANGED);
	*/
	int n = m_nNum;
	CPaintManagerUI::SetInstance(AfxGetInstanceHandle());
	CDuiString szString = CPaintManagerUI::GetInstancePath();
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("Skin"));
	CMainWnd *pMainWnd = new CMainWnd("MainWnd.xml", this->m_hWnd);
	pMainWnd->Create(*this, _T("Duilib"), UI_WNDSTYLE_CHILD, 0, 0, 0, 0, 0);
	pMainWnd->ShowWindow(true);
	return TRUE;  
}

void CDuiDlgTwo::GetNum(int nNum)
{
	m_nNum = nNum;
}