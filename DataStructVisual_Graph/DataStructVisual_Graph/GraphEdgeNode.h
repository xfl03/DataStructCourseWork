#pragma once
#include "afx.h"
class CGraphVertexNode;
class CGraphEdgeNode :
	public CObject
{
public:
	CGraphEdgeNode();
	~CGraphEdgeNode();
	int m_Weight;// 边的权值
	COLORREF m_Color;// 边的颜色
	CGraphVertexNode* m_pAdjVertex;// 邻接顶点指针
	CGraphEdgeNode* m_pNextEdge;// 下一条边结点
	BOOL m_bVisit;// 是否访问
				  // 该边依附的两个顶点指针
	CGraphVertexNode* m_pFromVertex, *m_pToVertex;
	// 顶点分别指向的下一条边
	CGraphEdgeNode* m_pFromNextEdge, *m_pToNextEdge;
	void DrawEdge(CDC *tPDC, int vShowMode);// 绘制边结点
};

