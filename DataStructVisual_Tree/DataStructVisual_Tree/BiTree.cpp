#include "stdafx.h"
#include "BiTree.h"


CBiTree::CBiTree()
{
	m_pBiTreeRoot = NULL;
}
CBiTree::~CBiTree()
{
}
void CBiTree::DrawBiTree(CRect vWinRect, CDC *pDC)
{
	if (m_pBiTreeRoot) {
		DrawBiTree(m_pBiTreeRoot, pDC);
	}
}
void CBiTree::DrawBiTree(CBiTreeNode* vPBiTreeNode, CDC *pDC)
{
	DrawBiTreeLine(vPBiTreeNode, pDC);
	DrawBiTreeNode(vPBiTreeNode, pDC);
}
void CBiTree::DrawBiTreeNode(CBiTreeNode* vPBiTreeNode, CDC *pDC)
{
	vPBiTreeNode->DrawBiTreeNode(pDC);
	if (vPBiTreeNode->m_pLChild)
	{
		DrawBiTreeNode(vPBiTreeNode->m_pLChild, pDC);
	}
	if (vPBiTreeNode->m_pRChild)
	{
		DrawBiTreeNode(vPBiTreeNode->m_pRChild, pDC);
	}
}
void CBiTree::DrawBiTreeLine(CBiTreeNode* vPBiTreeNode, CDC *pDC)
{
	if (vPBiTreeNode->m_pLChild)
	{
		pDC->MoveTo(vPBiTreeNode->m_Point);
		pDC->LineTo(vPBiTreeNode->m_pLChild->m_Point);
		DrawBiTreeLine(vPBiTreeNode->m_pLChild, pDC);
	}
	if (vPBiTreeNode->m_pRChild)
	{
		pDC->MoveTo(vPBiTreeNode->m_Point);
		pDC->LineTo(vPBiTreeNode->m_pRChild->m_Point);
		DrawBiTreeLine(vPBiTreeNode->m_pRChild, pDC);
	}
}
void CBiTree::InsertBiTreeNode(CRect vWinRect, int vBTNValue)
{
	m_WinSize = vWinRect;
	CString tStr;
	tStr.Format(_T("%d"), vBTNValue);
	if (!m_pBiTreeRoot) {
		CPoint tCurPoint;
		m_pBiTreeRoot = new CBiTreeNode();
		m_pBiTreeRoot->m_Visit = FALSE;
		m_pBiTreeRoot->m_StrName = tStr;
		m_pBiTreeRoot->m_Value = vBTNValue;
		m_pBiTreeRoot->m_pLChild = NULL;
		m_pBiTreeRoot->m_pRChild = NULL;
		m_pBiTreeRoot->m_pParent = NULL;
		tCurPoint.x = vWinRect.right / 2;
		tCurPoint.y = vWinRect.top + 30;
		m_pBiTreeRoot->m_Point = tCurPoint;
	}
	else {
		CBiTreeNode *tPCurBTNode = new CBiTreeNode;
		tPCurBTNode->m_Visit = FALSE;
		tPCurBTNode->m_StrName = tStr;
		tPCurBTNode->m_Value = vBTNValue;
		tPCurBTNode->m_pLChild = NULL;
		tPCurBTNode->m_pRChild = NULL;
		tPCurBTNode->m_pParent = NULL;
		InsertBiTreeNode(m_pBiTreeRoot, tPCurBTNode, vBTNValue);
	}
}
void CBiTree::InsertBiTreeNode(CBiTreeNode *(&vPBTRoot),
	CBiTreeNode * (&vPCurBTNode), int vBTNValue)
{
	CPoint tCurPoint;
	if (vPBTRoot->m_Value>vBTNValue) {
		if (!vPBTRoot->m_pLChild) {
			tCurPoint.x = vPBTRoot->m_Point.x - 25;
			tCurPoint.y = vPBTRoot->m_Point.y + 50;
			vPCurBTNode->m_Point = tCurPoint;
			vPBTRoot->m_pLChild = vPCurBTNode;
			vPCurBTNode->m_pParent = vPBTRoot;
			ReSizeTree();
		}
		else {
			InsertBiTreeNode(vPBTRoot->m_pLChild,
				vPCurBTNode, vBTNValue);
		}
	}
	else {
		if (!vPBTRoot->m_pRChild) {
			tCurPoint.x = vPBTRoot->m_Point.x + 25;
			tCurPoint.y = vPBTRoot->m_Point.y + 50;
			vPCurBTNode->m_Point = tCurPoint;
			vPBTRoot->m_pRChild = vPCurBTNode;
			vPCurBTNode->m_pParent = vPBTRoot;
			ReSizeTree();
		}
		else {
			InsertBiTreeNode(vPBTRoot->m_pRChild,
				vPCurBTNode, vBTNValue);
		}
	}
}
void CBiTree::ReSizeTree()
{
	int tStartingPoint = m_WinSize.right / 2;
	ResetWidths(m_pBiTreeRoot);
	SetNewPositions(m_pBiTreeRoot, tStartingPoint, 0);
}
int CBiTree::ResetWidths(CBiTreeNode * vPBTRoot)
{
	if (!vPBTRoot)
		return 0;
	vPBTRoot->m_Leftwidth = max(ResetWidths(vPBTRoot->m_pLChild), 25);
	vPBTRoot->m_Rightwidth = max(ResetWidths(vPBTRoot->m_pRChild), 25);
	return vPBTRoot->m_Leftwidth + vPBTRoot->m_Rightwidth;
}
void CBiTree::SetNewPositions(CBiTreeNode* vPBTRoot,
	int vXPosition, int vPosition)
{
	if (vPBTRoot) {
		if (vPosition == -1) {
			vXPosition = vXPosition - vPBTRoot->m_Rightwidth;
		}
		else if (vPosition == 1) {
			vXPosition = vXPosition + vPBTRoot->m_Leftwidth;
		}
		vPBTRoot->m_Point.x = vXPosition;
		if (vPBTRoot->m_Point.y<0)
			vPBTRoot->m_DisplayPoint.y = vPBTRoot->m_Point.y;
		SetNewPositions(vPBTRoot->m_pLChild, vXPosition, -1);
		SetNewPositions(vPBTRoot->m_pRChild, vXPosition, 1);
	}
}void CBiTree::DeleteBiTreeNode(CRect vWinRect, int vBTNValue)
{
	m_WinSize = vWinRect;
	DeleteBiTreeNode(m_pBiTreeRoot, vBTNValue);
}
void CBiTree::DeleteBiTreeNode(CBiTreeNode *vPBTRoot, int vBTNValue)
{
	boolean tLeftChild = false;
	if (vPBTRoot)
	{
		if (vPBTRoot->m_pParent)
			tLeftChild = vPBTRoot->m_pParent->m_pLChild == vPBTRoot;
		if (vBTNValue == vPBTRoot->m_Value) {
			if ((!vPBTRoot->m_pLChild) && (!vPBTRoot->m_pRChild))
			{// 情况 1 ：左右子树均空
				if (vPBTRoot->m_pParent) {
					if (tLeftChild) {
						vPBTRoot->m_pParent->m_pLChild = NULL;
					}
					else {
						vPBTRoot->m_pParent->m_pRChild = NULL;
					}
				}
				else {
					m_pBiTreeRoot = NULL;
				}
				ReSizeTree();
			}
			else if (!vPBTRoot->m_pLChild) {// 情况 2 ：左子树为空
				if (vPBTRoot->m_pParent) {
					if (tLeftChild) {
						vPBTRoot->m_pParent->m_pLChild
							= vPBTRoot->m_pRChild;
						vPBTRoot->m_pRChild->m_pParent
							= vPBTRoot->m_pParent;
					}
					else {
						vPBTRoot->m_pParent->m_pRChild
							= vPBTRoot->m_pRChild;
						vPBTRoot->m_pRChild->m_pParent
							= vPBTRoot->m_pParent;
					}
				}
				else {
					m_pBiTreeRoot = vPBTRoot->m_pRChild;
					vPBTRoot->m_pRChild->m_pParent = NULL;
				}
				ChangeHeights(vPBTRoot->m_pRChild);
				ReSizeTree();
			}
			else if (!vPBTRoot->m_pRChild) {// 情况 3 ：右子树为空
				if (vPBTRoot->m_pParent) {
					if (tLeftChild) {
						vPBTRoot->m_pParent->m_pLChild
							= vPBTRoot->m_pLChild;
						vPBTRoot->m_pLChild->m_pParent
							= vPBTRoot->m_pParent;
					}
					else {
						vPBTRoot->m_pParent->m_pRChild
							= vPBTRoot->m_pLChild;
						vPBTRoot->m_pLChild->m_pParent
							= vPBTRoot->m_pParent;
					}
				}
				else {
					m_pBiTreeRoot = vPBTRoot->m_pLChild;
					vPBTRoot->m_pLChild->m_pParent = NULL;
				}
				ChangeHeights(vPBTRoot->m_pLChild);
				ReSizeTree();
			}
			else {// 情况 4 ：左右子树均不空
				CBiTreeNode * tCurBitreeNode = new CBiTreeNode;
				tCurBitreeNode = vPBTRoot;
				tCurBitreeNode = vPBTRoot->m_pLChild;
				while (tCurBitreeNode->m_pRChild) {
					tCurBitreeNode = tCurBitreeNode->m_pRChild;
				}
				vPBTRoot->m_Value = tCurBitreeNode->m_Value;
				DeleteBiTreeNode(tCurBitreeNode,
					tCurBitreeNode->m_Value);
				delete tCurBitreeNode;
			}
		}
		else if (vBTNValue<vPBTRoot->m_Value)
		{
			DeleteBiTreeNode(vPBTRoot->m_pLChild, vBTNValue);
		}
		else
		{
			DeleteBiTreeNode(vPBTRoot->m_pRChild, vBTNValue);
		}
	}
}
void CBiTree::ChangeHeights(CBiTreeNode *(&vPBTRoot))
{
	if (vPBTRoot) {
		vPBTRoot->m_Point.y = vPBTRoot->m_Point.y - 50;
		ChangeHeights(vPBTRoot->m_pLChild);
		ChangeHeights(vPBTRoot->m_pRChild);
	}
}
CBiTreeNode * CBiTree::SearchBiTreeNode(CBiTreeNode *vPBTRoot,
	int vBTNValue)
{
	if (!vPBTRoot)
		return NULL;
	if (vPBTRoot->m_Value == vBTNValue)
		return vPBTRoot;
	else {
		if (vBTNValue <vPBTRoot->m_Value) {
			return SearchBiTreeNode(vPBTRoot->m_pLChild, vBTNValue);
		}
		else {
			return SearchBiTreeNode(vPBTRoot->m_pRChild, vBTNValue);
		}
	}
}
void CBiTree::SetBiTreeSearchKey(int vBTNValue)
{
	m_SearchValue = vBTNValue;
}
void CBiTree::DrawSearchBiTreeNode(CDC *pDC)
{
	CBiTreeNode* tPBTNode = SearchBiTreeNode(m_pBiTreeRoot,
		m_SearchValue);
	if (tPBTNode) {
		tPBTNode->DrawSearchBITreeNode(m_SearchValue, pDC);
	}
	else {
		::AfxMessageBox(_T(" 查找结点不存在."));
	}
}
void CBiTree::UnRecPreOrderTraverse(CBiTreeNode *vPBiTreeRoot)
{
	stack<CBiTreeNode*> tSeqStack;// 建立栈
	CBiTreeNode *tPCurBiTreeNode = vPBiTreeRoot;
	while (tPCurBiTreeNode != NULL || !tSeqStack.empty())
	{
		while (tPCurBiTreeNode != NULL) // 遍历左子树
		{
			//visite(tPCurBiTreeNode->m_Data);// 访问结点
			tSeqStack.push(tPCurBiTreeNode);
			tPCurBiTreeNode = tPCurBiTreeNode->m_pLChild;
		}
		if (!tSeqStack.empty())// 实现右子树遍历
		{
			tPCurBiTreeNode = tSeqStack.top();
			tSeqStack.pop();
			tPCurBiTreeNode = tPCurBiTreeNode->m_pRChild;
		}
	}
}
void CBiTree::UnRecInOrderTraverse(CBiTreeNode *vPBiTreeRoot)
{
	stack<CBiTreeNode*> tSeqStack;// 建立栈
	while (!tSeqStack.empty())// 清空栈
	{
		tSeqStack.pop();
	}
	CBiTreeNode *tPCurBiTreeNode = vPBiTreeRoot;
	do
	{
		while (tPCurBiTreeNode != NULL)// 遍历左子树
		{
			tSeqStack.push(tPCurBiTreeNode);
			tPCurBiTreeNode = tPCurBiTreeNode->m_pLChild;
		}if (!tSeqStack.empty())// 栈不空
		{
			tPCurBiTreeNode = tSeqStack.top();
			tSeqStack.pop();
			// visite(tPCurBiTreeNode->m_Value);// 访问结点
			tPCurBiTreeNode = tPCurBiTreeNode->m_pRChild;
		}
	} while (tPCurBiTreeNode != NULL || !tSeqStack.empty());
}
void CBiTree::UnRecPostOrderTraverse(CBiTreeNode *vPBiTreeRoot)
{
	stack<CBiTreeNode*> tSeqStack;// 建立栈
	while (!tSeqStack.empty())// 清空栈
	{
		tSeqStack.pop();
	}
	CBiTreeNode *tPCurBiTreeNode = vPBiTreeRoot;
	do
	{
		while (tPCurBiTreeNode != NULL) // 遍历左子树
		{
			tPCurBiTreeNode->m_Visit = 0;
			tSeqStack.push(tPCurBiTreeNode);
			tPCurBiTreeNode = tPCurBiTreeNode->m_pLChild;
		}
		if (!tSeqStack.empty())// 右子树遍历
		{
			tPCurBiTreeNode = tSeqStack.top();
			if (tPCurBiTreeNode->m_Visit == 1)
			{
				//visite(tPCurBiTreeNode->m_Value);// 访问结点
				tSeqStack.pop();
			}
			else
			{
				// tPTempBiTreeNode->m_Visit=1;
				tPCurBiTreeNode = tPCurBiTreeNode->m_pRChild;
			}
		}
	} while (tPCurBiTreeNode != NULL || !tSeqStack.empty());
}