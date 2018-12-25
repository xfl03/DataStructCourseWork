#include "stdafx.h"
#include "BiTreeNode.h"


CBiTreeNode::CBiTreeNode()
{
}


CBiTreeNode::~CBiTreeNode()
{
}
bool CBiTreeNode::DrawBiTreeNode(CDC* pDC)
{
	CPen tDrawPen, *tPOldPen;
	CRect tNodeRect;
	CString tStr;
	tStr.Format(_T("%d"), m_Value);
	tDrawPen.CreatePen(PS_SOLID, 1, m_Color);
	tPOldPen = pDC->SelectObject(&tDrawPen);
	tNodeRect.SetRect(m_Point.x - 20, m_Point.y - 20, m_Point.x + 20,
		m_Point.y + 20);
	if (!pDC->Ellipse(tNodeRect)) return false;
	if (!pDC->TextOut(m_Point.x - 10, m_Point.y - 10, tStr)) return false;
	pDC->SelectObject(tPOldPen);
	return true;
}
void CBiTreeNode::DrawSearchBITreeNode(int vBiTreeKey, CDC* pDC)
{
	CPen tPen;
	CRect tNodeRect;
	TEXTMETRIC tTxt;
	CString tStr;
	tPen.CreatePen(1, 2, RGB(128, 64, 0));//在这里改变颜色
	CPen* tPOldPen = pDC->SelectObject(&tPen);
	tStr.Format(_T("%d"), vBiTreeKey);
	pDC->GetTextMetrics(&tTxt);
	tNodeRect.SetRect(m_Point.x - 20, m_Point.y - 20, m_Point.x + 20,
		m_Point.y + 20);
	pDC->Ellipse(tNodeRect);
	pDC->TextOut(m_Point.x - 10, m_Point.y - 10, tStr);
	pDC->SelectObject(tPOldPen);
}