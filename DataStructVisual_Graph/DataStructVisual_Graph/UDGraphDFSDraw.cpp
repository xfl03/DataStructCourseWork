// UDGraphDFSDraw.cpp : 实现文件
//

#include "stdafx.h"
#include "DataStructVisual_Graph.h"
#include "UDGraphDFSDraw.h"
#include "MainFrm.h"
#include "GraphSetWeight.h"

// CUDGraphDFSDraw

IMPLEMENT_DYNCREATE(CUDGraphDFSDraw, CFormView)

CUDGraphDFSDraw::CUDGraphDFSDraw()
	: CFormView(IDD_UDGRAPHDFS_DRAW)
	, m_Flag(0)
{

}

CUDGraphDFSDraw::~CUDGraphDFSDraw()
{
}

void CUDGraphDFSDraw::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CUDGraphDFSDraw, CFormView)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CUDGraphDFSDraw 诊断

#ifdef _DEBUG
void CUDGraphDFSDraw::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUDGraphDFSDraw::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUDGraphDFSDraw 消息处理程序


void CUDGraphDFSDraw::ClearUDGraph()
{
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	m_UDGraphDFS.ClearGraph();
	pMainFrame->m_FunType = 1;
	m_Flag = 0;
	this->Invalidate();
}


void CUDGraphDFSDraw::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	m_hEventUDGraphDFS = ::CreateEvent(NULL, true, true,
		_T("UDGraphDFS"));
	m_Flag = 0;
	m_nGridRow = 30;
	m_nGridColumn = 30;
	m_nGridLeft = 20;
	m_nGridTop = 20;
	m_nGridWidth = 0;
	m_nGridHeight = 0;
	m_bStartFlag = TRUE;
	m_bEdgeSource = FALSE;
}


DWORD  CUDGraphDFSDraw::UDGraphDFSProc(LPVOID lpParameter)
{
	CUDGraphDFSDraw *tPUDGraphDFSDraw =
		(CUDGraphDFSDraw*)lpParameter;
	CRect tWinSize;
	CPoint tCenterPoint;
	tPUDGraphDFSDraw->GetClientRect(tWinSize);
	CDC *tPDC = tPUDGraphDFSDraw->GetDC();
	if (tPUDGraphDFSDraw->m_Flag == -1)
	{
		tPUDGraphDFSDraw->DrawUDGraphDFS(tWinSize, tPDC);
	}
	if (tPUDGraphDFSDraw->m_Flag == 0)
	{
		tPUDGraphDFSDraw->m_Flag = -1;
		tPUDGraphDFSDraw->DrawUDGraphDFS(tWinSize, tPDC);
	}
	if (tPUDGraphDFSDraw->m_Flag == 1)
	{
		tPUDGraphDFSDraw->m_Flag = -1;
		tPUDGraphDFSDraw->DrawUDGraphDFS(tWinSize, tPDC);
		tPUDGraphDFSDraw->DrawMouseMoveEdge(tPDC);
	}
	if (tPUDGraphDFSDraw->m_Flag == 2)
	{
		tPUDGraphDFSDraw->m_Flag = -1;
		tPUDGraphDFSDraw->DrawGraphGrid(tPDC);
		tPUDGraphDFSDraw->DrawDFSTraverse(tPDC,
			tPUDGraphDFSDraw->m_hEventUDGraphDFS);
	}
	tPUDGraphDFSDraw->DrawGraphGrid(tPDC);
	return 1;
}


