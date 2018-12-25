#pragma once
#include "afx.h"
class CGraphVertexNode;
class CGraphEdgeNode :
	public CObject
{
public:
	CGraphEdgeNode();
	~CGraphEdgeNode();
	int m_Weight;// �ߵ�Ȩֵ
	COLORREF m_Color;// �ߵ���ɫ
	CGraphVertexNode* m_pAdjVertex;// �ڽӶ���ָ��
	CGraphEdgeNode* m_pNextEdge;// ��һ���߽��
	BOOL m_bVisit;// �Ƿ����
				  // �ñ���������������ָ��
	CGraphVertexNode* m_pFromVertex, *m_pToVertex;
	// ����ֱ�ָ�����һ����
	CGraphEdgeNode* m_pFromNextEdge, *m_pToNextEdge;
	void DrawEdge(CDC *tPDC, int vShowMode);// ���Ʊ߽��
};

