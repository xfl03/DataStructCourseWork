#pragma once
#include "afx.h"
#include <afxtempl.h>
#include <afxwin.h>
#include <afxext.h>
#include "GraphEdgeNode.h"
#define RADIUS 15 // ���嶥��뾶
class CGraphVertexNode :
	public CObject
{
public:
	CGraphVertexNode();
	~CGraphVertexNode();
	CPoint m_Point;// ͼ��������λ��
	COLORREF m_Color;// ͼ������ɫ
	CString m_StrName; // ͼ�������
	BOOL m_bVisit;// ͼ������ʱ�־
	int m_Index;// ������ͼ�еı��
	int m_Value;// ����ֵ
	CGraphEdgeNode* m_pFirstEdge;// ����ͼָ�������е�һ���߽��ָ��
	CTypedPtrList <CObList, CGraphEdgeNode*> m_EdgeOut;// ������߱�
	CTypedPtrList <CObList, CGraphEdgeNode*> m_EdgeIn;// ������߱�
	void DrawVertex(CDC *pDC, int vShowMode);// ���Ƶ�ǰ����
};