void CUDGraphDFSDraw::DrawUDGraphDFS(CRect vWinRect, CDC *vPDC)
{
	m_UDGraphDFS.DrawUDGraph(vPDC);
}
void CUDGraphDFSDraw::DrawMouseMoveEdge(CDC *vPDC)
{
	CPen tWhitePen(PS_SOLID, 2, RGB(230, 230, 230));
	CPen TGrayPen(PS_SOLID, 2, RGB(255, 0, 0));
	vPDC->SelectObject(&tWhitePen);
	vPDC->MoveTo(m_EdgeSrcVex.x, m_EdgeSrcVex.y);
	vPDC->LineTo(m_EdgeCurPos.x, m_EdgeCurPos.y);
	vPDC->SelectObject(&TGrayPen);
	vPDC->MoveTo(m_EdgeSrcVex.x, m_EdgeSrcVex.y);
	vPDC->LineTo(m_EdgeMovePos.x, m_EdgeMovePos.y);
	m_EdgeCurPos = m_EdgeMovePos;
	vPDC->SelectStockObject(BLACK_PEN);
}
void CUDGraphDFSDraw::DrawGraphGrid(CDC *vPDC)
{
	CRect tRect;
	GetClientRect(&tRect);
	tRect.left = m_nGridLeft;
	tRect.top = m_nGridTop;
	tRect.right -= m_nGridLeft;
	tRect.bottom -= m_nGridTop;
	m_nGridWidth = tRect.Width();
	m_nGridHeight = tRect.Height();
	int i, j, x, y;
	vPDC->SelectStockObject(BLACK_PEN);
	for (i = 0; i<m_nGridColumn; i++) {
		for (j = 0; j<m_nGridRow; j++) {
			x = m_nGridLeft + i*m_nGridWidth / (m_nGridColumn - 1);
			y = m_nGridTop + j*m_nGridHeight / (m_nGridRow - 1);
			vPDC->Ellipse(x - 1, y - 1, x + 1, y + 1);
		}
	}
	CPen newpen(PS_SOLID, 2, RGB(0, 0, 255));
	vPDC->SelectObject(&newpen);
	vPDC->MoveTo(m_nGridLeft, m_nGridTop);
	vPDC->LineTo(m_nGridLeft + tRect.Width(), m_nGridTop);
	vPDC->MoveTo(m_nGridLeft, m_nGridTop);
	vPDC->LineTo(m_nGridLeft, m_nGridTop + tRect.Height());
	vPDC->MoveTo(m_nGridLeft, m_nGridTop + tRect.Height());
	vPDC->LineTo(m_nGridLeft + tRect.Width(), m_nGridTop + tRect.Height());
	vPDC->MoveTo(m_nGridLeft + tRect.Width(), m_nGridTop);
	vPDC->LineTo(m_nGridLeft + tRect.Width(), m_nGridTop + tRect.Height());
	vPDC->SelectStockObject(BLACK_PEN);
}
void CUDGraphDFSDraw::DrawDFSTraverse(CDC * vPDC,
	HANDLE vHEvent)
{
	m_UDGraphDFS.DFSTraverse(vPDC, vHEvent, m_StartPointDFS);
}


