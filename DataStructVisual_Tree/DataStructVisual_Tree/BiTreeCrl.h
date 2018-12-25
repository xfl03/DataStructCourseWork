#pragma once
#include "BiTreeDraw.h"


// CBiTreeCrl 窗体视图

class CBiTreeCrl : public CFormView
{
	DECLARE_DYNCREATE(CBiTreeCrl)

protected:
	CBiTreeCrl();           // 动态创建所使用的受保护的构造函数
	virtual ~CBiTreeCrl();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BITREE_CONTROL };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_BiTreeNodeVal;
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButtonInsertbitreenode();
	afx_msg void OnBnClickedButtonDeletebitreenode();
	afx_msg void OnBnClickedButtonSearchbitreenode();
};


