
// MFCAndDuilib.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCAndDuilibApp:
// �йش����ʵ�֣������ MFCAndDuilib.cpp
//

class CMFCAndDuilibApp : public CWinAppEx
{
public:
	CMFCAndDuilibApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCAndDuilibApp theApp;