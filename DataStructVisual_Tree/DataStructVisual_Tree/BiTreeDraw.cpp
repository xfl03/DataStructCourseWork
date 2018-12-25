// BiTreeDraw.cpp : 实现文件
//

#include "stdafx.h"
#include "DataStructVisual_Tree.h"
#include "BiTreeDraw.h"


// CBiTreeDraw

IMPLEMENT_DYNCREATE(CBiTreeDraw, CFormView)

CBiTreeDraw::CBiTreeDraw()
	: CFormView(IDD_BITREE_DRAW)
{

}

CBiTreeDraw::~CBiTreeDraw()
{
}

void CBiTreeDraw::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBiTreeDraw, CFormView)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CBiTreeDraw 诊断

#ifdef _DEBUG
void CBiTreeDraw::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CBiTreeDraw::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBiTreeDraw 消息处理程序
CDataStructVisual_TreeDoc* CBiTreeDraw::GetDocument()
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS
	(CDataStructVisual_TreeDoc)));
	return (CDataStructVisual_TreeDoc*)m_pDocument;
}

void CBiTreeDraw::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	m_pDoc = GetDocument();
	m_hEventTree = ::CreateEvent(NULL, true, true, _T("BiTree"));
	m_Flag = 0;
}


DWORD CBiTreeDraw::BiTreeProc(LPVOID lpParameter)
{
	CBiTreeDraw *tPBiTreeDraw = (CBiTreeDraw*)lpParameter;
	CRect tWinSize;
	CPoint tCenterPoint;
	tPBiTreeDraw->GetClientRect(tWinSize);
	CDC *tPDC = tPBiTreeDraw->GetDC();
	if (tPBiTreeDraw->m_Flag == -1)
	{
		tPBiTreeDraw->DrawBiTree(tWinSize, tPDC);
	}
	if (tPBiTreeDraw->m_Flag == 0) {
		tPBiTreeDraw->m_Flag = -1;
		tPBiTreeDraw->DrawBiTree(tWinSize, tPDC);
	}
	if (tPBiTreeDraw->m_Flag == 1)
	{
		tPBiTreeDraw->m_Flag = -1;
		tPBiTreeDraw->DrawBiTree(tWinSize, tPDC);
		tPBiTreeDraw->DrawBiTreeSearchNode(tPDC);
	}
	return 1;
}


void CBiTreeDraw::DrawBiTree(CRect vWinRect, CDC* pDC)
{
	m_pDoc->m_BiTree.DrawBiTree(vWinRect, pDC);
}


void CBiTreeDraw::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CFormView::OnPaint()
	CBiTreeDraw *tPBiTreeDraw = this;
	m_hThreadTree = CreateThread(
		NULL,
		0, (LPTHREAD_START_ROUTINE)BiTreeProc,
		(LPVOID)tPBiTreeDraw, 0, NULL
	);
	CloseHandle(m_hThreadTree);
}


void CBiTreeDraw::InsertBiTreeNode(int vBTNValue)
{
	CDataStructVisual_TreeDoc* pDoc = GetDocument();
	CPoint tCenterPoint;
	CRect tWinSize;
	this->GetClientRect(tWinSize);
	pDoc->m_BiTree.InsertBiTreeNode(tWinSize, vBTNValue);
	m_Flag = 0;
	this->Invalidate();
}


void CBiTreeDraw::DeleteBiTreeNode(int vBTNValue)
{
	CDataStructVisual_TreeDoc* pDoc = GetDocument();
	CPoint tCenterPoint;
	CRect tWinSize;
	this->GetClientRect(tWinSize);
	pDoc->m_BiTree.DeleteBiTreeNode(tWinSize, vBTNValue);
	m_Flag = 0;
	this->Invalidate();
}


void CBiTreeDraw::SearchBiTreeNode(int vBTNValue)
{
	CDataStructVisual_TreeDoc* pDoc = GetDocument();
	pDoc->m_BiTree.SetBiTreeSearchKey(vBTNValue);
	m_Flag = 1;
	this->Invalidate();
}


void CBiTreeDraw::DrawBiTreeSearchNode(CDC* pDC)
{
	m_pDoc->m_BiTree.DrawSearchBiTreeNode(pDC);
}
