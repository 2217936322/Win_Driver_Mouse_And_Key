#pragma once
#include "MyDialog.h"


// CPage4 �Ի���

class CPage4 : public CMyDialog
{
	DECLARE_DYNAMIC(CPage4)

public:
	CPage4(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage4();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	void SaveState();
	void RestoreState();
private:
	int m_nIncense;					//����������
	int m_nGrass;					//��ڤ������
	int m_nMagicDrug;				//��ҩ����
	int m_nRound;					//�غ�������
	int m_MagicDrugType;		    //��ҩ����
	int m_nIsDoWork;		        //�Ƿ��Զ�����
	int m_nAfterComplete;	        //ץ���֮����
	int m_nIsCatchSpecial;          //����������
public:
	afx_msg void OnChange(UINT id);
};
