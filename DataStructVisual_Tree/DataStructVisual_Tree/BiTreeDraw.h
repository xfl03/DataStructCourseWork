#pragma once
#include "BiTree.h"
#include "DataStructVisual_TreeDoc.h"

// CBiTreeDraw ������ͼ

class CBiTreeDraw : public CFormView
{
	DECLARE_DYNCREATE(CBiTreeDraw)

protected:
	CBiTreeDraw();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CBiTreeDraw();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BITREE_DRAW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	CBiTree*  m_pTree;
	int m_Flag;
	HANDLE m_hThreadTree;
	HANDLE m_hEventTree;
	CDataStructVisual_TreeDoc* m_pDoc;
	CDataStructVisual_TreeDoc* GetDocument();
	virtual void OnInitialUpdate();
	static DWORD WINAPI BiTreeProc(LPVOID lpParameter);
	void DrawBiTree(CRect vWinRect,CDC* pDC);
	afx_msg void OnPaint();
	void InsertBiTreeNode(int vBTNValue);
	void DeleteBiTreeNode(int vBTNValue);
	void SearchBiTreeNode(int vBTNValue);
	void DrawBiTreeSearchNode(CDC* pDC);
};


