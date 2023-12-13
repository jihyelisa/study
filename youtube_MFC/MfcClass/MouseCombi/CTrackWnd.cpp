#include "StdAfx.h"
#include "CTrackWnd.h"
BEGIN_MESSAGE_MAP(CTrackWnd, CWnd)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()

CTrackWnd::CTrackWnd()
{
	m_bTrack = FALSE;
}

void CTrackWnd::OnMouseMove(UINT nFlags, CPoint point)
{
	if (!m_bTrack)
	{
		TRACKMOUSEEVENT tme = { 0 };
		tme.cbSize = sizeof(tme);
		tme.dwFlags = TME_LEAVE;
		tme.hwndTrack = m_hWnd;
		tme.dwHoverTime = 0;

		m_bTrack = ::_TrackMouseEvent(&tme);

		if (m_bTrack)
			SetWindowText(_T("Tracking"));
	}

	CWnd::OnMouseMove(nFlags, point);
}


void CTrackWnd::OnMouseLeave()
{
	SetWindowText(_T("TRACK TEST"));

	CWnd::OnMouseLeave();
}
