
// DataStructVisual_GraphView.h : CDataStructVisual_GraphView ��Ľӿ�
//

#pragma once


class CDataStructVisual_GraphView : public CView
{
protected: // �������л�����
	CDataStructVisual_GraphView();
	DECLARE_DYNCREATE(CDataStructVisual_GraphView)

// ����
public:
	CDataStructVisual_GraphDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CDataStructVisual_GraphView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // DataStructVisual_GraphView.cpp �еĵ��԰汾
inline CDataStructVisual_GraphDoc* CDataStructVisual_GraphView::GetDocument() const
   { return reinterpret_cast<CDataStructVisual_GraphDoc*>(m_pDocument); }
#endif

