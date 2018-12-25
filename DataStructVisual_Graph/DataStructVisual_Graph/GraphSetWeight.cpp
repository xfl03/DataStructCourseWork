// GraphSetWeight.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DataStructVisual_Graph.h"
#include "GraphSetWeight.h"
#include "afxdialogex.h"


// CGraphSetWeight �Ի���

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


// CGraphSetWeight ��Ϣ�������


BOOL CGraphSetWeight::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
