#pragma once


// CDuiDlgTwo �Ի���

class CDuiDlgTwo : public CDialog
{
	DECLARE_DYNAMIC(CDuiDlgTwo)

public:
	CDuiDlgTwo(CWnd* pParent = NULL);   
	virtual ~CDuiDlgTwo();
	enum { IDD = IDD_DIALOG_DUILIB };

public:
	
	void GetNum(int nNum);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

private:
	int m_nNum;
};
