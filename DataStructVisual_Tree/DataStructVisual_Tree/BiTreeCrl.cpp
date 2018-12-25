// BiTreeCrl.cpp : 实现文件
//

#include "stdafx.h"
#include "DataStructVisual_Tree.h"
#include "BiTreeCrl.h"


// CBiTreeCrl

IMPLEMENT_DYNCREATE(CBiTreeCrl, CFormView)

CBiTreeCrl::CBiTreeCrl()
	: CFormView(IDD_BITREE_CONTROL)
	, m_BiTreeNodeVal(_T(""))
{

}

CBiTreeCrl::~CBiTreeCrl()
{
}

void CBiTreeCrl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BITREE_DATA, m_BiTreeNodeVal);
}

BEGIN_MESSAGE_MAP(CBiTreeCrl, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_INSERTBITREENODE, &CBiTreeCrl::OnBnClickedButtonInsertbitreenode)
	ON_BN_CLICKED(IDC_BUTTON_DELETEBITREENODE, &CBiTreeCrl::OnBnClickedButtonDeletebitreenode)
	ON_BN_CLICKED(IDC_BUTTON_SEARCHBITREENODE, &CBiTreeCrl::OnBnClickedButtonSearchbitreenode)
END_MESSAGE_MAP()


// CBiTreeCrl 诊断

#ifdef _DEBUG
void CBiTreeCrl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CBiTreeCrl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBiTreeCrl 消息处理程序


void CBiTreeCrl::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	GetDlgItem(IDC_BUTTON_DELETEBITREENODE)->
		EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SEARCHBITREENODE)->
		EnableWindow(FALSE);
}


void CBiTreeCrl::OnBnClickedButtonInsertbitreenode()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_BiTreeNodeVal.IsEmpty()) {
		::AfxMessageBox(_T(" 请输入插入结点值."));
		return;
	}
	int tBiTreeNodeVal = _ttoi(m_BiTreeNodeVal);
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CBiTreeDraw*)(pWnd->GetPane(0, 0)))->
		InsertBiTreeNode(tBiTreeNodeVal);
	GetDlgItem(IDC_BUTTON_DELETEBITREENODE)->
		EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SEARCHBITREENODE)->
		EnableWindow(TRUE);
}


void CBiTreeCrl::OnBnClickedButtonDeletebitreenode()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_BiTreeNodeVal.IsEmpty()) {
		::AfxMessageBox(_T(" 请输入删除结点值."));
		return;
	}
	int tBiTreeNodeVal = _ttoi(m_BiTreeNodeVal);
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CBiTreeDraw*)(pWnd->GetPane(0, 0)))->
		DeleteBiTreeNode(tBiTreeNodeVal);
	GetDlgItem(IDC_BUTTON_DELETEBITREENODE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SEARCHBITREENODE)->
		EnableWindow(TRUE);
}


void CBiTreeCrl::OnBnClickedButtonSearchbitreenode()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_BiTreeNodeVal.IsEmpty()) {
		::AfxMessageBox(_T(" 请输入查找结点值."));
		return;
	}
	int tBiTreeNodeVal = _ttoi(m_BiTreeNodeVal);
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CBiTreeDraw*)(pWnd->GetPane(0, 0)))->
		SearchBiTreeNode(tBiTreeNodeVal);
}
