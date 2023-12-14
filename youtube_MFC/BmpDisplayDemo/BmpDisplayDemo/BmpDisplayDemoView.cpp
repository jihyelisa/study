
// BmpDisplayDemoView.cpp : CBmpDisplayDemoView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CBmpDisplayDemoView 생성/소멸

CBmpDisplayDemoView::CBmpDisplayDemoView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CBmpDisplayDemoView::~CBmpDisplayDemoView()
{
}

BOOL CBmpDisplayDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CBmpDisplayDemoView 그리기

void CBmpDisplayDemoView::OnDraw(CDC* /*pDC*/)
{
	CBmpDisplayDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CBmpDisplayDemoView 인쇄

BOOL CBmpDisplayDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CBmpDisplayDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CBmpDisplayDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CBmpDisplayDemoView 진단

#ifdef _DEBUG
void CBmpDisplayDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CBmpDisplayDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBmpDisplayDemoDoc* CBmpDisplayDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBmpDisplayDemoDoc)));
	return (CBmpDisplayDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CBmpDisplayDemoView 메시지 처리기


void CBmpDisplayDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	//CDC MemDC;
	//BITMAP bmpInfo;

	//// 위의 화면 CPaintDC와 호환되는 메모리 DC 생성
	//MemDC.CreateCompatibleDC(&dc);

	//// 비트맵 리소스 로드
	//CBitmap bmp;
	//CBitmap* pOldBmp = NULL;
	//bmp.LoadBitmap(IDB_Test_Image);
	//
	//// 로드된 비트맵의 정보 가져옴
	//bmp.GetBitmap(&bmpInfo);

	//// 메모리 DC에 선택
	//pOldBmp = MemDC.SelectObject(&bmp);

	//// 메모리 DC에 들어있는 비트맵을 화면 DC로 복사하여 출력
	//dc.BitBlt(200, 200, 250, 300, &MemDC, 350, 200, SRCCOPY);


	// 로드할 이미지 경로
	CString strImagePath = _T("res/sample-image.jpg");

	// 이미지 파일 로드
	CImage image;
	HRESULT hResult = image.Load(strImagePath);
	if (FAILED(hResult))
	{
		CString strtmp = _T("ERROR: Failed to load ");
		strtmp += strImagePath + _T("\n");
		TRACE(strtmp);
		return;
	}

	CRect rect;
	GetClientRect(&rect);

	// 화면 DC에 출력
	// image.BitBlt(dc.m_hDC, 10, 10);
	image.StretchBlt(dc, 10, 10, 500, 700, SRCCOPY);
}
