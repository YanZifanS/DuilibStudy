// MFCUseDuilib.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "MFCUseDuilib.h"
#include "MFCUseDuilibDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCUseDuilibApp

BEGIN_MESSAGE_MAP(CMFCUseDuilibApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMFCUseDuilibApp 构造

CMFCUseDuilibApp::CMFCUseDuilibApp()
{
	
}


// 唯一的一个 CMFCUseDuilibApp 对象

CMFCUseDuilibApp theApp;

BOOL CMFCUseDuilibApp::InitInstance()
{
	//如果要直接使用duilib而跳过MFC的对话框 修改这里

	/*************
		CString szCurPath = CPaintManagerUI::GetCurrentPath();
		int n = szCurPath.GetLength(), nPos;
		nPos = szCurPath.ReverseFind('\\');
		szCurPath = szCurPath.Left(nPos);
		szCurPath += "\\Skin\\";
		CDuiString szResourePath;
		szResourePath.Format(_T("%s"), szCurPath);
		CPaintManagerUI::SetInstance(AfxGetInstanceHandle());
		CPaintManagerUI::SetResourcePath(szResourePath);
		CMainWnd *pMainWnd = new CMainWnd(_T("MainWnd.xml"));
		pMainWnd->Create(NULL, _T("Duilib"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
		pMainWnd->CenterWindow();
		pMainWnd->ShowModal();
		delete pMainWnd;
	**************/

	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	CWinApp::InitInstance();
	AfxEnableControlContainer();
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CMFCUseDuilibDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	return FALSE;
}
