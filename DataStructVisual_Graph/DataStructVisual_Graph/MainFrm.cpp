
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "DataStructVisual_Graph.h"
#include "UDGraphDFSDraw.h"
#include "UDGraphDFSCrl.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_GRAPH_OPEN, &CMainFrame::OnGraphOpen)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_OPEN, &CMainFrame::OnUpdateGraphOpen)
	ON_COMMAND(ID_GRAPH_SAVE, &CMainFrame::OnGraphSave)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_SAVE, &CMainFrame::OnUpdateGraphSave)
	ON_COMMAND(ID_GRAPH_CLEAR, &CMainFrame::OnGraphClear)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_CLEAR, &CMainFrame::OnUpdateGraphClear)
	ON_COMMAND(ID_GRAPH_VERTEX_ADD, &CMainFrame::OnGraphVertexAdd)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_VERTEX_ADD, &CMainFrame::OnUpdateGraphVertexAdd)
	ON_COMMAND(ID_GRAPH_VERTEX_DELETE, &CMainFrame::OnGraphVertexDelete)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_VERTEX_DELETE, &CMainFrame::OnUpdateGraphVertexDelete)
	ON_COMMAND(ID_GRAPH_VERTEX_INFO, &CMainFrame::OnGraphVertexInfo)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_VERTEX_INFO, &CMainFrame::OnUpdateGraphVertexInfo)
	ON_COMMAND(ID_GRAPH_EDGE_ADD, &CMainFrame::OnGraphEdgeAdd)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_EDGE_ADD, &CMainFrame::OnUpdateGraphEdgeAdd)
	ON_COMMAND(ID_GRAPH_EDGE_DELETE, &CMainFrame::OnGraphEdgeDelete)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_EDGE_DELETE, &CMainFrame::OnUpdateGraphEdgeDelete)
	ON_COMMAND(ID_GRAPH_EDGE_INFO, &CMainFrame::OnGraphEdgeInfo)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_EDGE_INFO, &CMainFrame::OnUpdateGraphEdgeInfo)
	ON_COMMAND(ID_GRAPH_EDGE_SETWEIGHT, &CMainFrame::OnGraphEdgeSetweight)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_EDGE_SETWEIGHT, &CMainFrame::OnUpdateGraphEdgeSetweight)
	ON_WM_SIZE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
	: m_FunType(0)
	, m_bSplitterWndCreated(false)
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������



void CMainFrame::OnGraphOpen()
{
	// TODO: �ڴ���������������
}


void CMainFrame::OnUpdateGraphOpen(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
}


void CMainFrame::OnGraphSave()
{
	// TODO: �ڴ���������������
}


void CMainFrame::OnUpdateGraphSave(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
}


void CMainFrame::OnGraphClear()
{
	// TODO: �ڴ���������������
}


void CMainFrame::OnUpdateGraphClear(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
}


void CMainFrame::OnGraphVertexAdd()
{
	// TODO: �ڴ���������������
	m_FunType = 1;
}


void CMainFrame::OnUpdateGraphVertexAdd(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
}


void CMainFrame::OnGraphVertexDelete()
{
	// TODO: �ڴ���������������
	m_FunType = 2;
}


void CMainFrame::OnUpdateGraphVertexDelete(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	CUDGraphDFSDraw* tPCUDGraphDFSDraw =
		(CUDGraphDFSDraw*)m_wndSplitter.GetPane(0, 0);
	if (tPCUDGraphDFSDraw->GetUGraphVertexNum()>0)
	{
		pCmdUI->Enable(TRUE);
	}
	else
	{
		pCmdUI->Enable(FALSE);
	}
}


void CMainFrame::OnGraphVertexInfo()
{
	// TODO: �ڴ���������������
	CUDGraphDFSDraw* tPCUDGraphDFSDraw =
		(CUDGraphDFSDraw*)m_wndSplitter.GetPane(0, 0);
	tPCUDGraphDFSDraw->OnUGVertexInfor();
}


void CMainFrame::OnUpdateGraphVertexInfo(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	CUDGraphDFSDraw* tPCUDGraphDFSDraw =
		(CUDGraphDFSDraw*)m_wndSplitter.GetPane(0, 0);
	if (tPCUDGraphDFSDraw->GetUGraphVertexNum()>0)
	{
		pCmdUI->Enable(TRUE);
	}
	else
	{
		pCmdUI->Enable(FALSE);
	}
}


