// PreDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPreDemoApp:
// �йش����ʵ�֣������ PreDemo.cpp
//

class CPreDemoApp : public CWinApp
{
public:
	CPreDemoApp();
    ~CPreDemoApp();
	HBITMAP  m_hBitmap;
	BOOL     m_bLoadDriver;
    BOOL     m_bShutDown;
	HANDLE   m_Mutex;
	PCTSTR   m_AppDirectory;

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
public:
    void SetShutDown(BOOL bflag) {m_bShutDown = bflag;}
};

extern CPreDemoApp theApp;