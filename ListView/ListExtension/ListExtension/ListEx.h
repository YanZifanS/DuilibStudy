#ifndef LISTEX_H
#define LISTEX_H

#pragma once

class CListContainerElementUIEx;
class CListUIEx;

class CListUIEx : public CListUI
{
public:
	/**
	 * ���캯��
	 */
	CListUIEx();

	/**
	 * ��������
	 */
	virtual ~CListUIEx();

	/**
	 * ������,�վ�,��0��ʼ
	 * 
	 * @param	nCol					����,��Ҫ��0��ʼ���β���
	 * @param	lpszColumnHeaderStr		ÿһ�б���
	 * @param	uTextStyle				�������ֶ��뷽ʽ
	 * @param	nWidth					�п�
	 * 
	 * @return	����TrueΪ�ɹ�,FalseΪʧ��
	 */
	BOOL InsertColumn(
		int nCol,
		LPCTSTR lpszColumnHeaderStr,
		UINT uTextStyle = DT_LEFT,
		int nWidth = -1
		);
	BOOL InsertColumn( int nCol, CListHeaderItemUI *pHeaderItem );
	/**
	 * ������,�վ�,��0��ʼ
	 * 
	 * @param	nItem					����,��Ҫ��0��ʼ���β���
	 *
	 * @return	�ɹ��򷵻�����,���򷵻�-1
	 */
	int InsertItem(int nItem, int nHeight = 20);
	int InsertItem(int nItem, int nHeight, CListContainerElementUI *pListItem);
	void SetItemData(int nItem, int nColumn, LPCTSTR Text, LPCTSTR Name);
	void SetItemData(int nItem, int nColumn, CControlUI* pControl);
	/**
	 * ����������ȡ�пؼ�
	 * 
	 * @param	iIndex					����,��0���������
	 * 
	 * @return	�ɹ�ʱ�����ӿؼ���ַ,���򷵻�NULL
	 */
	CListContainerElementUI* GetListItem(int iIndex);

	/**
	 * ��ȡ����λ�õĿؼ�
	 * 
	 * @param	iIndex					����,��0���������
	 * @param	iSubIndex					����,��0���������
	 * 
	 * @return	�ɹ�ʱ�����ӿؼ���ַ,���򷵻�NULL
	 */
	CHorizontalLayoutUI* GetListSubItem(int iIndex, int iSubIndex);
	BOOL SetHeaderItemData(int nColumn, CControlUI* pControl);
};
#endif