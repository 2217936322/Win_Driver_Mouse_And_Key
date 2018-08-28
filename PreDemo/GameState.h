
#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#pragma once
#include "bm.h"
#include <vector>
#include <map>


// ��Ϸ��ͼ����
#define UNKNOWN_MAP 0   //δ֪����

// ���г���
#define MAP_CITY_CA 1   //������
#define MAP_CITY_JY 2   //������
#define MAP_CITY_AL 3   //������
#define MAP_CITY_CS 4   //���ٴ�
#define MAP_CITY_ZZ 5   //���Ϲ�
#define MAP_CITY_XL 6   //����Ů��
#define MAP_CITY_BX 7   //����� 

//ʦ�ų���
#define MAP_SM_DT    8   //���ƹٸ�
#define MAP_SM_HS    9   //������
#define MAP_SM_NE    10  //Ů����
#define MAP_SM_FC    11  //����ɽ
#define MAP_SM_LG    12  //����
#define MAP_SM_DF    13  //���ܵظ�
#define MAP_SM_WZ    14  //��ׯ��
#define MAP_SM_TG    15  //�칬
#define MAP_CITY_MAX 15 
#define MAP_SM_PS    16  //��˿��
#define MAP_SM_MW    17  //ħ��կ
#define MAP_SM_ST    18  //ʨ����
#define MAP_SM_PT    19  //����ɽ

//Ұ�ⳡ��
#define MAP_SUBURB_DongHW       20  //������
#define MAP_SUBURB_DongHHD      21  //��������
#define MAP_SUBURB_JiangNYW     22  //����Ұ��
#define MAP_SUBURB_DaTGJ        23  //���ƹ���
#define MAP_SUBURB_DaTJW        24  //���ƾ���
#define MAP_SUBURB_YueG         25  //�¹� 
#define MAP_SUBURB_HuaGS	    26  //����ɽ
#define MAP_SUBURB_ChangSJW     27  //���ٽ���
#define MAP_SUBURB_BeiJLZ       28  //����«��

//�Թ�����
//������
#define MAP_MAZE_T1 29  //T1
#define MAP_MAZE_T2 30  //T2
#define MAP_MAZE_T3 31  //T3
#define MAP_MAZE_T4 32  //T4
#define MAP_MAZE_T5 33  //T5
#define MAP_MAZE_T6 34  //T6
#define MAP_MAZE_T7 35  //T7

//�����Թ�
#define MAP_MAZE_H1 36  //H1
#define MAP_MAZE_H2 37  //H2
#define MAP_MAZE_H3 38  //H3
#define MAP_MAZE_H4 39  //H4
#define MAP_MAZE_H5 40  //H5

//�����Թ�
#define MAP_MAZE_D1 41  //D1
#define MAP_MAZE_D2 42  //D2
#define MAP_MAZE_D3 43  //D3
#define MAP_MAZE_D4 44  //D4
#define MAP_MAZE_D5 45  //D5

//����
#define MAP_MAZE_L1 46  //L1
#define MAP_MAZE_L2 47  //L2
#define MAP_MAZE_L3 48  //L3
#define MAP_MAZE_L4 49  //L4
#define MAP_MAZE_L5 50  //L5
#define MAP_MAZE_L6 51  //L6
#define MAP_MAZE_L7 52  //L7

//�ﳲ
#define MAP_MAZE_F1 53  //F1
#define MAP_MAZE_F2 54  //F2
#define MAP_MAZE_F3 55  //F3
#define MAP_MAZE_F4 56  //F4
#define MAP_MAZE_F5 57  //F5
#define MAP_MAZE_F6 58  //F6
#define MAP_MAZE_F7 59  //F7

// NPC�̵곡��
#define MAP_MAZE_MIN    60  // ��С��ͼ������Сֵ
#define MAP_CA_HOTEL    60  // �����Ƶ�
#define MAP_CA_HOTEL_2L 61  // �����Ƶ��¥
#define MAP_CA_BOOKSHOP 62  // �������
#define MAP_CA_SHOP     63  // �����̻�

