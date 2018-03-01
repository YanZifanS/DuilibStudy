#include "stdafx.h"
#include "ListEx.h"
#include "ListExMainWnd.h"

CDuiString sSortRow = "other";

BOOL IsNumber(LPCTSTR  pszText,int length) 
{ 
	if (pszText == NULL || length < 0)
		return FALSE;

	for(int i = 0;i < length;i++) 
		if(! isdigit(pszText[i])) 
			return  FALSE; 
	return TRUE; 
}

int CALLBACK SortCompare(LPCTSTR data1,LPCTSTR data2) 
{ 
	CDuiString strItem1 = (LPCTSTR)data1;
	CDuiString strItem2 = (LPCTSTR)data2;

	//�ж�Ϊ����
	if (IsNumber(strItem1, strItem1.GetLength()))
	{
		int number1 = _tcstol(strItem1,NULL,10);
		int number2 = _tcstol(strItem2,NULL,10);

		if (number1 == number2)
			return 0;
		else if (number1 > number2)
			return 1;
		else
			return -1;
	}
	//��s1<s2ʱ������ֵ<0 ������s1=s2ʱ������ֵ=0 ������s1>s2ʱ������ֵ>0 
	return _tcscmp(strItem2,strItem1); 
}

DUI_BEGIN_MESSAGE_MAP(CListExMainWnd, WindowImplBase)
	DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
	DUI_ON_MSGTYPE(DUI_MSGTYPE_HEADERCLICK, OnHeaderClick)
DUI_END_MESSAGE_MAP()

CListExMainWnd::CListExMainWnd()
{
}

CListExMainWnd::~CListExMainWnd()
{
}

void CListExMainWnd::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
	delete this;
}

CDuiString CListExMainWnd::GetSkinFolder()
{
	return _T("skin\\");
}

CDuiString CListExMainWnd::GetSkinFile()
{
	return _T("main.xml");
}

UILIB_RESOURCETYPE CListExMainWnd::GetResourceType() const
{
	return UILIB_FILE;
}

LPCTSTR CListExMainWnd::GetWindowClassName(void) const
{
	return _T("ListExWnd");
}

UINT CListExMainWnd::GetClassStyle() const
{
	return UI_CLASSSTYLE_DIALOG;
}

void CListExMainWnd::Notify(TNotifyUI &msg)
{
	if (_tcsicmp(msg.sType, _T("itemactivate")) == 0 )
	{
		::MessageBox(m_hWnd, "aaa", "", 0);
	}
	return WindowImplBase::Notify(msg);
}

void CListExMainWnd::OnClick( TNotifyUI &msg )
{
	if( msg.pSender == m_pCloseBtn) 
	{ 
		PostQuitMessage(0); // ��Ϊactivex��ԭ��ʹ��close���ܻ���ִ���
		return; 
	}
	else if(msg.pSender == m_pMinBtn) 
	{ 
		SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0); 
		return; 
	}
	else if (msg.pSender->GetName() == "phonenbr")
	{
		::MessageBox(NULL, "aaa", "", 0);
	}
	else if (msg.pSender->GetName() == "phoneclass")
	{
		::MessageBox(NULL, "bbbb", "", 0);
	}
	else if (msg.pSender->GetName() == "additem")
	{
		CDialogBuilder builder;
		CListContainerElementUI* pLine = (CListContainerElementUI*)(builder.Create(_T("sigle_list_item_column.xml"),(UINT)0));
		if( pLine != NULL ) 
		{
			CListUIEx *pList = static_cast<CListUIEx*>(m_PaintManager.FindControl(_T("listex")));
			pList->InsertItem(pList->GetCount(), 60, pLine);
		}
	}
	else if (msg.pSender->GetName() == "additembycode")
	{
		CListUIEx *pList = static_cast<CListUIEx*>(m_PaintManager.FindControl(_T("listex")));
		int nIndex = pList->GetCount();
		pList->InsertItem(nIndex);

		CEditUI *pControl = new CEditUI; 
		pControl->SetText("");
		pControl->SetName("edit");
		pControl->SetBorderColor(RGB(255, 0, 0));
		pControl->SetAttribute("bordersize", "1");
		pControl->SetAttribute("bordercolor", "#FF4775CC");
		pList->SetItemData(nIndex, 0, pControl);

		CButtonUI *pBtnUI = new CButtonUI;
		pBtnUI->SetText("���");
		pBtnUI->SetFixedWidth(60);
		pBtnUI->SetAttribute(_T("pushedimage"), _T("button_down.bmp"));
		pBtnUI->SetAttribute(_T("hotimage"), _T("button_over.bmp"));
		pBtnUI->SetAttribute(_T("normalimage"), _T("button_nor.bmp"));		
		pList->SetItemData(nIndex, 1, pBtnUI);

		pList->SetItemData(nIndex, 2, "����һ�ж�̬��ӵ�����", "testid");
		if (pList->GetHeader()->GetCount() > 3)
		{
			pList->SetItemData(nIndex, 3, "����������", "testid1");
		}
		
	}
	else if (msg.pSender->GetName() == "addcolumn")
	{
		CListUIEx *pList = static_cast<CListUIEx*>(m_PaintManager.FindControl(_T("listex")));
		
		//pList->InsertColumn(3, "������   ", DT_RIGHT, 150);

		CListHeaderItemUI *pHeaderItem = new CListHeaderItemUI;
		pHeaderItem->SetTextStyle(DT_RIGHT|DT_VCENTER|DT_SINGLELINE);
		pHeaderItem->SetText("������   ");
		pHeaderItem->SetAttribute(_T("sepimage"), _T("Headerctrl_Sperator.bmp"));
		pHeaderItem->SetAttribute(_T("sepwidth"), _T("1"));
		pHeaderItem->SetAttribute(_T("pushedimage"), _T("headerctrl_down.bmp"));
		pHeaderItem->SetAttribute(_T("hotimage"), _T("headerctrl_hot.bmp"));
		pHeaderItem->SetAttribute(_T("normalimage"), _T("headerctrl_normal.bmp"));
		pHeaderItem->SetFixedWidth(150);
		pList->InsertColumn(3, pHeaderItem);

		CCheckBoxUI *pBtnUI = new CCheckBoxUI;
		pBtnUI->SetText("ѡ��");
		pBtnUI->SetAttribute(_T("selectedimage"), _T("file='checkbox_p.png' dest='0,2,15,17'"));
		pBtnUI->SetAttribute(_T("normalimage"), _T("file='checkbox_h.png' dest='0,2,15,17'"));
		pBtnUI->SetAttribute(_T("textpadding"), _T("20,3,0,0"));
		pBtnUI->SetAttribute(_T("align"), _T("right"));
		pBtnUI->SetFloat(true);
		pBtnUI->SetAttribute("pos", "20,3, 65, 20");

		pList->SetHeaderItemData(3, pBtnUI);
	}
	
}

