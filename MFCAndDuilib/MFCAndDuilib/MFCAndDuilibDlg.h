
// MFCAndDuilibDlg.h : ͷ�ļ�
//

#pragma once


// CMFCAndDuilibDlg �Ի���
class CMFCAndDuilibDlg : public CDialog
{
// ����
public:
	CMFCAndDuilibDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCANDDUILIB_DIALOG };

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
};
