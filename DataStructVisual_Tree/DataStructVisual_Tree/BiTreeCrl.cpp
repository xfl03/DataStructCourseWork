// BiTreeCrl.cpp : ʵ���ļ�
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


// CBiTreeCrl ���

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


// CBiTreeCrl ��Ϣ�������


void CBiTreeCrl::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	GetDlgItem(IDC_BUTTON_DELETEBITREENODE)->
		EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SEARCHBITREENODE)->
		EnableWindow(FALSE);
}


void CBiTreeCrl::OnBnClickedButtonInsertbitreenode()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_BiTreeNodeVal.IsEmpty()) {
		::AfxMessageBox(_T(" �����������ֵ."));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_BiTreeNodeVal.IsEmpty()) {
		::AfxMessageBox(_T(" ������ɾ�����ֵ."));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_BiTreeNodeVal.IsEmpty()) {
		::AfxMessageBox(_T(" ��������ҽ��ֵ."));
		return;
	}
	int tBiTreeNodeVal = _ttoi(m_BiTreeNodeVal);
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CBiTreeDraw*)(pWnd->GetPane(0, 0)))->
		SearchBiTreeNode(tBiTreeNodeVal);
}
