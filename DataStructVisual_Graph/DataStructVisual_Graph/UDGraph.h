#pragma once
#include "math.h"
#include <afxtempl.h>
#include <afxwin.h>
#include <afxext.h>
#include "GraphVertexNode.h"
class CUDGraph
{
public:
	CUDGraph();
	~CUDGraph();
	CTypedPtrList <CObList, CGraphVertexNode*>
		m_UDGraphVertexContainer;// ����ͼ����洢����
	CTypedPtrList <CObList, CGraphEdgeNode*>
		m_UDGraphEdgeContainer;// ����ͼ�ߴ洢����
	int m_VertexNum;// ͼ�������
	int m_VertexIndex;// ͼ������
	int m_EdgeNum;// ͼ�߸���
	BOOL m_IsShowVertexInfor;// �Ƿ���ʾ���������Ϣ
	BOOL m_IsShowEdgeInfor;// �Ƿ���ʾ�߽�����Ϣ
public:
	void InsertVertex(CPoint vPoint);// ��������
	void DeleteVertex(CPoint vPoint);// ɾ������
									 // �ж�����Ϊ vPoint �Ķ����Ƿ����
	CGraphVertexNode* IsPointInGraph(CPoint vPoint);
	// �ж�ֵΪ vVertexName �Ķ����Ƿ����
	BOOL IsPointInGraph(CString vVertexName);
	// �жϱ�(vPBeginVertex,vPEndVertex) �Ƿ����
	BOOL IsEdgeExist(CGraphVertexNode* vPBeginVertex,
		CGraphVertexNode* vPEndVertex);
	void InsertEdge(CGraphVertexNode* vPBeginVertex,
		CGraphVertexNode* vPEndVertex, int vWeight);// �����
	void DrawUDGraph(CDC *pDC);// ��������ͼ
	void DrawUDGraphVertex(CDC *pDC);// ��������ͼ����
	void DrawUDGraphEdge(CDC *pDC);// ��������ͼ��
	void DeleteEdge(CGraphVertexNode* vPBeginVertex,
		CGraphVertexNode* vPEndVertex);// ɾ����
	void SetEdgeWeight(CGraphVertexNode* vPBeginVertex,
		CGraphVertexNode* vPEndVertex, int vWeight);// ���ñߵ�Ȩֵ
													// ������ȱ������� vPBeginVertex ���ڵ���ͨ��ͼ
	void DFS(CGraphVertexNode* vPBeginVertex,
		CDC* vPDC, HANDLE vHEventNG);
	void DFSTraverse(CDC *vPDC,
		HANDLE vHEventNG, CString vPoint);// ������ȱ���ͼ
										  // ֵΪ vName �Ķ������ڽӶ��ر��е����
	int IndexVertexInGraph(CString vName);
	void ClearGraph();// �ÿ�ͼ
	void LoadUDGraph(FILE* vFileName);// ����ͼ
	void SaveUDGraph(FILE* vFileName);// ����ͼ
};

