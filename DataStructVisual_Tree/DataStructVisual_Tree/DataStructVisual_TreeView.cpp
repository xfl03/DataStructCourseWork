
// DataStructVisual_TreeView.cpp : CDataStructVisual_TreeView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CDataStructVisual_TreeView ����/����

CDataStructVisual_TreeView::CDataStructVisual_TreeView()
{
	// TODO: �ڴ˴���ӹ������

}

CDataStructVisual_TreeView::~CDataStructVisual_TreeView()
{
}

BOOL CDataStructVisual_TreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDataStructVisual_TreeView ����

void CDataStructVisual_TreeView::OnDraw(CDC* /*pDC*/)
{
	CDataStructVisual_TreeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDataStructVisual_TreeView ���

#ifdef _DEBUG
void CDataStructVisual_TreeView::AssertValid() const
{
	CView::AssertValid();
}

void CDataStructVisual_TreeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDataStructVisual_TreeDoc* CDataStructVisual_TreeView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDataStructVisual_TreeDoc)));
	return (CDataStructVisual_TreeDoc*)m_pDocument;
}
#endif //_DEBUG


// CDataStructVisual_TreeView ��Ϣ�������
