
// DataStructVisual_Graph.h : DataStructVisual_Graph Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDataStructVisual_GraphApp:
// �йش����ʵ�֣������ DataStructVisual_Graph.cpp
//

class CDataStructVisual_GraphApp : public CWinApp
{
public:
	CDataStructVisual_GraphApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDataStructVisual_GraphApp theApp;