void CMainFrame::OnGraphEdgeAdd()
{
	// TODO: �ڴ���������������
	m_FunType = 3;
}


void CMainFrame::OnUpdateGraphEdgeAdd(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	CUDGraphDFSDraw* tPCUDGraphDFSDraw =
		(CUDGraphDFSDraw*)m_wndSplitter.GetPane(0, 0);
	if (tPCUDGraphDFSDraw->GetUGraphVertexNum()>0)
	{
		pCmdUI->Enable(TRUE);
	}
	else
	{
		pCmdUI->Enable(FALSE);
	}
}


void CMainFrame::OnGraphEdgeDelete()
{
	// TODO: �ڴ���������������
	m_FunType = 4;
}


void CMainFrame::OnUpdateGraphEdgeDelete(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	CUDGraphDFSDraw* tPCUDGraphDFSDraw =
		(CUDGraphDFSDraw*)m_wndSplitter.GetPane(0, 0);
	if (tPCUDGraphDFSDraw->GetUGraphEdgeNum()>0)
	{
		pCmdUI->Enable(TRUE);
	}
	else
	{
		pCmdUI->Enable(FALSE);
	}
}


void CMainFrame::OnGraphEdgeInfo()
{
	// TODO: �ڴ���������������
	CUDGraphDFSDraw* tPCUDGraphDFSDraw =
		(CUDGraphDFSDraw*)m_wndSplitter.GetPane(0, 0);
	tPCUDGraphDFSDraw->OnUGEdgeInfor();
}


void CMainFrame::OnUpdateGraphEdgeInfo(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	CUDGraphDFSDraw* tPCUDGraphDFSDraw =
		(CUDGraphDFSDraw*)m_wndSplitter.GetPane(0, 0);
	if (tPCUDGraphDFSDraw->GetUGraphEdgeNum()>0)
	{
		pCmdUI->Enable(TRUE);
	}
	else
	{
		pCmdUI->Enable(FALSE);
	}
}


void CMainFrame::OnGraphEdgeSetweight()
{
	// TODO: �ڴ���������������
	m_FunType = 5;
}


void CMainFrame::OnUpdateGraphEdgeSetweight(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	CUDGraphDFSDraw* tPCUDGraphDFSDraw =
		(CUDGraphDFSDraw*)m_wndSplitter.GetPane(0, 0);
	if (tPCUDGraphDFSDraw->GetUGraphEdgeNum()>0)
	{
		pCmdUI->Enable(TRUE);
	}
	else
	{
		pCmdUI->Enable(FALSE);
	}
}


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���
	m_bSplitterWndCreated = false;
	if (!m_wndSplitter.CreateStatic(this, 2, 1))
	{
		TRACE0("Failed to create splitter window\n");
		return FALSE;
	}
	CRect rect;
	GetClientRect(&rect);
	if (!m_wndSplitter.CreateView(
		0,
		0,
		RUNTIME_CLASS(CUDGraphDFSDraw),
		CSize(rect.Width(), rect.Height() * 3 / 4),
		pContext)
		)
	{
		TRACE0("Failed to create left pane view\n");
		return FALSE;
	}
	if (!m_wndSplitter.CreateView(
		1,
		0,
		RUNTIME_CLASS(CUDGraphDFSCrl),
		CSize(rect.Width(), rect.Height() * 1 / 4),
		pContext))
	{
		TRACE0("Failed to create right pane frame\n");
		return FALSE;
	}
	// �����Ѿ�����������ִ�д����ػ湦��
	m_bSplitterWndCreated = true;
	return true;
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}


void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	if (m_bSplitterWndCreated)
	{
		CRect rect;
		m_wndSplitter.GetClientRect(&rect);
		m_wndSplitter.SetColumnInfo(0, rect.Width(), 10);
		m_wndSplitter.SetRowInfo(0, (rect.Height()) * 3 / 4, 10);
		m_wndSplitter.SetRowInfo(1, (rect.Height()) / 4, 10);
		m_wndSplitter.RecalcLayout();
	}
}
