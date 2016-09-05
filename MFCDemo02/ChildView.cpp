
// ChildView.cpp : CChildView ���ʵ��
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



// CChildView ��Ϣ�������

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
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������

	// TODO: �ڴ˴������Ϣ����������
	// ��ҪΪ������Ϣ������ CWnd::OnPaint()
	//dc��ΪCDC��������
	//������д�Լ��Ĵ��룬����ʱ�Զ���������Ĵ���

	//example 01
	//��y=sin(x)�ĺ���ͼ��
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
	//	//dc.SetPixel(i+200, y, RGB(255, 0, 0));//����ͼ
	//	dc.Ellipse(i + 200 - r, y - r, i + 200 + r, y + r);//Ȧ��ͼ
	//}

	//example 02
	//A(20,20) B(200,50),�����������
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

	//example03 ֱ��ɨ���㷨--��ֵ΢�ַ���DDA��
	//ʵ�ʻ���y=kx+b;ֻ����Ϊx�ı仯��Ϊ1,���Կ���ֱ����y�Ļ����ϼ�k��ʵ������+1*k
	//A(20,20) B(400,100)��ɫֱ�߶�
	float x1 = 40, y1 = 20, x2 = 2000, y2 = 1000;
	float x, y, k, b;
	k = (y1 - y2) / (x1 - x2);
	//b = y1 - k*x1;
	bool flag = true;//k>0�����
	if(k<0)
	{
		flag = false;
	}
	if (x1 > x2)	//��x1��x2������һ���Ĵ�С��ϵʱ���������������swapһ��
	{
		float temp;
		temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	//4�������
	//1. 0<k<1 	true	��1
	//2. k>1	true	��2
	//3. -1<k<0	false	��2
	//4. k<-1	false	��1
	if((k>0 && k<1 && flag) || (k<-1 && !flag))
	{
		y = y1;
		for (x = x1;x <= x2;x++)
		{
			//y = (int)(k*x + b + 0.5);
			dc.SetPixel(x, y, RGB(0, 0, 255));
			y = y + k;//��Ϊ��x�ı仯������,x�ı仯��Ϊ1
		}
	}
	else if((k<0 && k>-1 && !flag) || (k>1 && flag)) {
		x = x1;
		for (y = y1;y <= y2;y++)
		{
			dc.SetPixel(x, y, RGB(0, 0, 255));
			x = x + 1/k;//��Ϊ��x�ı仯������,x�ı仯��Ϊ1��б�ʱ��k�ĵ���
		}
	}


}
