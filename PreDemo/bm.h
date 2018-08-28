
#ifndef _BM_H
#define _BM_H

#pragma once

class Cbm {
private:
	BITMAPFILEHEADER   bmfh;                 // λͼ�ļ�ͷ
	BITMAPINFOHEADER   bmih;                 // λͼ��Ϣͷ
	PBYTE              pBits;                // λͼ����λָ��
	int                cBits;                // λͼÿ�������ֽ�����
	int                cxDib;                // λͼˮƽ���ؿ��
	int                cyDib;                // λͼ��ֱ���ظ߶�

	void SetcBits() {cBits = ((cxDib * bmih.biBitCount + 31) & ~31) >> 3;}
	void SetcxDib() {cxDib = bmih.biWidth;}
	void SetcyDib() {cyDib = bmih.biHeight;}
	inline BOOL IsInRect(const RECT & rect) const;    // �ж�ϵͳ����Ƿ��ڴ��ڷ�Χ��
public:
	// TODO: �ڴ�������ķ�����
	explicit Cbm(HWND hwndScreen = NULL);        // ͨ�����ھ����ͼ��ȡλͼ��Ϣ
	explicit Cbm(PCTSTR FilePath);               // ͨ�������ļ���ȡλͼ��Ϣ
	Cbm(const Cbm & bm, LPCRECT pRect = NULL);   // ��ȡָ�������λͼ��Ϣ
	~Cbm();   // ��������

	//����������
	Cbm & operator=(const Cbm & bm);
	friend BOOL operator==(const Cbm & bm1, const Cbm & bm2);
	//�෽��
	COLORREF  GetPixel(int x, int y) const;		// ͨ��λͼ�������RGB��ɫֵ
	void SetPixel(int x, int y, COLORREF targetColor);	 // ��дָ�������λͼRGB��ɫ
	void GrayBitmap();	// ��ͼ��ҶȻ�
	void DisplayBitmap(HWND hwnd) const;	// ��ʾλͼ
    inline void  GetBitmapRect(RECT & rect) const;  // ��ȡλͼ��rect��Χ
    BOOL SaveBitmapToFile(PCTSTR FileName = NULL, LPCRECT pRect = NULL) const; // ����λͼ���ļ�
    BOOL ResolveBitmapFile(const SIZE size, int i = 0) const;   // �ֽ�ͼƬ�ļ�
    BOOL IsRectOnTheEdge(const RECT & rect);   // �ж�rect�Ƿ���ͼƬ��Χ��Ե

	/*****************************�Ƚ���ͼ����***************************************
	*        �β�˵��bmWnd: ��ͼ����Ļ��ͼ��Դͼ
	*              bmFile: ����ͼ��Сͼ�����ļ�����
	*       (IN OUT) rect: ��ͼ�ķ�Χ,��������ͼ��Դͼ�е����귶Χ
	*                 rgb: ͸��ɫRGBֵ��͸��ɫ��Ϊ��ͼ�п��Ա����Ե���ɫ
	*            resemble: ���ƶȣ���ͬ����ռ�����صİٷֱ�,Ĭ��ֵΪ100
	**********************************************************************************/
    friend BOOL FindPic(HWND hWnd, PCTSTR FileName, LPCRECT rectTarget = NULL, OUT PRECT retRect = NULL, int resemble = 100, COLORREF rgb = 0);

	friend BOOL FindPic(const Cbm & bmWnd, const Cbm & bmFile, LPCRECT rectTarget = NULL, OUT PRECT retRect = NULL, int resemble = 100, COLORREF rgb = 0);

    friend BOOL FindPic(const Cbm & bmWnd, PCTSTR FileName, LPCRECT rectTarget = NULL, OUT PRECT retRect = NULL, int resemble = 100, COLORREF rgb = 0);

    friend BOOL FindPic(PCTSTR destFileName, PCTSTR srcFileName, LPCRECT rectTarget = NULL, OUT PRECT retRect = NULL, int resemble = 100, COLORREF rgb = 0);
	
    friend BOOL FindPicEx(const Cbm & bmWnd, const Cbm & bmFile,
        PRECT pRect = NULL, int deviation = 0, int resemble = 100, COLORREF rgb = 0);

    friend BOOL FindPicEx(const Cbm & bmWnd, PCTSTR FileName,
        PRECT pRect = NULL, int deviation = 0, int resemble = 100, COLORREF rgb = 0);

    friend BOOL FindPicEx(PCTSTR destFileName, PCTSTR srcFileName,
        PRECT pRect = NULL, int deviation = 0, int resemble = 100, COLORREF rgb = 0);

    friend BOOL FindPicEx(HWND hWnd, PCTSTR FileName,
        PRECT pRect = NULL, int deviation = 0, int resemble = 100, COLORREF rgb = 0);
	//�����޸�λͼ�ļ�,�β�:strFolderpath,������ɫignoreColor,Ҫ��������ɫ�޸ĳɵ�Ŀ����ɫtargetColor
	friend BOOL ModifyBitmapFile(PCTSTR FilePath, COLORREF ignoreColor = 0xf8fcf8, COLORREF targetColor = 0);
	//friend BOOL BM_API ModifyBitmapFile(tstring strFolderpath);
};

#endif // _BM_H