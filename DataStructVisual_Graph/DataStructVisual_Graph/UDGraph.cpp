#include "stdafx.h"
#include "UDGraph.h"
CUDGraph::CUDGraph()
{
	m_VertexNum = 0;
	m_EdgeNum = 0;
	m_VertexIndex = 0;
	m_IsShowVertexInfor = FALSE;
	m_IsShowEdgeInfor = FALSE;
}
CUDGraph::~CUDGraph()
{
}
void CUDGraph::InsertVertex(CPoint vPoint)
{
	if (m_VertexIndex<26)
	{
		CGraphVertexNode *pGraphVertexNode = new CGraphVertexNode();
		pGraphVertexNode->m_Index = m_VertexIndex;
		pGraphVertexNode->m_Point = vPoint;
		pGraphVertexNode->m_pFirstEdge = NULL;
		m_UDGraphVertexContainer.AddTail(pGraphVertexNode);
		m_VertexIndex++;
		m_VertexNum++;
	}
	else
	{
		::AfxMessageBox(_T(" 顶点编号已达最大值."));
	}
}
CGraphVertexNode* CUDGraph::IsPointInGraph(CPoint vPoint)
{
	POSITION tPos;
	int i = 0;
	CGraphVertexNode *pGraphVertexNode;
	for (tPos = m_UDGraphVertexContainer.GetHeadPosition(); tPos != NULL;)
	{
		pGraphVertexNode = m_UDGraphVertexContainer.GetNext(tPos);
		if (sqrt((double)(pGraphVertexNode->m_Point.x - vPoint.x)
			*(double)(pGraphVertexNode->m_Point.x - vPoint.x)
			+ (double)(pGraphVertexNode->m_Point.y - vPoint.y)
			*(double)(pGraphVertexNode->m_Point.y - vPoint.y))<15)
		{
			pGraphVertexNode->m_Index = i;
			return pGraphVertexNode;
		}
		i++;
	}
	return NULL;
}
BOOL CUDGraph::IsPointInGraph(CString vVertexName)
{
	// 由结点的名字获得它的指针
	POSITION tPos;
	CGraphVertexNode *pGraphVertexNode;
	for (tPos = m_UDGraphVertexContainer.GetHeadPosition(); tPos != NULL;)
	{
		pGraphVertexNode = m_UDGraphVertexContainer.GetNext(tPos);
		if (pGraphVertexNode->m_StrName == vVertexName)
			return TRUE;
	}
	return FALSE;
}
void CUDGraph::DeleteVertex(CPoint vPoint)
{
	POSITION tPos, tDelPos;
	CGraphEdgeNode * tPGraphEdge;
	CGraphVertexNode *tPGraphVertexFrom = IsPointInGraph(vPoint);
	int i = 0, j = -1;
	// 删除当前顶点所有的邻接边
	if (tPGraphVertexFrom != NULL) {
		for (tPos = m_UDGraphEdgeContainer.GetHeadPosition();
			tPos != NULL;) {
			tPGraphEdge = m_UDGraphEdgeContainer.GetNext(tPos);
			if (tPGraphVertexFrom == tPGraphEdge->m_pFromVertex
				|| tPGraphVertexFrom == tPGraphEdge->m_pToVertex)
			{
				j = i;
				tDelPos = m_UDGraphEdgeContainer.FindIndex(j);
				m_UDGraphEdgeContainer.RemoveAt(tDelPos);
				m_EdgeNum--;
			}
			else
			{
				i++;
			}
		}
		// 删除当前顶点
		tDelPos = m_UDGraphVertexContainer.
			FindIndex(tPGraphVertexFrom->m_Index);
		m_UDGraphVertexContainer.RemoveAt(tDelPos);
		m_VertexNum--;
	}
}
void CUDGraph::DrawUDGraph(CDC *pDC)
{
	DrawUDGraphEdge(pDC);
	DrawUDGraphVertex(pDC);
}
void CUDGraph::DrawUDGraphVertex(CDC *pDC)
{
	POSITION pos;
	CGraphVertexNode *pGraphVertexNode;
	for (pos = m_UDGraphVertexContainer.GetHeadPosition(); pos != NULL;)
	{
		pGraphVertexNode = m_UDGraphVertexContainer.GetNext(pos);
		if (!m_IsShowVertexInfor) {
			// 不显示图的节点信息
			pGraphVertexNode->DrawVertex(pDC, 0);
		}
		else {
			// 显示图的结点信息
			pGraphVertexNode->DrawVertex(pDC, 1);
		}
	}
}
void CUDGraph::DrawUDGraphEdge(CDC *pDC)
{
	POSITION pos;
	CGraphEdgeNode *pGraphEdgeNode;
	for (pos = m_UDGraphEdgeContainer.GetHeadPosition(); pos != NULL;)
	{
		pGraphEdgeNode = m_UDGraphEdgeContainer.GetNext(pos);
		if (!m_IsShowEdgeInfor) {
			// 不显示图的边信息
			pGraphEdgeNode->DrawEdge(pDC, 0);
		}
		else {
			// 显示图的边信息
			pGraphEdgeNode->DrawEdge(pDC, 1);
		}
	}
}
void CUDGraph::InsertEdge(CGraphVertexNode* vPBeginVertex,
	CGraphVertexNode* vPEndVertex, int vWeight)
{
	CGraphEdgeNode * tPGraphEdge = new CGraphEdgeNode();
	tPGraphEdge->m_bVisit = FALSE;
	tPGraphEdge->m_Weight = vWeight;
	tPGraphEdge->m_pFromVertex = vPBeginVertex;
	tPGraphEdge->m_pFromNextEdge = vPBeginVertex->m_pFirstEdge;
	vPBeginVertex->m_pFirstEdge = tPGraphEdge;
	tPGraphEdge->m_pToVertex = vPEndVertex;
	tPGraphEdge->m_pToNextEdge = vPEndVertex->m_pFirstEdge;
	vPEndVertex->m_pFirstEdge = tPGraphEdge;
	m_UDGraphEdgeContainer.AddTail(tPGraphEdge);
	m_EdgeNum++;
}
BOOL CUDGraph::IsEdgeExist(CGraphVertexNode* vPBeginVertex,
	CGraphVertexNode* vPEndVertex)
{
	CGraphEdgeNode* tPGraphEdge;
	POSITION tPos;
	int i = 0;
	for (tPos = m_UDGraphEdgeContainer.GetHeadPosition();
		tPos != NULL;) {
		tPGraphEdge = m_UDGraphEdgeContainer.GetNext(tPos);
		if ((vPBeginVertex == tPGraphEdge->m_pFromVertex
			&&vPEndVertex == tPGraphEdge->m_pToVertex)
			|| (vPBeginVertex == tPGraphEdge->m_pToVertex
				&&vPEndVertex == tPGraphEdge->m_pFromVertex))
		{
			return TRUE;
		}
	}
	return FALSE;
}
void CUDGraph::DeleteEdge(CGraphVertexNode* vPBeginVertex,
	CGraphVertexNode* vPEndVertex)
{
	CGraphEdgeNode* tPGraphEdge;
	POSITION tPos;
	int i = 0, j = -1;
	for (tPos = m_UDGraphEdgeContainer.GetHeadPosition(); tPos != NULL;) {
		tPGraphEdge = m_UDGraphEdgeContainer.GetNext(tPos);
		if ((vPBeginVertex == tPGraphEdge->m_pFromVertex &&
			vPEndVertex == tPGraphEdge->m_pToVertex)
			|| (vPBeginVertex == tPGraphEdge->m_pToVertex &&
				vPEndVertex == tPGraphEdge->m_pFromVertex))
		{
			j = i;
			break;
		}
		else
		{
			i++;
		}
	}
	if (j >= 0 && j<m_UDGraphEdgeContainer.GetCount())
	{
		tPos = m_UDGraphEdgeContainer.FindIndex(j);
		m_UDGraphEdgeContainer.RemoveAt(tPos);
		m_EdgeNum--;
	}
}
void CUDGraph::SetEdgeWeight(CGraphVertexNode* vPBeginVertex,
	CGraphVertexNode* vPEndVertex,
	int vWeight)
{
	CGraphEdgeNode* tPGraphEdge;
	POSITION tPos;
	for (tPos = m_UDGraphEdgeContainer.GetHeadPosition(); tPos != NULL;) {
		tPGraphEdge = m_UDGraphEdgeContainer.GetNext(tPos);
		if ((vPBeginVertex == tPGraphEdge->m_pFromVertex
			&& vPEndVertex == tPGraphEdge->m_pToVertex)
			|| (vPBeginVertex == tPGraphEdge->m_pToVertex
				&& vPEndVertex == tPGraphEdge->m_pFromVertex))
		{
			tPGraphEdge->m_Weight = vWeight;
			break;
		}
	}
}
void CUDGraph::DFS(CGraphVertexNode* vPBeginVertex,
	CDC* vPDC, HANDLE vHEventNG)
{
	//DFS 递归实现函数
	CGraphEdgeNode* tPGraphEdge;
	CGraphVertexNode* tPCurVertex;
	vPBeginVertex->m_bVisit = TRUE;
	DrawUDGraph(vPDC);
	Sleep(500 * 2);
	tPGraphEdge = vPBeginVertex->m_pFirstEdge;
	WaitForSingleObject(vHEventNG, -1);
	while (tPGraphEdge != NULL)
	{
		tPCurVertex = tPGraphEdge->m_pFromVertex == vPBeginVertex
			? tPGraphEdge->m_pToVertex : tPGraphEdge->m_pFromVertex;
		if (!tPCurVertex->m_bVisit) {
			DrawUDGraph(vPDC);
			DFS(tPCurVertex, vPDC, vHEventNG);
		}
		tPGraphEdge = tPGraphEdge->m_pFromVertex == vPBeginVertex
			? tPGraphEdge->m_pFromNextEdge
			: tPGraphEdge->m_pToNextEdge;
	}
}
void CUDGraph::DFSTraverse(CDC *vPDC, HANDLE vHEventNG,
	CString vPoint)
{
	POSITION tPos;
	CGraphVertexNode *pGraphVertexNode;
	CGraphEdgeNode *tPGraphEdge;
	for (tPos = m_UDGraphVertexContainer.
		GetHeadPosition(); tPos != NULL;)
	{
		pGraphVertexNode =
			m_UDGraphVertexContainer.GetNext(tPos);
		pGraphVertexNode->m_bVisit = FALSE;
	}
	for (tPos = m_UDGraphEdgeContainer.
		GetHeadPosition(); tPos != NULL;)
	{
		tPGraphEdge =
			m_UDGraphEdgeContainer.GetNext(tPos);
		tPGraphEdge->m_bVisit = FALSE;
	}
	// 通过循环数组方式遍历所有无向图顶点
	int tCount = m_UDGraphVertexContainer.GetCount();
	int tStart = IndexVertexInGraph(vPoint);
	if (tStart == -1)
	{
		::AfxMessageBox(_T("DFS 初始顶点错误!"));
		return;
	}
	else {
		for (int i = tStart, j = 0; j<tCount;
			i = (i + 1) % tCount, j++) {
			tPos = m_UDGraphVertexContainer.FindIndex(i);
			pGraphVertexNode =
				m_UDGraphVertexContainer.GetAt(tPos);
			if (!pGraphVertexNode->m_bVisit)
			{
				DFS(pGraphVertexNode, vPDC, vHEventNG);
			}
		}
	}
}
int CUDGraph::IndexVertexInGraph(CString vName)
{
	// 由结点的名字获取其指针
	CGraphVertexNode *pGraphVertexNode;
	POSITION tPos;
	int i = 0, j = -1;
	for (tPos = m_UDGraphVertexContainer.GetHeadPosition(); tPos != NULL;)
	{
		pGraphVertexNode = m_UDGraphVertexContainer.GetNext(tPos);
		if (pGraphVertexNode->m_StrName == vName)
		{
			j = i;
		}
		else {
			i++;
		}
	}
	return j;
}
void CUDGraph::ClearGraph()
{
	if (!m_UDGraphVertexContainer.IsEmpty())
	{
		m_UDGraphVertexContainer.RemoveAll();
		m_VertexNum = 0;
		m_VertexIndex = 0;
	}
	if (!m_UDGraphEdgeContainer.IsEmpty())
	{
		m_UDGraphEdgeContainer.RemoveAll();
		m_EdgeNum = 0;
	}
}
void CUDGraph::LoadUDGraph(FILE* vFileName)
{
	CGraphVertexNode* tPCurVertex = NULL;
	CGraphEdgeNode* tPGraphEdge = NULL;
	CGraphVertexNode* tPBeginVertex, *tPEndVertex;
	int tWeight;
	CPoint tPoint;
	// 清空原有图
	ClearGraph();
	// 首先读取图的顶点信息
	fread(&(m_VertexNum), sizeof(int), 1, vFileName);
	fread(&(m_VertexIndex), sizeof(int), 1, vFileName);
	for (int i = 0; i<m_VertexNum; i++) {
		tPCurVertex = new CGraphVertexNode;
		fread(&(tPCurVertex->m_Point), sizeof(CPoint), 1, vFileName);
		fread(&(tPCurVertex->m_Index), sizeof(int), 1, vFileName);
		m_UDGraphVertexContainer.AddTail(tPCurVertex);
	}
	// 读取边的信息
	fread(&(m_EdgeNum), sizeof(int), 1, vFileName);
	for (int i = 0; i<m_EdgeNum; i++) {
		tPGraphEdge = new CGraphEdgeNode;
		fread(&(tPoint), sizeof(CPoint), 1, vFileName);
		tPBeginVertex = IsPointInGraph(tPoint);
		fread(&(tPoint), sizeof(CPoint), 1, vFileName);
		tPEndVertex = IsPointInGraph(tPoint);
		fread(&(tWeight), sizeof(int), 1, vFileName);
		tPGraphEdge->m_Weight = tWeight;
		tPGraphEdge->m_pFromVertex = tPBeginVertex;
		tPGraphEdge->m_pFromNextEdge = tPBeginVertex->m_pFirstEdge;
		tPBeginVertex->m_pFirstEdge = tPGraphEdge;
		tPGraphEdge->m_pToVertex = tPEndVertex;
		tPGraphEdge->m_pToNextEdge = tPEndVertex->m_pFirstEdge;
		tPEndVertex->m_pFirstEdge = tPGraphEdge;
		m_UDGraphEdgeContainer.AddTail(tPGraphEdge);
	}
}
void CUDGraph::SaveUDGraph(FILE* vFileName)
{
	//int size = m_vertexs.size();
	POSITION tPos;
	CGraphVertexNode *tPGraphVertexNode;
	CGraphEdgeNode* tPGraphEdge = NULL;
	fwrite(&(m_VertexNum), sizeof(int), 1, vFileName);
	fwrite(&(m_VertexIndex), sizeof(int), 1, vFileName);
	// 保存无向图中所有顶点坐标
	for (tPos = m_UDGraphVertexContainer.GetHeadPosition(); tPos != NULL;)
	{
		tPGraphVertexNode =
			m_UDGraphVertexContainer.GetNext(tPos);
		fwrite(&(tPGraphVertexNode->m_Point),
			sizeof(CPoint), 1, vFileName);
		fwrite(&(tPGraphVertexNode->m_Index),
			sizeof(int), 1, vFileName);
	}
	// 保存无向图中所有边
	fwrite(&(m_EdgeNum), sizeof(int), 1, vFileName);
	for (tPos = m_UDGraphEdgeContainer.GetHeadPosition(); tPos != NULL;)
	{
		tPGraphEdge = m_UDGraphEdgeContainer.GetNext(tPos);
		fwrite(&(tPGraphEdge->m_pFromVertex->m_Point),
			sizeof(CPoint), 1, vFileName);
		fwrite(&(tPGraphEdge->m_pToVertex->m_Point),
			sizeof(CPoint), 1, vFileName);
		fwrite(&(tPGraphEdge->m_Weight),
			sizeof(int), 1, vFileName);
	}
}