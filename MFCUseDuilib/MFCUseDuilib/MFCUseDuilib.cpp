// MFCUseDuilib.cpp : ����Ӧ�ó��������Ϊ��
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


// CMFCUseDuilibApp ����

CMFCUseDuilibApp::CMFCUseDuilibApp()
{
	
}


// Ψһ��һ�� CMFCUseDuilibApp ����

CMFCUseDuilibApp theApp;

BOOL CMFCUseDuilibApp::InitInstance()
{
	//���Ҫֱ��ʹ��duilib������MFC�ĶԻ��� �޸�����

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
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CMFCUseDuilibDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	return FALSE;
}