void CUDGraphDFSDraw::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CFormView::OnPaint()
	CUDGraphDFSDraw *tPUDGraphDFSDraw = this;
	m_hThreadUDGraphDFS = CreateThread(
		NULL,
		0,
		(LPTHREAD_START_ROUTINE)UDGraphDFSProc,
		(LPVOID)tPUDGraphDFSDraw, 0, NULL
	);
	CloseHandle(m_hThreadUDGraphDFS);
}
int CUDGraphDFSDraw::GetUGraphVertexNum()
{
	return m_UDGraphDFS.m_VertexNum;
}
int CUDGraphDFSDraw::GetUGraphEdgeNum()
{
	return m_UDGraphDFS.m_EdgeNum;
}
void CUDGraphDFSDraw::OnUGVertexInfor()
{
	m_UDGraphDFS.m_IsShowVertexInfor =
		!m_UDGraphDFS.m_IsShowVertexInfor;
	this->Invalidate();
}
void CUDGraphDFSDraw::OnUGEdgeInfor()
{
	m_UDGraphDFS.m_IsShowEdgeInfor =
		!m_UDGraphDFS.m_IsShowEdgeInfor;
	this->Invalidate();
}
void CUDGraphDFSDraw::GetPointOffset(CPoint& vPoint,
	CPoint vOrignPoint)
{
	float tAdjPointDis_LU, tAdjPointDis_LD,
		tAdjPointDis_RU, tAdjPointDis_RD;// 左上、左下、右上、右下
	vPoint.x = (vOrignPoint.x - m_nGridLeft)*(m_nGridColumn - 1) / m_nGridWidth;
	vPoint.y = (vOrignPoint.y - m_nGridLeft)*(m_nGridRow - 1) / m_nGridHeight;
	int tX = m_nGridLeft + vPoint.x*m_nGridWidth / (m_nGridColumn - 1);
	int tY = m_nGridTop + vPoint.y*m_nGridHeight / (m_nGridRow - 1);
	int tWidth = m_nGridWidth / (m_nGridColumn - 1);
	int tHeight = m_nGridHeight / (m_nGridRow - 1);
	tAdjPointDis_LU = abs(vOrignPoint.x - tX)
		+ abs(vOrignPoint.y - tY);
	tAdjPointDis_RU = abs(vOrignPoint.x - (tX + tWidth))
		+ abs(vOrignPoint.y - tY);
	tAdjPointDis_LD = abs(vOrignPoint.x - tX)
		+ abs(vOrignPoint.y - (tY + tHeight));
	tAdjPointDis_RD = abs(vOrignPoint.x - (tX + tWidth))
		+ abs(vOrignPoint.y - (tY + tHeight));
	//计算逻辑偏移
	if (tAdjPointDis_RU<tAdjPointDis_LU
		&& tAdjPointDis_RU<tAdjPointDis_LD &&
		tAdjPointDis_RU<tAdjPointDis_RD) {
		vPoint.x++;
	}
	else if (tAdjPointDis_LD<tAdjPointDis_RU
		&& tAdjPointDis_LD<tAdjPointDis_RU &&
		tAdjPointDis_LD<tAdjPointDis_RD) {
		vPoint.y++;
	}
	else if (tAdjPointDis_RD<tAdjPointDis_LU
		&& tAdjPointDis_RD<tAdjPointDis_RU &&
		tAdjPointDis_RD<tAdjPointDis_LD) {
		vPoint.x++; vPoint.y++;
	}
	// 换算为绝对坐标
	vPoint.x = m_nGridLeft + vPoint.x
		*m_nGridWidth / (m_nGridColumn - 1);
	vPoint.y = m_nGridTop + vPoint.y
		*m_nGridHeight / (m_nGridRow - 1);
}


