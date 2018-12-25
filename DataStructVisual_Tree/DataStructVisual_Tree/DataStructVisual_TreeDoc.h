
// DataStructVisual_TreeDoc.h : CDataStructVisual_TreeDoc ��Ľӿ�
//


#pragma once
#include "BiTree.h"

class CDataStructVisual_TreeDoc : public CDocument
{
protected: // �������л�����
	CDataStructVisual_TreeDoc();
	DECLARE_DYNCREATE(CDataStructVisual_TreeDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CDataStructVisual_TreeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	CBiTree m_BiTree;
};
