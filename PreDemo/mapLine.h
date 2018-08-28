
#ifndef _MAPLINE_H
#define _MAPLINE_H


#pragma once
#include <list>


#define DIRECT_EXIT      TRUE
#define INDIRECT_EXIT    FALSE


class Cmap
{
// ���Ա
public:
    enum {CITY_MOVE, TAB_MOVE, MAZE_MOVE};
private:
    int       m_nCurrentMap;          // ��ͼ����
	int       m_nNextMap;             // ��һ����ͼ��
    int       m_nMoveType;            // �ƶ�����
    BOOL      m_bExitType;            // ��������
	CRect     m_ExitRect;             // ����RECT

    // ˽�з���
    BOOL TabMove(HWND hWnd) const;
    BOOL MazeMove(HWND hWnd) const;
	BOOL CityMove(HWND hWnd) const;
	int  GetTeleportPos() const;
	void CrossExitPoint(HWND hWnd) const;
// �෽��
public:
    Cmap(int MapIndex, int NextMapIndex, const RECT & ExitRect = CRect(), BOOL ExitType = DIRECT_EXIT, int MoveType = TAB_MOVE);
    BOOL MapMove(HWND hWnd) const;
    int CurrentMap() const {return m_nCurrentMap;}
    int NextMap() const {return m_nNextMap;}
};

BOOL LineMove(HWND hWnd, const std::list<Cmap> & line, int TargetMapIndex);


#endif // _MAPLINE_H

