#pragma once


// CDuilibDlg �Ի���

class CDuilibDlg : public CDialog
{
	DECLARE_DYNAMIC(CDuilibDlg)

public:
	CDuilibDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDuilibDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