//��������
#define Monster_NO             0         //��
#define Monster_DaHaiGui       1         //�󺣹�
#define Monster_JuWa           2         //����
#define Monster_ShuGuai        3         //����
#define Monster_YeZhu          4         //Ұ��
#define Monster_DuTu           5         //��ͽ
#define Monster_ShanZei        6         //ɽ��
#define Monster_QiangDao       7         //ǿ��
#define Monster_LaoHu          8         //�ϻ�
#define Monster_HeiXiong       9         //����
#define Monster_HuaYao         10        //����
#define Monster_YangTouGuai    11        //��ͷ��
#define Monster_KuLouGuai      12        //���ù�
#define Monster_HaMaJing       13        //��󡾫
#define Monster_HuLiJing       14        //���꾫
#define Monster_XiaoLongNv     15        //С��Ů
#define Monster_Lang           16        //��
#define Monster_XiaBing        17        //Ϻ��
#define Monster_XieJiang       18        //з��
#define Monster_GuiChengXiang  19        //��ة��
#define Monster_NiuYao         20        //ţ��
#define Monster_HeiXiongJing   21        //���ܾ�
#define Monster_ZhiZhuJing     22        //֩�뾫
#define Monster_TuZiGuai       23        //���ӹ�
#define Monster_YeGui          24        //Ұ��
#define Monster_JiangShi       25        //��ʬ
#define Monster_NiuTou         26        //ţͷ
#define Monster_MaMian         27        //����
#define Monster_LeiNiao        28        //����
#define Monster_HuDieXianZi    29        //��������
#define Monster_GuDaiRuiShou   30        //�Ŵ�����
#define Monster_BaiXiong       31        //����
#define Monster_TianJiang      32        //�콫
#define Monster_HeiShanLaoYao  33        //��ɽ����
#define Monster_TianBing       34        //���
#define Monster_FengBo         35        //�粮
#define Monster_DiYuZhanShen   36        //����ս��
#define Monster_JiaoLong       37        //����
#define Monster_FengHuang      38        //���
#define Monster_YuShi          39        //��ʦ
#define Monster_XunYouTianShen 40        //Ѳ������
#define Monster_FuRongXianZi   41        //ܽ������
#define Monster_XingLingXianZi 42        //��������
#define Monster_RuYiXianZi     43        //��������


//���ַ��ű�ʶ
#define INVALID_VALUE   -1  //��Ч��ֵ
#define BITMAP_ZERO     0   //����������ͼ��0
#define BITMAP_ONE      1   //����������ͼ��1
#define BITMAP_TWO      2   //����������ͼ��2
#define BITMAP_THREE    3   //����������ͼ��3
#define BITMAP_FOUR     4   //����������ͼ��4
#define BITMAP_FIVE     5   //����������ͼ��5
#define BITMAP_SIX      6   //����������ͼ��6
#define BITMAP_SEVEN    7   //����������ͼ��7
#define BITMAP_EIGHT    8   //����������ͼ��8
#define BITMAP_NINE     9   //����������ͼ��9
#define LEFTBRACKET     10  //������
#define RIGHTBRACKET    11  //�ҷ�����
#define COMMA1          12  //����1
#define COMMA2          13  //����2
#define COMMA3          14  //����3


//��Ϸ���｡��״��
#define HEALTH_POINT    1    //����ֵ
#define MANA_POINT      2    //ħ��ֵ
#define SULK_POINT      3    //��ŭֵ
#define EXPERIENCE      4    //����ֵ


/////////////////////////////////////////////////////////////
enum {
    BaoZi = 1,    // ����
    SheYaoXiang,  // ������
    DongMingCao,  // ��ڤ��
    GuiQieCao,    // ���в�
    ZiDanLuo,     // �ϵ���
    FeiXingFu,    // ���з�
	DaoBiaoQi,    // ������
	ITEM_MAX = 7
};

enum {UNKNOWN_POS = -1, ShangHui_POS, JiuDian_POS, DaYanTa_POS, GuoJing_POS, YeWai_POS,
    ShuDian_POS, YiZhan_POS, HuaGuoShan_POS, DongHaiWan_POS, JiaoWai_POS, ZhuZiGuo_POS};


#ifdef UNICODE
#define SOUND_FILE_NAME L"BJ.wav"
#else
#define SOUND_FILE_NAME "BJ.wav"
#endif


// һЩ�Զ����RECT��Ļ����
#define RECT_NOT_DAOJULAN    CRect(220, 30, 520, 60)
#define RECT_NOT_TABMAP      CRect(220, 30, 520, 65)
#define RECT_NOT_XIANLING    CRect(480, 60, 580, 160)
#define RECT_NOT_MONSTER     CRect(110, 275, 380, 380)
#define RECT_MONSTER         CRect(53, 48, 292, 270)
#define RECT_MAPINFO         CRect(18, 23, 130, 55)
#define RECT_STATUSBAR       CRect(571, 0, 640, 51)
#define RED_BAR_RECT         CRect(596, 7, 619, 12)
#define BLUE_BAR_RECT        CRect(598, 18, 621, 24)
#define CENTER_RECT          CRect(200, 160, 440, 320)

