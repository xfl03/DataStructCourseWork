
// DataStructVisual_GraphView.cpp : CDataStructVisual_GraphView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CDataStructVisual_GraphView ����/����

CDataStructVisual_GraphView::CDataStructVisual_GraphView()
{
	// TODO: �ڴ˴���ӹ������

}

CDataStructVisual_GraphView::~CDataStructVisual_GraphView()
{
}

BOOL CDataStructVisual_GraphView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDataStructVisual_GraphView ����

void CDataStructVisual_GraphView::OnDraw(CDC* /*pDC*/)
{
	CDataStructVisual_GraphDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDataStructVisual_GraphView ���

#ifdef _DEBUG
void CDataStructVisual_GraphView::AssertValid() const
{
	CView::AssertValid();
}

void CDataStructVisual_GraphView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDataStructVisual_GraphDoc* CDataStructVisual_GraphView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDataStructVisual_GraphDoc)));
	return (CDataStructVisual_GraphDoc*)m_pDocument;
}
#endif //_DEBUG


// CDataStructVisual_GraphView ��Ϣ�������
