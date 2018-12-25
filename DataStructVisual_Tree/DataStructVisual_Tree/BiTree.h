#pragma once
#include "math.h"
#include <afxtempl.h>
#include <afxwin.h>
#include <afxext.h>
#include "BiTreeNode.h"
#include <stack>
using namespace std;
class CBiTree
{
public:
	CBiTree();
	~CBiTree();
	void InsertBiTreeNode(CRect vWinRect,
		int vBTNValue);// 二叉树中插入关键字函数
	void InsertBiTreeNode(CBiTreeNode *(&vPBiTreeNode),
		CBiTreeNode * (&vPNewBTNode),
		int vBTNValue);//
	void DeleteBiTreeNode(CRect vWinRect,
		int vBTNValue);// 二叉树删除关键字函数
	void DeleteBiTreeNode(CBiTreeNode *vPBTRoot,
		int vBTNValue);// 重载二叉树删除关键字函数
	void SetNewPositions(CBiTreeNode* vPBiTree,
		int Xposition, int position);// 设置二叉树结点显示位置函数
	void SetBiTreeSearchKey(int vBTNValue);// 设置二叉树待查关键字函数
	void ReSizeTree();// 结点间距离计算函数
	CBiTreeNode * SearchBiTreeNode(CBiTreeNode *vPBTree,
		int vBTNValue);// 二叉树关键字查找函数
	void ChangeHeights(CBiTreeNode *(&vPBTRoot));// 计算二叉树结点高度
	int ResetWidths(CBiTreeNode * vPBTRoot); // 计算二叉树显示宽度
	void DrawBiTree(CRect vWinRect,
		CDC *pDC);// 绘制二叉树函数
	void DrawBiTree(CBiTreeNode* vPBiTreeNode,
		CDC *pDC);// 重载绘制二叉树函数
	void DrawBiTreeNode(CBiTreeNode* vPBiTreeNode,
		CDC *pDC);// 绘制二叉树结点函数
	void DrawBiTreeLine(CBiTreeNode* vPBiTreeNode,
		CDC *pDC);// 绘制二叉树分支函数
	void DrawSearchBiTreeNode(CDC *pDC);// 绘制二叉树查找结点函数
	void UnRecPreOrderTraverse(CBiTreeNode *vPBiTreeRoot);
	void UnRecInOrderTraverse(CBiTreeNode *vPBiTreeRoot);
	void UnRecPostOrderTraverse(CBiTreeNode *vPBiTreeRoot);
private:
	CBiTreeNode* m_pBiTreeRoot;// 二叉树根结点指针
	CRect m_WinSize;// 当前窗口尺寸
	int m_SearchValue;// 二叉树待查找值
	CTypedPtrList <CObList, CBiTreeNode*>
		m_BiTreeContainer;// 二叉树遍历存储容器
	int m_Visit;
};