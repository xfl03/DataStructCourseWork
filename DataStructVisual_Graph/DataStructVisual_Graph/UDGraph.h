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
		m_UDGraphVertexContainer;// 无向图顶点存储容器
	CTypedPtrList <CObList, CGraphEdgeNode*>
		m_UDGraphEdgeContainer;// 无向图边存储容器
	int m_VertexNum;// 图顶点个数
	int m_VertexIndex;// 图顶点编号
	int m_EdgeNum;// 图边个数
	BOOL m_IsShowVertexInfor;// 是否显示顶点结点的信息
	BOOL m_IsShowEdgeInfor;// 是否显示边结点的信息
public:
	void InsertVertex(CPoint vPoint);// 新增顶点
	void DeleteVertex(CPoint vPoint);// 删除顶点
									 // 判断坐标为 vPoint 的顶点是否存在
	CGraphVertexNode* IsPointInGraph(CPoint vPoint);
	// 判断值为 vVertexName 的顶点是否存在
	BOOL IsPointInGraph(CString vVertexName);
	// 判断边(vPBeginVertex,vPEndVertex) 是否存在
	BOOL IsEdgeExist(CGraphVertexNode* vPBeginVertex,
		CGraphVertexNode* vPEndVertex);
	void InsertEdge(CGraphVertexNode* vPBeginVertex,
		CGraphVertexNode* vPEndVertex, int vWeight);// 插入边
	void DrawUDGraph(CDC *pDC);// 绘制无向图
	void DrawUDGraphVertex(CDC *pDC);// 绘制无向图顶点
	void DrawUDGraphEdge(CDC *pDC);// 绘制无向图边
	void DeleteEdge(CGraphVertexNode* vPBeginVertex,
		CGraphVertexNode* vPEndVertex);// 删除边
	void SetEdgeWeight(CGraphVertexNode* vPBeginVertex,
		CGraphVertexNode* vPEndVertex, int vWeight);// 设置边的权值
													// 深度优先遍历顶点 vPBeginVertex 所在的连通子图
	void DFS(CGraphVertexNode* vPBeginVertex,
		CDC* vPDC, HANDLE vHEventNG);
	void DFSTraverse(CDC *vPDC,
		HANDLE vHEventNG, CString vPoint);// 深度优先遍历图
										  // 值为 vName 的顶点在邻接多重表中的序号
	int IndexVertexInGraph(CString vName);
	void ClearGraph();// 置空图
	void LoadUDGraph(FILE* vFileName);// 加载图
	void SaveUDGraph(FILE* vFileName);// 保存图
};

