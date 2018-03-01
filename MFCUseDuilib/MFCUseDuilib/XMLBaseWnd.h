#pragma once
#include "../Include/Duilib/UIlib.h"
using namespace DuiLib;
//һ��Ҫ���������ռ�����
#include "MfcWndUI.h"


#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "..\\Include\\Duilib\\Lib\\DuiLib_ud.lib")
#   else
#       pragma comment(lib, "..\\Include\\Duilib\\Lib\\DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "..\\Include\\Duilib\\Lib\\DuiLib_u.lib")
#   else
#      pragma comment(lib, "..\\Include\\Duilib\\Lib\\DuiLib.lib")
#   endif
#endif

class CXMLBaseWnd : public WindowImplBase
{
public:
	CXMLBaseWnd(void);
	explicit CXMLBaseWnd(LPCTSTR pszXMLPath) : m_strXMLPath(pszXMLPath)
	{
		
	}
	virtual ~CXMLBaseWnd(void);
	virtual LPCTSTR GetWindowClassName() const
	{
		return _T("XMLWnd");
	}

	virtual CDuiString GetSkinFile()
	{
		return m_strXMLPath;
	}

	virtual CDuiString GetSkinFolder()
	{
		return _T("skin");
	}

	void ShowSysBtn(CDuiString szName);

	//����˺���  ==> ȥxml���涨��Dialog �Ϳ�����duilib�ռ�һ��ȥʹ��
	virtual CControlUI* CreateControl(LPCTSTR pstrClassName)
	{
		if (_tcsicmp(pstrClassName, _T("Dialog")) == 0)
		{
			CMfcWndUI *pUI = new CMfcWndUI();
			/*CDlg *pVideoDlg = new CDlg(CWnd::FromHandle(GetHWND()));
			pVideoDlg->Create(CDlg::IDD, CWnd::FromHandle(GetHWND()));
			pUI->Attach(pVideoDlg->GetSafeHwnd());*/
			return  pUI;
		}
		return NULL;
	}



protected:
	CDuiString m_strXMLPath;
};
