#pragma once


// CDuilibDlg 对话框

class CDuilibDlg : public CDialog
{
	DECLARE_DYNAMIC(CDuilibDlg)

public:
	CDuilibDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDuilibDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
