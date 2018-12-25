
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "DataStructVisual_Tree.h"
#include "BiTreeDraw.h"
#include "BiTreeCrl.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
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
		0, 0,
		RUNTIME_CLASS(CBiTreeDraw),
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
		RUNTIME_CLASS(CBiTreeCrl),
		CSize(rect.Width(), rect.Height() * 1 / 4),
		pContext))
	{
		TRACE0("Failed to create right pane frame\n");
		return FALSE;
	}
	// �����Ѿ�����������ִ�д����ػ湦��
	m_bSplitterWndCreated = true;
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	return true;
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
