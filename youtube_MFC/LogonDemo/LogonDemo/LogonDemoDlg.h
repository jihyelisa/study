
// LogonDemoDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CLogonDemoDlg 대화 상자
class CLogonDemoDlg : public CDialogEx
{
// 생성입니다.
public:
	CLogonDemoDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_LOGONDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	// 로그온 ID
	CString m_strID;
	afx_msg void OnEnChangeEditId();
	// 로그온 Password
	CString m_strPassword;
	afx_msg void OnBnClickedOk();
	afx_msg void OnNMClickSyslink1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	BOOL m_bAuto;
	BOOL m_bUpdate;
	BOOL m_bSystem;
	afx_msg void OnBnClickedCheckAuto();
	CListBox m_List;
	CString m_strInput;
	afx_msg void OnBnClickedButtonInsertstring();
	afx_msg void OnBnClickedButtonAddstring();
	afx_msg void OnBnClickedButtondelete();
	afx_msg void OnBnClickedButtonFind();
	afx_msg void OnLbnSelchangeList1();
	CString m_str_selected;
	CSpinButtonCtrl m_spin;
	CProgressCtrl m_progress;
	afx_msg void OnUpdateEditValue();
};
