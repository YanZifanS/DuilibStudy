// MFCUseDuilibDlg.h : ͷ�ļ�
//

#pragma once


// CMFCUseDuilibDlg �Ի���
class CMFCUseDuilibDlg : public CDialog
{
// ����
public:
	CMFCUseDuilibDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCUSEDUILIB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDuilib();
	afx_msg void OnBnClickedButtonDuilib();
};
