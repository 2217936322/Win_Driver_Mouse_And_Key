#pragma once
#include "MyDialog.h"


// CPage3 �Ի���

class CPage3 : public CMyDialog
{
	DECLARE_DYNAMIC(CPage3)

public:
	CPage3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage3();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	void SaveState();
	void RestoreState();
private:
	CString m_strPos[11];
public:
	afx_msg void OnChange(UINT id);
};
