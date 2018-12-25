#pragma once


// CGraphSetWeight 对话框

class CGraphSetWeight : public CDialog
{
	DECLARE_DYNAMIC(CGraphSetWeight)

public:
	CGraphSetWeight(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGraphSetWeight();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GRAPH_SETWEIGHT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_Weight;
	CString m_GraphVertexFrom;
	CString m_GraphVertexTo;
	virtual BOOL OnInitDialog();
};
