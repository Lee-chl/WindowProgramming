
// 05-03View.cpp: CMy0503View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "05-03.h"
#endif

#include "05-03Doc.h"
#include "05-03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0503View

IMPLEMENT_DYNCREATE(CMy0503View, CView)

BEGIN_MESSAGE_MAP(CMy0503View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy0503View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy0503View 생성/소멸

CMy0503View::CMy0503View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy0503View::~CMy0503View()
{
}

BOOL CMy0503View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy0503View 그리기

void CMy0503View::OnDraw(CDC* /*pDC*/)
{
	CMy0503Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CClientDC dc(this);
	CString strPoint;
	strPoint.Format(_T("마우스 좌표 (%4d, %4d"), m_Pos.x, m_Pos.y);
	dc.TextOutW(0, 0, strPoint);
}


// CMy0503View 인쇄


void CMy0503View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy0503View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy0503View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy0503View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy0503View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy0503View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy0503View 진단

#ifdef _DEBUG
void CMy0503View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0503View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0503Doc* CMy0503View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0503Doc)));
	return (CMy0503Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0503View 메시지 처리기


void CMy0503View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_Pos = point;
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}
