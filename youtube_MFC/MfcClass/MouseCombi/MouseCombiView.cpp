
// MouseCombiView.cpp : CMouseCombiView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MouseCombi.h"
#endif

#include "MouseCombiDoc.h"
#include "MouseCombiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMouseCombiView

IMPLEMENT_DYNCREATE(CMouseCombiView, CView)

BEGIN_MESSAGE_MAP(CMouseCombiView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMouseCombiView ����/�Ҹ�

CMouseCombiView::CMouseCombiView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_ptItemText = CPoint(10, 30);
	m_bDragFlag = false;
}

CMouseCombiView::~CMouseCombiView()
{
}

BOOL CMouseCombiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMouseCombiView �׸���

void CMouseCombiView::OnDraw(CDC* /*pDC*/)
{
	CMouseCombiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMouseCombiView �μ�

BOOL CMouseCombiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMouseCombiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMouseCombiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMouseCombiView ����

#ifdef _DEBUG
void CMouseCombiView::AssertValid() const
{
	CView::AssertValid();
}

void CMouseCombiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMouseCombiDoc* CMouseCombiView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMouseCombiDoc)));
	return (CMouseCombiDoc*)m_pDocument;
}
#endif //_DEBUG


// CMouseCombiView �޽��� ó����


void CMouseCombiView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (point.x >= m_ptItemText.x - 32 && point.x <= m_ptItemText.x + 32 &&
		point.y >= m_ptItemText.y - 32 && point.y <= m_ptItemText.y + 32)
	{
		m_bDragFlag = true;
		RedrawWindow();
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMouseCombiView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_bDragFlag)
	{
		m_bDragFlag = false;
		m_ptItemText = point;
		RedrawWindow();
		ReleaseCapture(); // ȭ�� �����ε� �巡�� �����ϵ��� ��
	}

	CView::OnLButtonUp(nFlags, point);
}


void CMouseCombiView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CView::OnLButtonDblClk(nFlags, point);
}


void CMouseCombiView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	if (m_bDragFlag)
		dc.TextOut(10, 10, _T("DRAG"));
	else
		dc.TextOut(10, 10, _T("----"));

	dc.TextOut(m_ptItemText.x, m_ptItemText.y, _T("�� ��ǻ��"));
}


void CMouseCombiView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_bDragFlag)
	{
		if (point.x >= 0 && point.y >= 0)
		{
			m_ptItemText = point;
			RedrawWindow();
		}
		else
			m_bDragFlag = false;
	}

	CView::OnMouseMove(nFlags, point);
}


int CMouseCombiView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_wndTrack.Create(_T("STATIC"), _T("TRACK TEST"),
					WS_CHILD | WS_VISIBLE | WS_BORDER | SS_NOTIFY,
					CRect(100, 10, 250, 160), this, 1234);

	return 0;
}
