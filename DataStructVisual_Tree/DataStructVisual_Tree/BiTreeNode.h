#pragma once
#include "afx.h"
class CBiTreeNode :
	public CObject
{
public:
	CBiTreeNode();
	~CBiTreeNode();
	bool DrawBiTreeNode(CDC* pDC);// ���ƶ��������
	void DrawSearchBITreeNode(int vBiTreeKey, CDC* pDC);// ���� ���ҽ��
public:
	CPoint m_Point;// �������������λ��
	COLORREF m_Color; // �����������ɫ
	CString m_StrName; // �������������
	int m_Value;// ���������ֵ
	BOOL m_Visit;// ����������Ƿ����
	CPoint m_DisplayPoint;// �������µ���ʾλ��
						  // ������������Һ���ָ��͸����ָ��
	CBiTreeNode *m_pLChild, *m_pRChild, *m_pParent;
	int m_Leftwidth;//���������������
	int m_Rightwidth;// ���������������
};