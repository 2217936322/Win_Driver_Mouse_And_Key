// Page2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PreDemo.h"
#include "Page2.h"


// CPage2 �Ի���

IMPLEMENT_DYNAMIC(CPage2, CMyDialog)

CPage2::CPage2(CWnd* pParent /*=NULL*/)
: CMyDialog(CPage2::IDD, pParent)
{
}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
    CMyDialog::DoDataExchange(pDX);
    for (int i = 0; i < 10; i++)
        DDX_CBIndex(pDX, IDC_COMBO1 + i, m_nMonster[i]);

    for (int i = 0; i < 10; i++)
        DDX_Text(pDX, IDC_EDIT1 + i, m_Price[i]);

}

void CPage2::RestoreState()
{
    CString str;
    for (int i = 0; i < 10; i++)
    {
        str.Format(_T("monster%d"), i);
		m_nMonster[i] = theApp.GetProfileInt(_T("ShopSetting"), str, 0);
    }

    str.Empty();
    for (int i = 0; i < 10; i++)
    {
        str.Format(_T("Price%d"), i);
		m_Price[i]	= theApp.GetProfileInt(_T("ShopSetting"), str, 0);
    }

    UpdateData(FALSE);
}

void CPage2::SaveState()
{
    UpdateData();

    CString str;
    for (int i = 0; i < 10; i++)
    {
        if (m_nMonster[i] != -1)
        {
            str.Format(_T("monster%d"), i);
			theApp.WriteProfileInt(_T("ShopSetting"), str, m_nMonster[i]);
        }
    }

    str.Empty();
    for (int i = 0; i < 10; i++)
    {
        str.Format(_T("Price%d"), i);
        theApp.WriteProfileInt(_T("ShopSetting"), str, m_Price[i]);
    }
}

BEGIN_MESSAGE_MAP(CPage2, CMyDialog)
    ON_CONTROL_RANGE(EN_CHANGE, IDC_EDIT1, IDC_EDIT10, &CPage2::OnChange)
    ON_CONTROL_RANGE(CBN_SELCHANGE, IDC_COMBO1, IDC_COMBO10, &CPage2::OnChange)
END_MESSAGE_MAP()


// CPage2 ��Ϣ�������

BOOL CPage2::OnInitDialog()
{
    CMyDialog::OnInitDialog();

    const CString MonsterList[44] = {
        _T(""), _T("�󺣹�"), _T("����"), _T("����"), _T("Ұ��"), _T("��ͽ"), _T("ɽ��"), _T("ǿ��"),
        _T("�ϻ�"), _T("����"), _T("����"), _T("��ͷ��"), _T("���ù�"), _T("��󡾫"), _T("���꾫"),
        _T("С��Ů"), _T("��"), _T("Ϻ��"), _T("з��"), _T("��ة��"), _T("ţ��"), _T("���ܾ�"),_T("֩�뾫"),
        _T("���ӹ�"), _T("Ұ��"), _T("��ʬ"), _T("ţͷ"), _T("����"), _T("����"),_T("��������"),_T("�Ŵ�����"),
        _T("����"), _T("�콫"), _T("��ɽ����"), _T("���"), _T("�粮"),_T("����ս��"), _T("����"), _T("���"),
        _T("��ʦ"), _T("Ѳ������"), _T("ܽ������"), _T("��������"),_T("��������")
    }; 


    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 44; j++)
            ((CComboBox*)GetDlgItem(IDC_COMBO1 + i))->AddString(MonsterList[j]);

    RestoreState();

    for (int i = 0; i < 10; i++)
    {
        CComboBox* pCombox = (CComboBox*)GetDlgItem(IDC_COMBO1 + i);
        if (pCombox->GetCurSel() == -1)
            pCombox->SetCurSel(0);
    }

    return TRUE;
}

void CPage2::OnChange(UINT /*id*/)
{
    AfxGetMainWnd()->GetDlgItem(IDOK)->EnableWindow();
}

