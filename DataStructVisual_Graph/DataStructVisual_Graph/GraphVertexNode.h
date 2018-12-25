#pragma once
#include "afx.h"
#include <afxtempl.h>
#include <afxwin.h>
#include <afxext.h>
#include "GraphEdgeNode.h"
#define RADIUS 15 // 定义顶点半径
class CGraphVertexNode :
	public CObject
{
public:
	CGraphVertexNode();
	~CGraphVertexNode();
	CPoint m_Point;// 图顶点坐标位置
	COLORREF m_Color;// 图顶点颜色
	CString m_StrName; // 图结点名称
	BOOL m_bVisit;// 图顶点访问标志
	int m_Index;// 顶点在图中的编号
	int m_Value;// 顶点值
	CGraphEdgeNode* m_pFirstEdge;// 无向图指向链表中第一个边结点指针
	CTypedPtrList <CObList, CGraphEdgeNode*> m_EdgeOut;// 顶点出边表
	CTypedPtrList <CObList, CGraphEdgeNode*> m_EdgeIn;// 顶点入边表
	void DrawVertex(CDC *pDC, int vShowMode);// 绘制当前顶点
};