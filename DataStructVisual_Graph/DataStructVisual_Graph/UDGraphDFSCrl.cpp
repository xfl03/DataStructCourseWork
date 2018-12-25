// UDGraphDFSCrl.cpp : 实现文件
//

#include "stdafx.h"
#include "DataStructVisual_Graph.h"
#include "UDGraphDFSCrl.h"
#include "UDGraphDFSDraw.h"

// CUDGraphDFSCrl

IMPLEMENT_DYNCREATE(CUDGraphDFSCrl, CFormView)

CUDGraphDFSCrl::CUDGraphDFSCrl()
	: CFormView(IDD_UDGRAPHDFS_CONTROL)
	, m_UDGraphDFSVal(_T(""))
{

}

CUDGraphDFSCrl::~CUDGraphDFSCrl()
{
}

void CUDGraphDFSCrl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_UDGRAPHDFS_DATA, m_UDGraphDFSVal);
	DDV_MaxChars(pDX, m_UDGraphDFSVal, 1);
}

BEGIN_MESSAGE_MAP(CUDGraphDFSCrl, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_UDGRAPHDFS_EXECUTE, &CUDGraphDFSCrl::OnBnClickedButtonUdgraphdfsExecute)
	ON_BN_CLICKED(IDC_BUTTON_UDGRAPHDFS_NEXT, &CUDGraphDFSCrl::OnBnClickedButtonUdgraphdfsNext)
END_MESSAGE_MAP()


// CUDGraphDFSCrl 诊断

#ifdef _DEBUG
void CUDGraphDFSCrl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUDGraphDFSCrl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUDGraphDFSCrl 消息处理程序


void CUDGraphDFSCrl::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	UpdateData(false);
	GetDlgItem(IDC_BUTTON_UDGRAPHDFS_NEXT)->
		EnableWindow(FALSE);
}


void CUDGraphDFSCrl::OnBnClickedButtonUdgraphdfsExecute()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tStartPoint;
	UpdateData(TRUE);
	if (m_UDGraphDFSVal.IsEmpty()) {
		::AfxMessageBox(_T(" 请输入源点."));
		return;
	}
	tStartPoint = m_UDGraphDFSVal.GetAt(0);
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CUDGraphDFSDraw*)(pWnd->GetPane(0, 0)))->
		ExecuteDFS(tStartPoint);
	GetDlgItem(IDC_BUTTON_UDGRAPHDFS_NEXT)->
		EnableWindow(TRUE);
}


void CUDGraphDFSCrl::OnBnClickedButtonUdgraphdfsNext()
{
	// TODO: 在此添加控件通知处理程序代码
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CUDGraphDFSDraw*)(pWnd->GetPane(0, 0)))->DFSStep();
}
