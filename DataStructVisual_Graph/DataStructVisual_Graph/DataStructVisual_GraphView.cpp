
// DataStructVisual_GraphView.cpp : CDataStructVisual_GraphView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DataStructVisual_Graph.h"
#endif

#include "DataStructVisual_GraphDoc.h"
#include "DataStructVisual_GraphView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDataStructVisual_GraphView

IMPLEMENT_DYNCREATE(CDataStructVisual_GraphView, CView)

BEGIN_MESSAGE_MAP(CDataStructVisual_GraphView, CView)
END_MESSAGE_MAP()

// CDataStructVisual_GraphView 构造/析构

CDataStructVisual_GraphView::CDataStructVisual_GraphView()
{
	// TODO: 在此处添加构造代码

}

CDataStructVisual_GraphView::~CDataStructVisual_GraphView()
{
}

BOOL CDataStructVisual_GraphView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDataStructVisual_GraphView 绘制

void CDataStructVisual_GraphView::OnDraw(CDC* /*pDC*/)
{
	CDataStructVisual_GraphDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDataStructVisual_GraphView 诊断

#ifdef _DEBUG
void CDataStructVisual_GraphView::AssertValid() const
{
	CView::AssertValid();
}

void CDataStructVisual_GraphView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDataStructVisual_GraphDoc* CDataStructVisual_GraphView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDataStructVisual_GraphDoc)));
	return (CDataStructVisual_GraphDoc*)m_pDocument;
}
#endif //_DEBUG


// CDataStructVisual_GraphView 消息处理程序
