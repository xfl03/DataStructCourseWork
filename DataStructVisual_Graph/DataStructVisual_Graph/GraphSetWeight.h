#pragma once


// CGraphSetWeight �Ի���

class CGraphSetWeight : public CDialog
{
	DECLARE_DYNAMIC(CGraphSetWeight)

public:
	CGraphSetWeight(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGraphSetWeight();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GRAPH_SETWEIGHT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_Weight;
	CString m_GraphVertexFrom;
	CString m_GraphVertexTo;
	virtual BOOL OnInitDialog();
};
