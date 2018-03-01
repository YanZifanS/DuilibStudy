#include "stdafx.h"
#include "MFCUseDuilib.h"
#include "DuilibDlg.h"
#include "MainWnd.h"

IMPLEMENT_DYNAMIC(CDuilibDlg, CDialog)

CDuilibDlg::CDuilibDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDuilibDlg::IDD, pParent)
{
}

CDuilibDlg::~CDuilibDlg()
{
}


void CDuilibDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDuilibDlg, CDialog)
END_MESSAGE_MAP()

BOOL CDuilibDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CPaintManagerUI::SetInstance(AfxGetInstanceHandle());
	CDuiString szString = CPaintManagerUI::GetInstancePath();
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("Skin"));
	CMainWnd *pMainWnd = new CMainWnd("MainWnd.xml", this->m_hWnd);
	pMainWnd->Create(*this, _T("Duilib"), UI_WNDSTYLE_CHILD, 0, 0, 0, 0, 0);
	pMainWnd->ShowWindow(true);
	return TRUE;  
}
