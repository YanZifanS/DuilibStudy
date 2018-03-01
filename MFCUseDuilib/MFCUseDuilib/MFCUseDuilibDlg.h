// MFCUseDuilibDlg.h : 头文件
//

#pragma once


// CMFCUseDuilibDlg 对话框
class CMFCUseDuilibDlg : public CDialog
{
// 构造
public:
	CMFCUseDuilibDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCUSEDUILIB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDuilib();
	afx_msg void OnBnClickedButtonDuilib();
};
