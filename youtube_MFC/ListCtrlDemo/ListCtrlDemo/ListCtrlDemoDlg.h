
// ListCtrlDemoDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CListCtrlDemoDlg ��ȭ ����
class CListCtrlDemoDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CListCtrlDemoDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LISTCTRLDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CImageList m_ImageList;
	CListCtrl m_List;
};
