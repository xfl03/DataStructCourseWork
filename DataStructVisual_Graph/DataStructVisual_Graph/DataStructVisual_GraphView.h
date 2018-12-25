
// DataStructVisual_GraphView.h : CDataStructVisual_GraphView 类的接口
//

#pragma once


class CDataStructVisual_GraphView : public CView
{
protected: // 仅从序列化创建
	CDataStructVisual_GraphView();
	DECLARE_DYNCREATE(CDataStructVisual_GraphView)

// 特性
public:
	CDataStructVisual_GraphDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CDataStructVisual_GraphView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // DataStructVisual_GraphView.cpp 中的调试版本
inline CDataStructVisual_GraphDoc* CDataStructVisual_GraphView::GetDocument() const
   { return reinterpret_cast<CDataStructVisual_GraphDoc*>(m_pDocument); }
#endif

