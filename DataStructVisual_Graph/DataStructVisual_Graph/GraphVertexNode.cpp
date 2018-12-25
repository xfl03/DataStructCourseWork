#include "stdafx.h"
#include "GraphVertexNode.h"



CGraphVertexNode::CGraphVertexNode()
{
	m_pFirstEdge = NULL;
	m_Color = RGB(0, 0, 0);
	m_bVisit = FALSE;
}
CGraphVertexNode::~CGraphVertexNode()
{
}
void CGraphVertexNode::DrawVertex(CDC *pDC, int vShowMode)
{
	CPen tNewPen, *tPOldPen;
	CRect tVertexRect;
	if (m_bVisit)
	{
		m_Color = RGB(255, 0, 0);
	}
	tNewPen.CreatePen(PS_DASHDOTDOT, 2, m_Color);
	tPOldPen = pDC->SelectObject(&tNewPen);
	if (vShowMode)
	{
		m_StrName = (char)(m_Index + 65);
		tVertexRect.SetRect(m_Point.x - RADIUS, m_Point.y - RADIUS,
			m_Point.x + RADIUS, m_Point.y + RADIUS);
		pDC->Ellipse(tVertexRect);
		pDC->TextOut(m_Point.x - RADIUS + 10,
			m_Point.y - RADIUS + 6, m_StrName);
	}
	else
	{
		tVertexRect.SetRect(m_Point.x - 3, m_Point.y - 3,
			m_Point.x + 3, m_Point.y + 3);
		pDC->Ellipse(tVertexRect);
	}
	pDC->SelectObject(tPOldPen);
}