
// DataStructVisual_TreeView.h : CDataStructVisual_TreeView ��Ľӿ�
//

#pragma once


class CDataStructVisual_TreeView : public CView
{
protected: // �������л�����
	CDataStructVisual_TreeView();
	DECLARE_DYNCREATE(CDataStructVisual_TreeView)

// ����
public:
	CDataStructVisual_TreeDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CDataStructVisual_TreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // DataStructVisual_TreeView.cpp �еĵ��԰汾
inline CDataStructVisual_TreeDoc* CDataStructVisual_TreeView::GetDocument() const
   { return reinterpret_cast<CDataStructVisual_TreeDoc*>(m_pDocument); }
#endif

