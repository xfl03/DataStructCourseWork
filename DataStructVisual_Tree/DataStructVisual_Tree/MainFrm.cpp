
// MainFrm.cpp : CMainFrame 类的实现
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
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
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
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

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


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类
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
	// 窗口已经创建，允许执行窗口重绘功能
	m_bSplitterWndCreated = true;
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	return true;
}


void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
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
