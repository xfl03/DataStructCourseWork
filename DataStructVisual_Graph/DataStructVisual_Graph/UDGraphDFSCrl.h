#pragma once



// CUDGraphDFSCrl ������ͼ

class CUDGraphDFSCrl : public CFormView
{
	DECLARE_DYNCREATE(CUDGraphDFSCrl)

protected:
	CUDGraphDFSCrl();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CUDGraphDFSCrl();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UDGRAPHDFS_CONTROL };
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
	CString m_UDGraphDFSVal;
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButtonUdgraphdfsExecute();
	afx_msg void OnBnClickedButtonUdgraphdfsNext();
};