void CListExMainWnd::OnHeaderClick(TNotifyUI& msg)
{
	CDuiString sName = msg.pSender->GetName();
	CListUIEx *pList = static_cast<CListUIEx*>(m_PaintManager.FindControl(_T("listex")));
	
	sSortRow = sName;
	//pList->SortItems(ListSortItems, NULL);
}


void CListExMainWnd::InitWindow()
{
	m_pCloseBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("closebtn")));
	m_pMinBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("minbtn")));

	CListUIEx *pList = static_cast<CListUIEx*>(m_PaintManager.FindControl(_T("listex")));
	CDialogBuilder builder;
	CListContainerElementUI* pLine = (CListContainerElementUI*)(builder.Create(_T("sigle_list_item_column.xml"),(UINT)0, this));
	if( pLine != NULL ) 
	{
		pList->InsertItem(0, 60, pLine);
	}
	RECT rect;
	GetWindowRect(m_hWnd, &rect);
	
	HRGN hRgn = CreateRectRgn(rect.left, rect.top, rect.right,rect.bottom);
	EnableBlurBehind(hRgn);
	DeleteObject(hRgn);
}

HRESULT CListExMainWnd::EnableBlurBehind(HRGN hRgn )
{
// 	DWM_BLURBEHIND bb = {0};
// 	bb.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION;
// 	bb.fEnable = true;
// 	bb.hRgnBlur = hRgn;
// 
// 	return DwmEnableBlurBehindWindow(m_hWnd, &bb);
	return 0;
}

int CALLBACK CListExMainWnd::ListSortItems(UINT_PTR data1, UINT_PTR data2, UINT_PTR userDef)
{
// 	CDuiString szSource;
// 	CDuiString szTemp;
// 	CLabelUI *pLabelUI ,*pNextLabelUI;
// 
// 	CListContainerElementUIEx *pListContainerElementUI = (CListContainerElementUIEx*)data1;
// 	if (pListContainerElementUI == NULL)
// 		return TRUE;
// 
// 	CListContainerElementUIEx *pNextListContainerElementUI = (CListContainerElementUIEx*)data2;
// 	if (pNextListContainerElementUI == NULL)
// 		return TRUE;
// 
// 	pLabelUI = (CLabelUI *)pListContainerElementUI->FindSubControl(sSortRow);
// 	pNextLabelUI = (CLabelUI *)pNextListContainerElementUI->FindSubControl(sSortRow);
// 	
// 	szSource = pLabelUI->GetText();
// 	szTemp = pNextLabelUI->GetText();
// 	
// 	return SortCompare(szSource,szTemp);
	return 0;
}