#define OPEN_WINDOW          TRUE
#define CLOSE_WINDOW         FALSE


#define WAIT_TIME_OUT        10000

typedef int Mst_Ty;
typedef int Mst_Prc;
typedef int Mst_Num;
struct MONSTERSHOPINFO {

    Mst_Ty  monsterType;
    Mst_Prc monsterPrice;

};


struct MONSTERINFO {

    Mst_Ty  monsterType;
    Mst_Num monsterNumber;

};

/************************��ͼ�Ƚ���ͼ����***************************************
	*       �β�˵��hwndScreen: ��ͼ���ھ��
	*                Folderpath: Сͼ���ڵ��ļ���·�������ơ�pic\\��
	*            (OUT) FileName: �����ҵ����ļ���
	*             (IN OUT) rect:�����ҵ�ƥ��ͼ�ķ�Χ���ꡣû�ҵ��򷵻���
	*********************************************************************************/
BOOL FindSomePic(const Cbm & bmWnd, PCTSTR FileName, LPCRECT rectTarget = NULL, PRECT retRect = NULL, PTSTR retFileName = NULL, int resemble = 100, COLORREF rgb = 0);
	
BOOL FindSomePic(HWND hWnd, PCTSTR FileName, LPCRECT rectTarget = NULL, PRECT retRect = NULL, PTSTR retFileName = NULL, int resemble = 100, COLORREF rgb = 0);

BOOL FindSomePicEx(const Cbm & bmWnd, PCTSTR FileName, PRECT pRect = NULL,
                   PTSTR retFileName = NULL, int deviation = 0, int resemble = 100, COLORREF rgb = 0);

BOOL FindSomePicEx(HWND hWnd, PCTSTR FileName, PRECT pRect = NULL,
                   PTSTR retFileName = NULL, int deviation = 0, int resemble = 100, COLORREF rgb = 0);

int GetMapIndex(const Cbm & bmWnd, int resemble = 100, COLORREF rgb = 0);

int GetMapIndex(HWND hWnd, int resemble = 100, COLORREF rgb = 0);

UINT GetRoleStatusValue(const Cbm & bmWnd, int StatusType);

UINT GetRoleStatusValue(HWND hWnd, int StatusType);

BOOL GetGameRolePos(const Cbm & bmWnd, POINT &ptPos, int resemble = 100, COLORREF rgb = 0);

BOOL GetGameRolePos(HWND hWnd, POINT &ptPos, int resemble = 100, COLORREF rgb = 0);

BOOL UseItemEx(HWND hWnd, int ItemType, int MapIndex = UNKNOWN_MAP, int TeleportPos = UNKNOWN_POS);

BOOL IsRoleStatic(HWND hWnd, PPOINT ptPos = NULL);

/***********ͨ����Ϸ���ͼ�꣬���ҹ������Ϸ�����е�����******************/
BOOL GetGameCursorPos(const Cbm & bmWnd, POINT & pt, int resemble = 100, COLORREF rgb = 0);

BOOL GetGameCursorPos(HWND hWnd, POINT & pt, int resemble = 100, COLORREF rgb = 0);

BOOL MoveGameCursorToSpecifyPos(HWND hWnd, const RECT & rect);

void MoveToSchool(HWND hWnd, int SchoolMapIndex);

int MonsterToMap(int monster);

BOOL CreateFolder(PCTSTR FilePath);

void ClickCheckWindow(HWND hWnd);

void EscapeFighting(HWND hWnd);

int GetShopMonsterNum(HWND hWnd);

void BeWarning(PCTSTR alarmFileName);

BOOL GotoHotel(HWND hWnd);

BOOL ShutDown(DWORD dwFlag);

void CheckRoleStatus(HWND hWnd, int StatusType, int LimitValue);

void GetConfigMonsterInfo(std::vector<MONSTERSHOPINFO> & vecShopInfo);

BOOL CatchMonster(HWND hWnd, const std::multimap<Mst_Num, Mst_Ty> & mtmp);

BOOL CheckShop(HWND hWnd, const std::vector<MONSTERSHOPINFO> & vecShopInfo, std::multimap<Mst_Num, Mst_Ty> & mtmp);


#endif // _GAMESTATE_H