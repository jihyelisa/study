
// WorkerThreadDemo.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CWorkerThreadDemoApp:
// �� Ŭ������ ������ ���ؼ��� WorkerThreadDemo.cpp�� �����Ͻʽÿ�.
//

class CWorkerThreadDemoApp : public CWinApp
{
public:
	CWorkerThreadDemoApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CWorkerThreadDemoApp theApp;