void CUDGraphDFSDraw::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CPoint tPoint;
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	GetPointOffset(tPoint, point);
	switch (pMainFrame->m_FunType)
	{
	case 1:
		m_UDGraphDFS.InsertVertex(tPoint);
		m_Flag = 0;
		this->Invalidate();
		break;
	case 2:
		m_UDGraphDFS.DeleteVertex(point);
		m_Flag = 0;
		this->Invalidate();
		break;
	case 3:
		if (m_UDGraphDFS.IsPointInGraph(point))
		{
			// 判断当前鼠标坐标点是否在列表中
			if (m_bStartFlag == TRUE)
			{
				// 边的起始顶点
				m_bStartFlag = FALSE;
				m_pBeginNode = m_UDGraphDFS.IsPointInGraph(point);
				m_EdgeSrcVex = tPoint;
				m_EdgeCurPos = tPoint;
				m_bEdgeSource = TRUE;
			}
			else
			{
				// 边的结束顶点
				m_pEndNode = m_UDGraphDFS.IsPointInGraph(point);
				if (!m_UDGraphDFS.IsEdgeExist(m_pBeginNode,
					m_pEndNode)
					&& m_pBeginNode != m_pEndNode)
				{
					m_bStartFlag = TRUE;
					m_bEdgeSource = FALSE;
					m_UDGraphDFS.InsertEdge(m_pBeginNode,
						m_pEndNode, 0);
				}
				else
				{
					if (m_pBeginNode == m_pEndNode)
						::AfxMessageBox(_T(" 请选择不同的顶点."));
					else
						::AfxMessageBox(_T(" 边已经被插入. "));
					m_bStartFlag = TRUE;
				}
			}
		}
		m_Flag = 0;
		this->Invalidate();
		break;
	case 4:
		if (m_UDGraphDFS.IsPointInGraph(point))
		{
			// 判断当前鼠标坐标点是否在列表中
			if (m_bStartFlag == TRUE)
			{
				// 边的起始顶点
				m_bStartFlag = FALSE;
				m_pBeginNode = m_UDGraphDFS.IsPointInGraph(point);
			}
			else
			{
				// 边的结束顶点
				m_pEndNode = m_UDGraphDFS.IsPointInGraph(point);
				if (m_UDGraphDFS.IsEdgeExist(m_pBeginNode,
					m_pEndNode)
					&& m_pBeginNode != m_pEndNode)
				{
					m_bStartFlag = TRUE;
					m_UDGraphDFS.DeleteEdge(m_pBeginNode,
						m_pEndNode);
				}
				else
				{
					if (m_pBeginNode == m_pEndNode)
						::AfxMessageBox(_T(" 请选择不同的顶点."));
					else
						::AfxMessageBox(_T(" 边不存在. "));
					m_bStartFlag = TRUE;
				}
			}
		}
		m_Flag = 0;
		this->Invalidate();
		break;
	case 5:
		if (m_UDGraphDFS.IsPointInGraph(point))
		{
			// 判断当前鼠标坐标点是否在列表中
			if (m_bStartFlag == TRUE)
			{
				// 边的起始顶点
				m_bStartFlag = FALSE;
				m_pBeginNode = m_UDGraphDFS.IsPointInGraph(point);
			}
			else
			{
				// 边的结束顶点
				m_pEndNode = m_UDGraphDFS.IsPointInGraph(point);
				if (m_UDGraphDFS.IsEdgeExist(m_pBeginNode,
					m_pEndNode)
					&& m_pBeginNode != m_pEndNode)
				{
					m_bStartFlag = TRUE;
					CGraphSetWeight tGraphWeightDlg(NULL);
					tGraphWeightDlg.m_GraphVertexFrom =
						m_pBeginNode->m_StrName;
					tGraphWeightDlg.m_GraphVertexTo =
						m_pEndNode->m_StrName;
					if (tGraphWeightDlg.DoModal() == IDOK)
					{
						m_UDGraphDFS.SetEdgeWeight(m_pBeginNode,
							m_pEndNode, tGraphWeightDlg.m_Weight);
					}
				}
				else
				{
					if (m_pBeginNode == m_pEndNode)
						::AfxMessageBox(_T(" 请选择不同的顶点."));
					else
						::AfxMessageBox(_T(" 边不存在. "));
					m_bStartFlag = TRUE;
				}
			}
		}
		m_Flag = 0;
		this->Invalidate();
		break;
}

	CFormView::OnLButtonDown(nFlags, point);
}


void CUDGraphDFSDraw::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	switch (pMainFrame->m_FunType)
	{
	case 3:
		m_bEdgeSource = FALSE;
		m_Flag = -1;
		this->Invalidate();
		break;
	}
	CFormView::OnRButtonDown(nFlags, point);
}


void CUDGraphDFSDraw::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect tWinSize;
	CPoint tPoint;
	this->GetClientRect(tWinSize);
	GetPointOffset(tPoint, point);
	if (!m_bEdgeSource) {
		return;
	}
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	switch (pMainFrame->m_FunType)
	{
	case 3:
		m_EdgeMovePos = tPoint;
		m_Flag = 1;
		this->InvalidateRect(&tWinSize, false);
		break;
	}
	CFormView::OnMouseMove(nFlags, point);
}
void CUDGraphDFSDraw::ExecuteDFS(CString vStart)
{
	m_Flag = 2;
	if (!m_UDGraphDFS.IsPointInGraph(vStart))
	{
		::AfxMessageBox(_T(" 请输入正确的遍历起始点."));
		return;
	}
	m_StartPointDFS = vStart;
	this->Invalidate();
	Sleep(600);
	::ResetEvent(m_hEventUDGraphDFS);
}
void CUDGraphDFSDraw::DFSStep()
{
	::SetEvent(m_hEventUDGraphDFS);
	Sleep(200);
	::ResetEvent(m_hEventUDGraphDFS);
}