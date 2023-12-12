
// MouseMsgView.cpp : CMouseMsgView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MouseMsg.h"
#endif

#include "MouseMsgDoc.h"
#include "MouseMsgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMouseMsgView

IMPLEMENT_DYNCREATE(CMouseMsgView, CView)

BEGIN_MESSAGE_MAP(CMouseMsgView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMouseMsgView ����/�Ҹ�

CMouseMsgView::CMouseMsgView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMouseMsgView::~CMouseMsgView()
{
}

BOOL CMouseMsgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMouseMsgView �׸���

void CMouseMsgView::OnDraw(CDC* /*pDC*/)
{
	CMouseMsgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMouseMsgView �μ�

BOOL CMouseMsgView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMouseMsgView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMouseMsgView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMouseMsgView ����

#ifdef _DEBUG
void CMouseMsgView::AssertValid() const
{
	CView::AssertValid();
}

void CMouseMsgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMouseMsgDoc* CMouseMsgView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMouseMsgDoc)));
	return (CMouseMsgDoc*)m_pDocument;
}
#endif //_DEBUG


// CMouseMsgView �޽��� ó����


void CMouseMsgView::OnMouseMove(UINT nFlags, CPoint point)
{
	m_ptMouse = point;
	RedrawWindow(); // ���ο��� onPaint�� ȣ��

	CView::OnMouseMove(nFlags, point);
}


void CMouseMsgView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CString strTmp = _T("");
	strTmp.Format(_T("%03d, %03d"), m_ptMouse.x, m_ptMouse.y);
	dc.TextOutW(10, 10, strTmp);
}


BOOL CMouseMsgView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	CString strTmp = _T("");
	strTmp.Format(TEXT("OnMouseWheel( ) zDelta : %d\n"), zDelta);
	TRACE(strTmp);

	return CView::OnMouseWheel(nFlags, zDelta, pt);
}


void CMouseMsgView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	AfxMessageBox(_T("TEST"));

	CView::OnLButtonDblClk(nFlags, point);
}
