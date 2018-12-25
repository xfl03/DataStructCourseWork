#include "stdafx.h"
#include "GraphEdgeNode.h"
#include "GraphVertexNode.h"
CGraphEdgeNode::CGraphEdgeNode()
{
	m_pAdjVertex = NULL;
	m_pNextEdge = NULL;
}
CGraphEdgeNode::~CGraphEdgeNode()
{
}
void CGraphEdgeNode::DrawEdge(CDC *pDC, int vShowMode)
{
	CPen *tPOldPen, tCurBPen;
	CString tStr;
	tCurBPen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	tPOldPen = pDC->SelectObject(&tCurBPen);
	CPoint tPointHead, tpointTail;
	tPointHead = m_pFromVertex->m_Point;
	pDC->MoveTo(tPointHead);
	tpointTail = m_pToVertex->m_Point;
	pDC->LineTo(tpointTail);
	if (vShowMode)
	{
		tStr.Format(_T("%d"), m_Weight);
		pDC->TextOut((tPointHead.x + tpointTail.x) / 2,
			(tPointHead.y + tpointTail.y) / 2, tStr);
	}
}