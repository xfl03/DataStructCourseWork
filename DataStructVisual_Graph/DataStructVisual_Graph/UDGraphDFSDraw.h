#pragma once
#include "UDGraph.h"
#include "GraphVertexNode.h"


// CUDGraphDFSDraw 窗体视图

class CUDGraphDFSDraw : public CFormView
{
	DECLARE_DYNCREATE(CUDGraphDFSDraw)

protected:
	CUDGraphDFSDraw();           // 动态创建所使用的受保护的构造函数
	virtual ~CUDGraphDFSDraw();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UDGRAPHDFS_DRAW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_Flag;
	HANDLE m_hThreadUDGraphDFS;
	HANDLE m_hEventUDGraphDFS;
	BOOL m_bStartFlag;
	BOOL m_bEdgeSource;
	CString m_StartPointDFS;
	int m_nGridLeft;
	int m_nGridTop;
	int m_nGridWidth;
	int m_nGridHeight;
	int m_nGridRow;
	int m_nGridColumn;
	int m_nShowMode;
	CPoint m_EdgeSrcVex;
	CPoint m_EdgeCurPos;
	CPoint m_EdgeMovePos;
	CGraphVertexNode* m_pEndNode;
	CGraphVertexNode* m_pBeginNode;

	CUDGraph m_UDGraphDFS;

	void ClearUDGraph();
	virtual void OnInitialUpdate();
	static DWORD  UDGraphDFSProc(LPVOID lpParameter);
	void DrawUDGraphDFS(CRect vWinRect, CDC *vPDC);
	void DrawMouseMoveEdge(CDC *vPDC);
	void DrawGraphGrid(CDC *vPDC);
	void DrawDFSTraverse(CDC * vPDC, HANDLE vHEvent);
	afx_msg void OnPaint();
	int GetUGraphVertexNum();
	int GetUGraphEdgeNum();
	void OnUGVertexInfor();
	void OnUGEdgeInfor();
	void GetPointOffset(CPoint& vPoint, CPoint vOrignPoint);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	void ExecuteDFS(CString vStart);
	void DFSStep();
};


