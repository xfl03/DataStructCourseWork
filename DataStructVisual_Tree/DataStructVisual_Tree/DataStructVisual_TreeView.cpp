
// DataStructVisual_TreeView.cpp : CDataStructVisual_TreeView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DataStructVisual_Tree.h"
#endif

#include "DataStructVisual_TreeDoc.h"
#include "DataStructVisual_TreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDataStructVisual_TreeView

IMPLEMENT_DYNCREATE(CDataStructVisual_TreeView, CView)

BEGIN_MESSAGE_MAP(CDataStructVisual_TreeView, CView)
END_MESSAGE_MAP()

// CDataStructVisual_TreeView 构造/析构

CDataStructVisual_TreeView::CDataStructVisual_TreeView()
{
	// TODO: 在此处添加构造代码

}

CDataStructVisual_TreeView::~CDataStructVisual_TreeView()
{
}

BOOL CDataStructVisual_TreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDataStructVisual_TreeView 绘制

void CDataStructVisual_TreeView::OnDraw(CDC* /*pDC*/)
{
	CDataStructVisual_TreeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDataStructVisual_TreeView 诊断

#ifdef _DEBUG
void CDataStructVisual_TreeView::AssertValid() const
{
	CView::AssertValid();
}

void CDataStructVisual_TreeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDataStructVisual_TreeDoc* CDataStructVisual_TreeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDataStructVisual_TreeDoc)));
	return (CDataStructVisual_TreeDoc*)m_pDocument;
}
#endif //_DEBUG


// CDataStructVisual_TreeView 消息处理程序
