
// KeyMoveView.cpp : CKeyMoveView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_SYSKEYDOWN()
END_MESSAGE_MAP()

// CKeyMoveView 생성/소멸

CKeyMoveView::CKeyMoveView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CKeyMoveView::~CKeyMoveView()
{
}

BOOL CKeyMoveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CKeyMoveView 그리기

void CKeyMoveView::OnDraw(CDC* /*pDC*/)
{
	CKeyMoveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CKeyMoveView 인쇄

BOOL CKeyMoveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CKeyMoveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CKeyMoveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CKeyMoveView 진단

#ifdef _DEBUG
void CKeyMoveView::AssertValid() const
{
	CView::AssertValid();
}

void CKeyMoveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKeyMoveDoc* CKeyMoveView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKeyMoveDoc)));
	return (CKeyMoveDoc*)m_pDocument;
}
#endif //_DEBUG


// CKeyMoveView 메시지 처리기


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
	CPoint ptChild; // 차일드 윈도우 좌표
	CRect Rect; // 차일드 윈도우 좌표 및 크기

	// 차일드 윈도우의 스크린 기준 왼쪽 상단, 오른쪽 하단 좌표 가져옴
	m_wndChild.GetWindowRect(&Rect);
	ptChild.x = Rect.left;
	ptChild.y = Rect.top;

	// 스크린 기준 좌표를 클라이언트 뷰 기준 좌표로 환산
	ScreenToClient(&ptChild);

	// 한 번에 움직일 범위
	int moveArrange = 10;

	if (::GetKeyState(VK_CONTROL) & 0x8000)
		moveArrange = 100;

	switch (nChar) // 누른 키 정보가 들어 있음
	{
	case VK_LEFT: // 왼쪽 화살표 누름
		ptChild.x -= moveArrange; // x좌표 10픽셀 감소
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


void CKeyMoveView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) // 문자 입력 시 호출
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
		BYTE byLow = LOBYTE(wResult); // 하위 바이트의 1번 비트가 1이면 토글 키가 켜진 상태
		if (byLow & 0x01) strMessage += TEXT("CAPS LOCK ON");
		else strMessage += TEXT("CAPS LOCK OFF");

		AfxMessageBox(strMessage);
	}

	CView::OnSysKeyDown(nChar, nRepCnt, nFlags);
}
