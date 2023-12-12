
// KeyMoveView.cpp : CKeyMoveView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "KeyMove.h"
#endif

#include "KeyMoveDoc.h"
#include "KeyMoveView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKeyMoveView

IMPLEMENT_DYNCREATE(CKeyMoveView, CView)

BEGIN_MESSAGE_MAP(CKeyMoveView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_SYSKEYDOWN()
END_MESSAGE_MAP()

// CKeyMoveView ����/�Ҹ�

CKeyMoveView::CKeyMoveView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CKeyMoveView::~CKeyMoveView()
{
}

BOOL CKeyMoveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CKeyMoveView �׸���

void CKeyMoveView::OnDraw(CDC* /*pDC*/)
{
	CKeyMoveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CKeyMoveView �μ�

BOOL CKeyMoveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CKeyMoveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CKeyMoveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CKeyMoveView ����

#ifdef _DEBUG
void CKeyMoveView::AssertValid() const
{
	CView::AssertValid();
}

void CKeyMoveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKeyMoveDoc* CKeyMoveView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKeyMoveDoc)));
	return (CKeyMoveDoc*)m_pDocument;
}
#endif //_DEBUG


// CKeyMoveView �޽��� ó����


int CKeyMoveView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_wndChild.Create(_T("STATIC"), _T("KeyMove"),
						WS_CHILD | WS_VISIBLE | WS_BORDER,
						CRect(100, 100, 200, 200), this, 1234);

	return 0;
}


void CKeyMoveView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CPoint ptChild; // ���ϵ� ������ ��ǥ
	CRect Rect; // ���ϵ� ������ ��ǥ �� ũ��

	// ���ϵ� �������� ��ũ�� ���� ���� ���, ������ �ϴ� ��ǥ ������
	m_wndChild.GetWindowRect(&Rect);
	ptChild.x = Rect.left;
	ptChild.y = Rect.top;

	// ��ũ�� ���� ��ǥ�� Ŭ���̾�Ʈ �� ���� ��ǥ�� ȯ��
	ScreenToClient(&ptChild);

	// �� ���� ������ ����
	int moveArrange = 10;

	if (::GetKeyState(VK_CONTROL) & 0x8000)
		moveArrange = 100;

	switch (nChar) // ���� Ű ������ ��� ����
	{
	case VK_LEFT: // ���� ȭ��ǥ ����
		ptChild.x -= moveArrange; // x��ǥ 10�ȼ� ����
		break;

	case VK_RIGHT:
		ptChild.x += moveArrange;
		break;

	case VK_UP:
		m_wndChild.SetWindowPos(&CWnd::wndTop, ptChild.x, ptChild.y, Rect.Width() + 10, Rect.Height() + 10,
								SWP_SHOWWINDOW | SWP_NOZORDER);
		break;

	case VK_DOWN:
		m_wndChild.SetWindowPos(&CWnd::wndTop, ptChild.x, ptChild.y, Rect.Width() - 10, Rect.Height() - 10,
								SWP_SHOWWINDOW | SWP_NOZORDER);
		break;
	}

	m_wndChild.SetWindowPos(&CWnd::wndTop, ptChild.x, ptChild.y, 0, 0,
			SWP_SHOWWINDOW | SWP_NOZORDER | SWP_NOSIZE);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CKeyMoveView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) // ���� �Է� �� ȣ��
{
	CString strTmp = _T("");
	strTmp.Format(_T("%c"), nChar);
	m_wndChild.SetWindowTextW(strTmp);

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CKeyMoveView::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString strMessage = TEXT("");

	WORD wResult = ::GetKeyState(VK_SPACE);
	BYTE byHigh = HIBYTE(wResult);
	if (byHigh & 0x01)
	{
		strMessage += TEXT("Alt + Space, ");
		wResult = ::GetKeyState(VK_CAPITAL);
		BYTE byLow = LOBYTE(wResult); // ���� ����Ʈ�� 1�� ��Ʈ�� 1�̸� ��� Ű�� ���� ����
		if (byLow & 0x01) strMessage += TEXT("CAPS LOCK ON");
		else strMessage += TEXT("CAPS LOCK OFF");

		AfxMessageBox(strMessage);
	}

	CView::OnSysKeyDown(nChar, nRepCnt, nFlags);
}
