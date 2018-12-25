#pragma once
#include "afx.h"
class CBiTreeNode :
	public CObject
{
public:
	CBiTreeNode();
	~CBiTreeNode();
	bool DrawBiTreeNode(CDC* pDC);// 绘制二叉树结点
	void DrawSearchBITreeNode(int vBiTreeKey, CDC* pDC);// 绘制 查找结点
public:
	CPoint m_Point;// 二叉树结点坐标位置
	COLORREF m_Color; // 二叉树结点颜色
	CString m_StrName; // 二叉树结点名称
	int m_Value;// 二叉树结点值
	BOOL m_Visit;// 二叉树结点是否访问
	CPoint m_DisplayPoint;// 二叉树新的显示位置
						  // 二叉树结点左右孩子指针和父结点指针
	CBiTreeNode *m_pLChild, *m_pRChild, *m_pParent;
	int m_Leftwidth;//二叉树左子树宽度
	int m_Rightwidth;// 二叉树右子树宽度
};