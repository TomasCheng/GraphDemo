
// MFCDemo02.h : MFCDemo02 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCDemo02App:
// �йش����ʵ�֣������ MFCDemo02.cpp
//

class CMFCDemo02App : public CWinApp
{
public:
	CMFCDemo02App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCDemo02App theApp;
