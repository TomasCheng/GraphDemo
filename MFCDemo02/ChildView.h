
// ChildView.h : CChildView ��Ľӿ�
//


#pragma once
#include "Cuboid.h"


// CChildView ����

class CChildView : public CWnd
{
// ����
public:
	CChildView();

// ����
public:

// ����
public:

// ��д
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CChildView();

	// ���ɵ���Ϣӳ�亯��

	//CPoint mypoint;
public:
	Cuboid cuboid;

	double th;
	unsigned int direction;

	double move;
	double flag;
	double tape;
	unsigned int translation;

	void initCuboid();


protected:
	afx_msg void OnPaint();

private:
	void drwaLineDDA(float x1,float y1,float x2,float y2);
	void drawLinePTP(float x1, float y1, float x2, float y2);
	void drawLineMP(float x1, float y1, float x2, float y2);
	void drawSin();
	void drawDoubleColor();
	void fillShape();
	void drawBase();
	void drawShape();
	void drawInfo();
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMenuCircle();
	afx_msg void OnMenuLine();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMenuRotatex();
	afx_msg void OnMenuRotatey();
	afx_msg void OnMenuRotatez();
	afx_msg void OnMenuStoprotate();
	afx_msg void OnMenuStoptran();
	afx_msg void OnMenuTranx();
	afx_msg void OnMenuTrany();
	afx_msg void OnMenuTranz();
//	afx_msg void OnMenuSmall();
	afx_msg void OnMenuStopchange();
	afx_msg void OnMenuChange();
};

