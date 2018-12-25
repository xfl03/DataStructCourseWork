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
		int vBTNValue);// �������в���ؼ��ֺ���
	void InsertBiTreeNode(CBiTreeNode *(&vPBiTreeNode),
		CBiTreeNode * (&vPNewBTNode),
		int vBTNValue);//
	void DeleteBiTreeNode(CRect vWinRect,
		int vBTNValue);// ������ɾ���ؼ��ֺ���
	void DeleteBiTreeNode(CBiTreeNode *vPBTRoot,
		int vBTNValue);// ���ض�����ɾ���ؼ��ֺ���
	void SetNewPositions(CBiTreeNode* vPBiTree,
		int Xposition, int position);// ���ö����������ʾλ�ú���
	void SetBiTreeSearchKey(int vBTNValue);// ���ö���������ؼ��ֺ���
	void ReSizeTree();// ���������㺯��
	CBiTreeNode * SearchBiTreeNode(CBiTreeNode *vPBTree,
		int vBTNValue);// �������ؼ��ֲ��Һ���
	void ChangeHeights(CBiTreeNode *(&vPBTRoot));// ������������߶�
	int ResetWidths(CBiTreeNode * vPBTRoot); // �����������ʾ���
	void DrawBiTree(CRect vWinRect,
		CDC *pDC);// ���ƶ���������
	void DrawBiTree(CBiTreeNode* vPBiTreeNode,
		CDC *pDC);// ���ػ��ƶ���������
	void DrawBiTreeNode(CBiTreeNode* vPBiTreeNode,
		CDC *pDC);// ���ƶ�������㺯��
	void DrawBiTreeLine(CBiTreeNode* vPBiTreeNode,
		CDC *pDC);// ���ƶ�������֧����
	void DrawSearchBiTreeNode(CDC *pDC);// ���ƶ��������ҽ�㺯��
	void UnRecPreOrderTraverse(CBiTreeNode *vPBiTreeRoot);
	void UnRecInOrderTraverse(CBiTreeNode *vPBiTreeRoot);
	void UnRecPostOrderTraverse(CBiTreeNode *vPBiTreeRoot);
private:
	CBiTreeNode* m_pBiTreeRoot;// �����������ָ��
	CRect m_WinSize;// ��ǰ���ڳߴ�
	int m_SearchValue;// ������������ֵ
	CTypedPtrList <CObList, CBiTreeNode*>
		m_BiTreeContainer;// �����������洢����
	int m_Visit;
};