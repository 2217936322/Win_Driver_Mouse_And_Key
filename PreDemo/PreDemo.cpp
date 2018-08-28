// PreDemo.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "PreDemo.h"
#include "PreDemoDlg.h"
#include "GameState.h"
#include "km.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPreDemoApp

BEGIN_MESSAGE_MAP(CPreDemoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CPreDemoApp ����

CPreDemoApp::CPreDemoApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
    srand(GetTickCount());
    m_bShutDown   = FALSE;
    m_bLoadDriver = FALSE;
    m_hBitmap     = NULL;
}

//��������
CPreDemoApp::~CPreDemoApp()
{
    if (m_bShutDown)
        ShutDown(EWX_SHUTDOWN);
}


// Ψһ��һ�� CPreDemoApp ����

CPreDemoApp theApp;

// CPreDemoApp ��ʼ��

BOOL CPreDemoApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	//SetRegistryKey(_T("ASSoft"));
	_tsetlocale(0,_T(""));

	// ���ƶ࿪
	m_Mutex = ::OpenMutex(MUTEX_ALL_ACCESS, FALSE, m_pszAppName);
	if (m_Mutex == NULL)
	{
		m_Mutex = CreateMutex(NULL, TRUE, m_pszAppName);
	}
	else
	{
		AfxMessageBox(_T("�����Ѿ����У�"));
		return FALSE;
	}


	CString strAppDirectory(m_pszHelpFilePath);
	strAppDirectory = strAppDirectory.Left(strAppDirectory.ReverseFind('\\') + 1);

	CImage image;
	if (image.Load(_T("Background.jpg")) != E_FAIL)
		m_hBitmap = image.Detach();

	m_pszProfileName = _tcsdup(strAppDirectory + m_pszAppName + _T(".ini"));
	m_AppDirectory   = _tcsdup(strAppDirectory);

	//��������
	m_bLoadDriver = ManageDriver(KEYMOUSE_DRIVER_NAME, DRIVER_FUNC_INSTALL);
	if (!m_bLoadDriver)
	{
		AfxMessageBox(_T("��������ʧ��!"));
#ifndef _DEBUG
		return FALSE;
#endif //  _DEBUG
	}

	CPreDemoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

int CPreDemoApp::ExitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
	if (m_Mutex)
		ReleaseMutex(m_Mutex);
	if (m_bLoadDriver)
		ManageDriver(KEYMOUSE_DRIVER_NAME, DRIVER_FUNC_REMOVE);

	free((PVOID)m_AppDirectory);

	return CWinApp::ExitInstance();
}
