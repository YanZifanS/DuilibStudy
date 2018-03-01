#include "stdafx.h"
#include "MFCUseDuilib.h"
#include "MFCUseDuilibDlg.h"
#include "DuilibDlg.h"
#include "DuiDlgTwo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMFCUseDuilibDlg::CMFCUseDuilibDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCUseDuilibDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCUseDuilibDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCUseDuilibDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(ID_DUILIB, &CMFCUseDuilibDlg::OnBnClickedDuilib)
	ON_BN_CLICKED(IDC_BUTTON_DUILIB, &CMFCUseDuilibDlg::OnBnClickedButtonDuilib)
END_MESSAGE_MAP()

BOOL CMFCUseDuilibDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	return TRUE;  
}

void CMFCUseDuilibDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CMFCUseDuilibDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCUseDuilibDlg::OnBnClickedDuilib()
{
	CDuilibDlg *pDlg = new CDuilibDlg;
	pDlg->Create(IDD_DIALOG1, NULL);
	pDlg->ShowWindow(SW_SHOWNORMAL);
	//delete pDlg;
}

void CMFCUseDuilibDlg::OnBnClickedButtonDuilib()
{
	int n = 1;
	CDuiDlgTwo *pDlg = new CDuiDlgTwo;
	pDlg->GetNum(n);
	pDlg->Create(IDD_DIALOG_DUILIB, NULL);
	pDlg->ShowWindow(SW_SHOWNORMAL);
	//delete pDlg;
}
