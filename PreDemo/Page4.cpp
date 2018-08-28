// Page4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PreDemo.h"
#include "Page4.h"


// CPage4 �Ի���

IMPLEMENT_DYNAMIC(CPage4, CMyDialog)

CPage4::CPage4(CWnd* pParent /*=NULL*/)
	: CMyDialog(CPage4::IDD, pParent)
{
}

CPage4::~CPage4()
{
}

void CPage4::DoDataExchange(CDataExchange* pDX)
{
	CMyDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nIncense);
	DDX_Text(pDX, IDC_EDIT2, m_nGrass);
	DDX_Text(pDX, IDC_EDIT3, m_nMagicDrug);
	DDX_Text(pDX, IDC_EDIT4, m_nRound);
	DDX_CBIndex(pDX, IDC_COMBO1, m_MagicDrugType);
	DDX_CBIndex(pDX, IDC_COMBO2, m_nIsDoWork);
	DDX_CBIndex(pDX, IDC_COMBO3, m_nAfterComplete);
	DDX_CBIndex(pDX, IDC_COMBO4, m_nIsCatchSpecial);
}

void CPage4::RestoreState()
{
	m_nIncense	  =	theApp.GetProfileInt(_T("AdvancedSetting"), _T("Incense"),    0);
	m_nGrass	  =	theApp.GetProfileInt(_T("AdvancedSetting"), _T("Grass"),      0);
	m_nMagicDrug  =	theApp.GetProfileInt(_T("AdvancedSetting"), _T("nMagicDrug"), 0);
	m_nRound	  =	theApp.GetProfileInt(_T("AdvancedSetting"), _T("Round"),      0);

	m_MagicDrugType   = theApp.GetProfileInt(_T("AdvancedSetting"), _T("strMagicDrug"), 0);
	m_nIsDoWork       = theApp.GetProfileInt(_T("AdvancedSetting"), _T("IsDoWork"), 0);
	m_nAfterComplete  = theApp.GetProfileInt(_T("AdvancedSetting"), _T("AfterComplete"), 0);
	m_nIsCatchSpecial = theApp.GetProfileInt(_T("AdvancedSetting"), _T("IsCatchSpecial"), 0);

    UpdateData(FALSE);
}

void CPage4::SaveState()
{
	UpdateData();
	
	theApp.WriteProfileInt(_T("AdvancedSetting"), _T("Incense"),    m_nIncense);
	theApp.WriteProfileInt(_T("AdvancedSetting"), _T("Grass"),      m_nGrass);
	theApp.WriteProfileInt(_T("AdvancedSetting"), _T("nMagicDrug"), m_nMagicDrug);
	theApp.WriteProfileInt(_T("AdvancedSetting"), _T("Round"),      m_nRound);

    if (m_MagicDrugType != -1)
	    theApp.WriteProfileInt(_T("AdvancedSetting"), _T("strMagicDrug"), m_MagicDrugType);
    if (m_nIsDoWork != -1)
	    theApp.WriteProfileInt(_T("AdvancedSetting"), _T("IsDoWork"), m_nIsDoWork);
    if (m_nAfterComplete != -1)
	    theApp.WriteProfileInt(_T("AdvancedSetting"), _T("AfterComplete"), m_nAfterComplete);
    if (m_nIsCatchSpecial != -1)
	    theApp.WriteProfileInt(_T("AdvancedSetting"), _T("IsCatchSpecial"), m_nIsCatchSpecial);
}


BEGIN_MESSAGE_MAP(CPage4, CMyDialog)
	ON_CONTROL_RANGE(EN_CHANGE, IDC_EDIT1, IDC_EDIT4, &CPage4::OnChange)
	ON_CONTROL_RANGE(CBN_SELCHANGE, IDC_COMBO1, IDC_COMBO4, &CPage4::OnChange)
END_MESSAGE_MAP()


// CPage4 ��Ϣ�������

BOOL CPage4::OnInitDialog()
{
	CMyDialog::OnInitDialog();
	//��ʼ���ؼ�
	const CString strMagicDrug[2]	= {_T("�ϵ���"), _T("���в�")};

	for (int i = 0; i < 2; i++)
    ((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(strMagicDrug[i]);

	const CString strIsDoWork[2]	= {_T("��"), _T("��")};
	for (int i = 0; i < 2; i++)
        ((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(strIsDoWork[i]);

	const CString strAfterComplete[3]	= {_T("��ͣ10���Ӻ����"), _T("ץ���Զ��ػ�"), _T("�������ر���Ϸ")};
	for (int i = 0; i < 3; i++)
        ((CComboBox*)GetDlgItem(IDC_COMBO3))->AddString(strAfterComplete[i]);

	const CString strIsCatchSpecial[2]	= {_T("��"), _T("��")};
	for (int i = 0; i < 2; i++)
        ((CComboBox*)GetDlgItem(IDC_COMBO4))->AddString(strIsCatchSpecial[i]);

	RestoreState();
	
    for (int i = 0; i < 4; i++)
    {
        CComboBox* pCombox = (CComboBox*)GetDlgItem(IDC_COMBO1 + i);
        if (pCombox->GetCurSel() == -1)
            pCombox->SetCurSel(0);
    }

	return TRUE;
}

void CPage4::OnChange(UINT /*id*/)
{
	AfxGetMainWnd()->GetDlgItem(IDOK)->EnableWindow();
}

