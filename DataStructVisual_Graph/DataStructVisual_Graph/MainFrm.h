
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include "afxext.h"

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnGraphOpen();
	afx_msg void OnUpdateGraphOpen(CCmdUI *pCmdUI);
	afx_msg void OnGraphSave();
	afx_msg void OnUpdateGraphSave(CCmdUI *pCmdUI);
	afx_msg void OnGraphClear();
	afx_msg void OnUpdateGraphClear(CCmdUI *pCmdUI);
	afx_msg void OnGraphVertexAdd();
	afx_msg void OnUpdateGraphVertexAdd(CCmdUI *pCmdUI);
	afx_msg void OnGraphVertexDelete();
	afx_msg void OnUpdateGraphVertexDelete(CCmdUI *pCmdUI);
	afx_msg void OnGraphVertexInfo();
	afx_msg void OnUpdateGraphVertexInfo(CCmdUI *pCmdUI);
	afx_msg void OnGraphEdgeAdd();
	afx_msg void OnUpdateGraphEdgeAdd(CCmdUI *pCmdUI);
	afx_msg void OnGraphEdgeDelete();
	afx_msg void OnUpdateGraphEdgeDelete(CCmdUI *pCmdUI);
	afx_msg void OnGraphEdgeInfo();
	afx_msg void OnUpdateGraphEdgeInfo(CCmdUI *pCmdUI);
	afx_msg void OnGraphEdgeSetweight();
	afx_msg void OnUpdateGraphEdgeSetweight(CCmdUI *pCmdUI);
	int m_FunType;
	CSplitterWnd m_wndSplitter;
	bool m_bSplitterWndCreated;
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


