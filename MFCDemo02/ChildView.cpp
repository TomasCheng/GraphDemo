
// ChildView.cpp : CChildView 类的实现
//

#include "stdafx.h"
#include "MFCDemo02.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView 消息处理程序

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}
void CChildView::OnPaint()
{
	CPaintDC dc(this); // 用于绘制的设备上下文

	// TODO: 在此处添加消息处理程序代码
	// 不要为绘制消息而调用 CWnd::OnPaint()
	//dc作为CDC对象的替代
	//在这里写自己的代码，运行时自动调用这里的代码

	//example 01
	//画y=sin(x)的函数图像
	/*
	radian = x *PI/ ((double)60 * 2);
	y = sin(radian) * 2 * 60;
	*/
	//float x, y;
	//const float PI = 3.1415;
	//float r = 5;
	////dc.TextOutW(100, 100, "This");

	//for (float i = 0;i <= 360;i = i + r)
	//{
	//	x = i*PI / 180;
	//	y = -sin(x) * 100 + 200;
	//	//dc.SetPixel(i+200, y, RGB(255, 0, 0));//点作图
	//	dc.Ellipse(i + 200 - r, y - r, i + 200 + r, y + r);//圈作图
	//}

	//example 02
	//A(20,20) B(200,50),求两点间连线
	//y = kx + b;	k = 3 / 17; b = 20 - 3 / 17 * 20 = ;
	/*	const float x1 = 20, y1 = 20, x2 = 200, y2 = 50;
	float x, y, k, b;
	k = (y1 - y2) / (x1 - x2);
	b = y1 - k*x1;
	for (x = x1;x <= x2;x++)
	{
	y = k*x + b;
	dc.SetPixel(x, y, RGB(255, 0, 0));
	}*/

	//example03 直线扫描算法--数值微分法（DDA）
	//实质还是y=kx+b;只是因为x的变化量为1,所以可以直接在y的基础上加k，实际上是+1*k
	//A(20,20) B(400,100)蓝色直线段
	float x1 = 40, y1 = 20, x2 = 2000, y2 = 1000;
	float x, y, k, b;
	k = (y1 - y2) / (x1 - x2);
	//b = y1 - k*x1;
	bool flag = true;//k>0的情况
	if(k<0)
	{
		flag = false;
	}
	if (x1 > x2)	//当x1和x2不满足一定的大小关系时，将两个点的坐标swap一下
	{
		float temp;
		temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	//4种情况：
	//1. 0<k<1 	true	走1
	//2. k>1	true	走2
	//3. -1<k<0	false	走2
	//4. k<-1	false	走1
	if((k>0 && k<1 && flag) || (k<-1 && !flag))
	{
		y = y1;
		for (x = x1;x <= x2;x++)
		{
			//y = (int)(k*x + b + 0.5);
			dc.SetPixel(x, y, RGB(0, 0, 255));
			y = y + k;//因为在x的变化过程中,x的变化量为1
		}
	}
	else if((k<0 && k>-1 && !flag) || (k>1 && flag)) {
		x = x1;
		for (y = y1;y <= y2;y++)
		{
			dc.SetPixel(x, y, RGB(0, 0, 255));
			x = x + 1/k;//因为在x的变化过程中,x的变化量为1，斜率变成k的倒数
		}
	}


}
