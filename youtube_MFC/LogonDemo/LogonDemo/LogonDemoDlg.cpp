
// LogonDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "LogonDemo.h"
#include "LogonDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLogonDemoDlg ��ȭ ����




CLogonDemoDlg::CLogonDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogonDemoDlg::IDD, pParent)
	, m_strID(_T(""))
	, m_strPassword(_T(""))
	, m_bAuto(TRUE)
	, m_bUpdate(FALSE)
	, m_bSystem(FALSE)
	, m_strInput(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLogonDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Edit_ID, m_strID);
	DDX_Text(pDX, IDC_Edit_Password, m_strPassword);
	DDX_Check(pDX, IDC_Check_Auto, m_bAuto);
	DDX_Check(pDX, IDC_Check_Update, m_bUpdate);
	DDX_Check(pDX, IDC_Check_System, m_bSystem);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_Edit_Input, m_strInput);
}

BEGIN_MESSAGE_MAP(CLogonDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_Edit_ID, &CLogonDemoDlg::OnEnChangeEditId)
	ON_BN_CLICKED(IDOK, &CLogonDemoDlg::OnBnClickedOk)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK1, &CLogonDemoDlg::OnNMClickSyslink1)
	ON_BN_CLICKED(IDC_BUTTON1, &CLogonDemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_Check_Auto, &CLogonDemoDlg::OnBnClickedCheckAuto)
	ON_BN_CLICKED(IDC_Button_Insertstring, &CLogonDemoDlg::OnBnClickedButtonInsertstring)
	ON_BN_CLICKED(IDC_Button_Addstring, &CLogonDemoDlg::OnBnClickedButtonAddstring)
END_MESSAGE_MAP()


// CLogonDemoDlg �޽��� ó����

BOOL CLogonDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	// üũ�ڽ� ��Ȱ��ȭ
	GetDlgItem(IDC_Check_Update)->EnableWindow(FALSE);
	GetDlgItem(IDC_Check_System)->EnableWindow(FALSE);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CLogonDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CLogonDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CLogonDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLogonDemoDlg::OnEnChangeEditId()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CLogonDemoDlg::OnBnClickedOk()
{
	UpdateData(); // edit control�� �Էµ� �����͸� ����� ������ �Ҵ�����
	CString strTmp = _T("");
	strTmp.Format(_T("�Է��� ID�� \"%s\"�̸� ��ȣ�� \"%s\"�Դϴ�."),
					m_strID, m_strPassword);
	AfxMessageBox(strTmp);


	CDialogEx::OnOK();
}


void CLogonDemoDlg::OnNMClickSyslink1(NMHDR *pNMHDR, LRESULT *pResult)
{
	CString strUrl = _T("");
	CLinkCtrl* pLinkCtrl = (CLinkCtrl*)GetDlgItem(IDC_SYSLINK1);
	pLinkCtrl->GetItemUrl(0, strUrl);

	::ShellExecute(NULL, TEXT("open"), strUrl, NULL, NULL, SW_SHOW);

	*pResult = 0;
}


void CLogonDemoDlg::OnBnClickedButton1()
{
	m_bAuto = FALSE;
	m_bUpdate = TRUE;
	m_bSystem = TRUE;

	UpdateData(FALSE); // �Է°��� ������ �Ҵ�x �ݴ�� �������� �Է¶��� ����
}


void CLogonDemoDlg::OnBnClickedCheckAuto()
{
	UpdateData(); // ���� üũ�ڽ� ������ ������ ��ġ��Ŵ

	if (m_bAuto)
	{
		GetDlgItem(IDC_Check_Update)->EnableWindow(FALSE);
		GetDlgItem(IDC_Check_System)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_Check_Update)->EnableWindow(TRUE);
		GetDlgItem(IDC_Check_System)->EnableWindow(TRUE);
	}
}


void CLogonDemoDlg::OnBnClickedButtonInsertstring()
{
	UpdateData();
	m_List.InsertString(0, m_strInput);
	
	m_strInput = _T("");
	UpdateData(FALSE);
}


void CLogonDemoDlg::OnBnClickedButtonAddstring()
{
	UpdateData();
	m_List.AddString(m_strInput);
	
	m_strInput = _T("");
	UpdateData(FALSE);
}
