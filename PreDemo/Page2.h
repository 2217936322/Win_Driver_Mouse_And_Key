#pragma once
#include "MyDialog.h"


// CPage2 �Ի���

class CPage2 : public CMyDialog
{
	DECLARE_DYNAMIC(CPage2)

public:
	CPage2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage2();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	void SaveState();
	void RestoreState();
private:
	int     m_nMonster[10];
	UINT    m_Price[10];
public:
	afx_msg void OnChange(UINT id);
};
