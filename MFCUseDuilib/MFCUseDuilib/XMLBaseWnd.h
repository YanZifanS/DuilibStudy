#pragma once
#include "../Include/Duilib/UIlib.h"
using namespace DuiLib;
//一定要放着命名空间下面
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

	//加入此函数  ==> 去xml里面定义Dialog 就可以像duilib空间一样去使用
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
