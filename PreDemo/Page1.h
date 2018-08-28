#pragma once
#include "MyDialog.h"
#include "MyHotKeyCtrl.h"


// CPage1 �Ի���

class CPage1 : public CMyDialog
{
	DECLARE_DYNAMIC(CPage1)

public:
	CPage1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage1();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	void SaveState();
	void RestoreState();
private:
	int m_nGameDelay;
	int m_nLoadQuantity;
	int m_nCounter;
	int m_nSchool;
	int m_nHeathLower;
    int m_nMagicLower;
    int m_nAlarm;
	BOOL m_bNotify;
	CMyHotKeyCtrl m_HotKeyStart;
	CMyHotKeyCtrl m_HotKeyPause;
	CMyHotKeyCtrl m_HotKeyClose;
    CMyHotKeyCtrl m_HotKeyScreenshot;
public:
	afx_msg void OnChange(UINT id);
	afx_msg void OnBnClickedButtonTest();   
};
