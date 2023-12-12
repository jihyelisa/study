
// MouseCombiView.h : CMouseCombiView Ŭ������ �������̽�
//

#pragma once


class CMouseCombiView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMouseCombiView();
	DECLARE_DYNCREATE(CMouseCombiView)

// Ư���Դϴ�.
public:
	CMouseCombiDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMouseCombiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MouseCombiView.cpp�� ����� ����
inline CMouseCombiDoc* CMouseCombiView::GetDocument() const
   { return reinterpret_cast<CMouseCombiDoc*>(m_pDocument); }
#endif

