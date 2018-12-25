// UDGraphDFSCrl.cpp : ʵ���ļ�
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


// CUDGraphDFSCrl ���

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


// CUDGraphDFSCrl ��Ϣ�������


void CUDGraphDFSCrl::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	UpdateData(false);
	GetDlgItem(IDC_BUTTON_UDGRAPHDFS_NEXT)->
		EnableWindow(FALSE);
}


void CUDGraphDFSCrl::OnBnClickedButtonUdgraphdfsExecute()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tStartPoint;
	UpdateData(TRUE);
	if (m_UDGraphDFSVal.IsEmpty()) {
		::AfxMessageBox(_T(" ������Դ��."));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CUDGraphDFSDraw*)(pWnd->GetPane(0, 0)))->DFSStep();
}
