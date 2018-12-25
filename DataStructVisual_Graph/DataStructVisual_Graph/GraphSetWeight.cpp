// GraphSetWeight.cpp : 实现文件
//

#include "stdafx.h"
#include "DataStructVisual_Graph.h"
#include "GraphSetWeight.h"
#include "afxdialogex.h"


// CGraphSetWeight 对话框

IMPLEMENT_DYNAMIC(CGraphSetWeight, CDialog)

CGraphSetWeight::CGraphSetWeight(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_GRAPH_SETWEIGHT, pParent)
	, m_Weight(0)
	, m_GraphVertexFrom(_T(""))
	, m_GraphVertexTo(_T(""))
{

}

CGraphSetWeight::~CGraphSetWeight()
{
}

void CGraphSetWeight::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDGE_WEIGHT, m_Weight);
	DDX_Text(pDX, IDC_GRAPHVERTEX_FROM, m_GraphVertexFrom);
	DDX_Text(pDX, IDC_GRAPHVERTEX_TO, m_GraphVertexTo);
}


BEGIN_MESSAGE_MAP(CGraphSetWeight, CDialog)
END_MESSAGE_MAP()


// CGraphSetWeight 消息处理程序


BOOL CGraphSetWeight::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
