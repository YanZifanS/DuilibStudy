#pragma once
#include "XMLBaseWnd.h"

class CMainWnd :
	public CXMLBaseWnd
{
public:
	explicit CMainWnd(LPCTSTR pszXMLPath, HWND hWnd);
	~CMainWnd(void);

protected:
	virtual void InitWindow();
	virtual LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual void Notify(TNotifyUI& msg);

protected:
	virtual void OnClick(TNotifyUI& msg);
	virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

private:
	CWndShadow m_WndShadow;
	int m_nCount;
	HWND m_hWnd;
};
