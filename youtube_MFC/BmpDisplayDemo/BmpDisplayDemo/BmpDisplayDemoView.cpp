
// BmpDisplayDemoView.cpp : CBmpDisplayDemoView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "BmpDisplayDemo.h"
#endif

#include "BmpDisplayDemoDoc.h"
#include "BmpDisplayDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBmpDisplayDemoView

IMPLEMENT_DYNCREATE(CBmpDisplayDemoView, CView)

BEGIN_MESSAGE_MAP(CBmpDisplayDemoView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CBmpDisplayDemoView ����/�Ҹ�

CBmpDisplayDemoView::CBmpDisplayDemoView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CBmpDisplayDemoView::~CBmpDisplayDemoView()
{
}

BOOL CBmpDisplayDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CBmpDisplayDemoView �׸���

void CBmpDisplayDemoView::OnDraw(CDC* /*pDC*/)
{
	CBmpDisplayDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CBmpDisplayDemoView �μ�

BOOL CBmpDisplayDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CBmpDisplayDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CBmpDisplayDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CBmpDisplayDemoView ����

#ifdef _DEBUG
void CBmpDisplayDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CBmpDisplayDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBmpDisplayDemoDoc* CBmpDisplayDemoView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBmpDisplayDemoDoc)));
	return (CBmpDisplayDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CBmpDisplayDemoView �޽��� ó����


void CBmpDisplayDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// �ε��� �̹��� ���
	CString strImagePath = _T("sample-image.jpg");

	// �̹��� ���� �ε�
	CImage Image;
	HRESULT hResult = Image.Load(strImagePath);
	if (FAILED(hResult))
	{
		CString strtmp = _T("ERROR: Failed to load");
		strtmp += strImagePath + _T("\n");
		TRACE(strtmp);
		return;
	}

	// ȭ�� DC�� ���
	Image.BitBlt(dc.m_hDC, 0, 0);
}
