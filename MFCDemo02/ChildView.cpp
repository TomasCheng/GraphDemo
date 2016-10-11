
// ChildView.cpp : CChildView 类的实现
//

#include "stdafx.h"
#include "MFCDemo02.h"
#include "ChildView.h"
//#include "Constants.h"
#include "Matrix.h"


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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_menu_circle, &CChildView::OnMenuCircle)
	ON_COMMAND(ID_menu_line, &CChildView::OnMenuLine)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_COMMAND(ID_menu_rotateX, &CChildView::OnMenuRotatex)
	ON_COMMAND(ID_menu_rotateY, &CChildView::OnMenuRotatey)
	ON_COMMAND(ID_menu_rotateZ, &CChildView::OnMenuRotatez)
	ON_COMMAND(ID_menu_stopRotate, &CChildView::OnMenuStoprotate)
	ON_COMMAND(ID_menu_stopTran, &CChildView::OnMenuStoptran)
	ON_COMMAND(ID_menu_tranX, &CChildView::OnMenuTranx)
	ON_COMMAND(ID_menu_tranY, &CChildView::OnMenuTrany)
	ON_COMMAND(ID_menu_tranZ, &CChildView::OnMenuTranz)
//	ON_COMMAND(ID_menu_small, &CChildView::OnMenuSmall)
	ON_COMMAND(ID_menu_stopChange, &CChildView::OnMenuStopchange)
	ON_COMMAND(ID_menu_change, &CChildView::OnMenuChange)
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
	CRect rect;
	GetClientRect(&rect);
	CDC *p = GetDC();
	p->SetMapMode(MM_ANISOTROPIC);
	p->SetWindowExt(rect.Width(), rect.Height());
	p->SetViewportExt(rect.Width(), -rect.Height());
	p->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);

	/*drawBase();
	
	drawShape();

	drawInfo();*/

	drawBase();
	cuboid.draw(p);
	cuboid.drawInfo(p, -700, -80);

	
	


	//CDC *pDC = GetDC();
	//CRect rect;//声明客户区矩形
	//GetClientRect(&rect);//获得客户区坐标

	//int height = (int)rect.Height();
	//int width = (int)rect.Width();
	//int i;
	//pDC->SetMapMode(MM_LOMETRIC);  //设置映射模式为：MM_LOMETRIC，即每个逻辑坐标被转换为0.1 mm。正x向右，正y向上。
	//pDC->SetWindowExt(width, height); //设置窗口
	//pDC->SetViewportExt(width, -height); //x轴水平向右，y轴垂直向上
	//pDC->SetViewportOrg(width/2,-height/2); //客户区中心为坐标系原点
	//pDC->SetWindowOrg(width / 2, -height / 2);
	// //画X轴
	//pDC->MoveTo(0, -height / 2);
	//pDC->LineTo(width, -height / 2);
	////画Y轴
	//pDC->MoveTo(width / 2, 0);
	//pDC->LineTo(width / 2, -height);

	/*CString x = _T("(0,0)");
	p->TextOut(0,0, x);
	x = _T("(100,-100)");
	p->TextOut(100, -100, x);*/
	






}
//example03 直线扫描算法--数值微分法（DDA）
//实质还是y=kx+b;只是因为x的变化量为1,所以可以直接在y的基础上加k，实际上是+1*k
//A(20,20) B(400,100)蓝色直线段
void CChildView::drwaLineDDA(float x1, float y1, float x2, float y2)
{
	CDC *dc;
	dc = GetDC();

	float x, y, k, b;
	if (x1 == x2)//此时斜率k不存在
	{
		if (y1 > y2)
		{
			float temp;
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		for (int i = y1;i <= y2;i++)
		{
			dc->SetPixel(x1, i, RGB(0, 0, 255));
		}
	}

	k = (y1 - y2) / (x1 - x2);	//这里要求x1！=x2
	bool flag = true;//k>0的情况
	if (k<0)
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
	if ((k >= 0 && k<1) || (k <= 0 && k>-1))
	{
		y = y1;
		for (x = x1;x <= x2;x++)
		{
			//y = (int)(k*x + b + 0.5);
			dc->SetPixel(x, y, RGB(0, 0, 255));
			y = y + k;//因为在x的变化过程中,x的变化量为1
		}
	}
	else if ((k<-1) || (k>1)) {
		x = x1;
		for (y = y1;y <= y2;y++)
		{
			dc->SetPixel(x, y, RGB(0, 0, 255));
			x = x + 1 / k;//因为在x的变化过程中,x的变化量为1，斜率变成k的倒数
		}
	}

}

//example 02
//A(20,20) B(200,50),求两点间连线
//y = kx + b;	k = 3 / 17; b = 20 - 3 / 17 * 20 = ;
void CChildView::drawLinePTP(float x1, float y1, float x2, float y2)
{
	CDC *dc;
	dc = GetDC(); // 用于绘制的设备上下文
	float x, y, k, b;
	k = (y1 - y2) / (x1 - x2);
	b = y1 - k*x1;
	for (x = x1;x <= x2;x++)
	{
		y = k*x + b;
		dc->SetPixel(x, y, RGB(255, 0, 0));
	}

}

//中点画线法画直线
void CChildView::drawLineMP(float x1, float y1, float x2, float y2)
{
	CDC *dc;
	dc = GetDC(); // 用于绘制的设备上下文
	/*中点算法画直线
	d(0) = 0.5 -k
	d(i+1) = di - k,当d(i)>=0 y(i+1)=y(i)
	d(i+1) = di -k +1,当d(i)<0 y(i+1)=y(i)+1
	(0,0)->(5,2),使用中点法
	k=0.4
	x(i)	y(i)	d(i)
	0		0		0.1
	1		0		-0.3		
	2		1		0.3
	3		1		-0.1
	4		2		0.5
	5		2		0.1
	*/

	//程序实现算法
	float x, y, k, d;
	k = (y1 - y2) / (x1 - x2);
	d = 0.5 - k;
	x = x1;
	y = y1;
	for (x = x1;x <= x2;x++)
	{
		dc->SetPixel(x, y, RGB(255, 0, 0));
		if (d >= 0) {
			y = y;
			d = d - k;
		}
		else
		{
			y = y + 1;
			d = d - k + 1;
		}
	}


}

//example 01
//画y=sin(x)的函数图像
//radian = x *PI/ ((double)60 * 2);
//y = sin(radian) * 2 * 60;
void CChildView::drawSin()
{
	CDC *dc;
	dc = GetDC();// 用于绘制的设备上下文
	float x, y;
	const float PI = 3.1415;
	float r = 5;

	for (float i = 0;i <= 360;i = i + r)
	{
		x = i*PI / 180;
		y = -sin(x) * 100 + 200;
		//dc.SetPixel(i+200, y, RGB(255, 0, 0));//点作图
		dc->Ellipse(i + 200 - r, y - r, i + 200 + r, y + r);//圈作图
	}
}

////取指定点的像素值
void CChildView::drawDoubleColor()
{
	CDC *dc;
	dc = GetDC();
	srand((unsigned)time(NULL));
	COLORREF crcolor;
	int x, y;
	for (y = 100;y < 300;y++)
	{
		for (x = 100;x < 300;x++)
		{
			dc->SetPixelV(x, y, RGB(rand() % 255, (x+y) % 255, (x*y) % 255));
		}
	}
	for (y = 100;y < 300;y++)
	{
		for (x = 100;x < 300;x++)
		{
			crcolor = dc->GetPixel(x, y);
			dc->SetPixel(800-x,y, crcolor);
		}
	}
}

//简单填充算法设计
//三角形填充 A(100,300)  B(200,200)  C(400,300)
void CChildView::fillShape()
{

}

void CChildView::drawBase()
{
	CRect rect;
	GetClientRect(&rect);
	CDC *p = GetDC();
	p->SetMapMode(MM_ANISOTROPIC);
	p->SetWindowExt(rect.Width(), rect.Height());
	p->SetViewportExt(rect.Width(), -rect.Height());
	p->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);

	double mm[20] = {
		0,0, 0, 0,
		0 + 400,0, 0, 0,
		0,0 + 300, 0, 0,
		0,0,400,0,
		0,  0,  0,  1 };//坐标轴坐标

	Matrix M_base = Matrix(mm, 5, 4);	//坐标系矩阵
	double am[16] = {
		1,0,0,0,
		0,1,0,0,
		-sqrt(2) / 2,-sqrt(2) / 2,0,0,
		0,0,0,1
	};//3d转2d的转换矩阵数组

	Matrix T_3d_To_2dm = Matrix(am, 4, 4);//3d转2d的转换矩阵

	Matrix m = M_base*T_3d_To_2dm;
	//CDC *p = GetDC();
	p->MoveTo(m.data[0][0], m.data[0][1]);
	p->LineTo(m.data[1][0], m.data[1][1]);
	CString x = _T("X");
	p->TextOut(m.data[1][0], m.data[1][1], x);

	p->MoveTo(m.data[0][0], m.data[0][1]);
	p->LineTo(m.data[2][0], m.data[2][1]);
	CString y = _T("Y");
	p->TextOut(m.data[2][0], m.data[2][1], y);

	p->MoveTo(m.data[0][0], m.data[0][1]);
	p->LineTo(m.data[3][0], m.data[3][1]);
	CString z = _T("Z");
	p->TextOut(m.data[3][0], m.data[3][1], z);
}

void CChildView::drawShape()
{
	//CRect rect;
	//GetClientRect(&rect);
	//CDC *p = GetDC();
	//p->SetMapMode(MM_ANISOTROPIC);
	//p->SetWindowExt(rect.Width(), rect.Height());
	//p->SetViewportExt(rect.Width(), -rect.Height());
	//p->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	//rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);

	//Matrix m = M_Shape*T_3d_To_2d;
	////CDC *p = GetDC();
	//MPoint *points = m.getPoints(8,2);

	//for (int i = 0;i < 8;i++)
	//{
	//	CString num;
	//	num.Format(_T("%d"), i+1);
	//	p->TextOut(points[i].x, points[i].y, num);
	//	
	//}
	//for (int i = 0;i < 4;i++)
	//{
	//	p->MoveTo(points[i].x, points[i].y);
	//	p->LineTo(points[(i + 1) % 4].x, points[(i + 1) % 4].y);
	//	
	//	p->MoveTo(points[i].x, points[i].y);
	//	p->LineTo(points[i + 4].x, points[i + 4].y);
	//	
	//}
	//for (int i = 4;i < 7;i++)
	//{
	//	p->MoveTo(points[i].x, points[i].y);
	//	p->LineTo(points[(i + 1) % 8].x, points[(i + 1) % 8].y);
	//	
	//}
	//p->MoveTo(points[7].x, points[7].y);
	//p->LineTo(points[4].x, points[4].y);

	

	
}

void CChildView::drawInfo()
{
	/*CDC *p = GetDC();
	MPoint *points = M_Shape.getPoints(8,3);
	CString num;
	num = "X";
	p->TextOut(50, 20 , num);
	num = "Y";
	p->TextOut(120, 20, num);
	num = "Z";
	p->TextOut(190, 20, num);	

	for (int i = 0;i < 8;i++)
	{
		num.Format(_T("%d"), i+1);
		p->TextOut(20, 50 + i * 20, num);
		num.Format(_T("%.1f"), points[i].x);
		p->TextOut(50, 50+i*20, num);
		num.Format(_T("%.1f"), points[i].y);
		p->TextOut(120, 50 + i * 20, num);
		num.Format(_T("%.1f"), points[i].z);
		p->TextOut(190, 50 + i * 20, num);
	}

	Matrix m = M_Shape*T_3d_To_2d;
	MPoint *points2 = m.getPoints(8, 2);
	
	num = "X";
	p->TextOut(50, 220, num);
	num = "Y";
	p->TextOut(120, 220, num);
	
	for (int i = 0;i < 8;i++)
	{
		num.Format(_T("%d"), i + 1);
		p->TextOut(20, 240 + i * 20, num);
		num.Format(_T("%.1f"), points2[i].x);
		p->TextOut(50, 240 + i * 20, num);
		num.Format(_T("%.1f"), points2[i].y);
		p->TextOut(120, 240 + i * 20, num);
	}*/

}

//鼠标按下的动作
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//mypoint = point;

	CWnd::OnLButtonDown(nFlags, point);
}

//鼠标抬起的动作
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*CDC *p;
	p = GetDC();
	p->MoveTo(mypoint);
	p->LineTo(point);*/

	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMenuCircle()
{
	// TODO: 在此添加命令处理程序代码
	CDC *p;
	p = GetDC();
	p->Ellipse(200-50,200-50,200+50,200+50);
}

void CChildView::OnMenuLine()
{
	// TODO: 在此添加命令处理程序代码
	CDC *p;
	p = GetDC();
	p->MoveTo(200, 200);
	p->LineTo(500, 500);
	
	
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//rotate_X_th = (int(rotate_X_th) + 10) % 360 * (3.14 / 180);
	////rotate_X_th ++;

	////rotate_Y_th = (int(rotate_Y_th) + 10) % 360 * (3.14 / 180);
	//rotate_Y_th++;

	//rotate_Z_th = (int(rotate_Z_th) + 5) % 360 * (3.14 / 180);

	//double temp[16] = {
	//	1,0,0,0,
	//	0,cos(rotate_X_th),sin(rotate_X_th),0,
	//	0,-sin(rotate_X_th),cos(rotate_X_th),0,
	//	0,0,0,1
	//};

	//for (int i = 0;i < 16;i++)
	//{
	//	rotate_X_arr[i] = temp[i];
	//}

	//M_rotate_X = Matrix(rotate_X_arr, 4, 4);

	//M_Shape = M_Shape*M_rotate_X;

	//Invalidate();
	if (direction > 0)
	{
		th = (int(th) + 10) % 360 * (3.14 / 180);
	}
	if (direction == 1) 
	{
		cuboid.rotate_X(th);
	}
	else if (direction == 2)
	{
		cuboid.rotate_Y(th);
	}
	else if (direction == 3)
	{
		cuboid.rotate_Z(th);
	}

	if (translation > 0)
	{
		if (move>=200 && flag==1)
		{
			flag = -1;
			tape = -4;
		}
		else if (move <= -200 && flag == -1)
		{
			flag = 1;
			tape = 4;
		}
		move = move + flag * 5;
		
		
		
	}
	if (translation == 1)
	{
		cuboid.translate(tape, 0, 0);
	}
	else if (translation == 2)
	{
		cuboid.translate(0, tape, 0);
	}
	else if (translation == 3)
	{
		cuboid.translate(0, 0, tape);
	}
	

	Invalidate();

	CWnd::OnTimer(nIDEvent);
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	initCuboid();

	SetTimer(1, 100, NULL);

	return 0;
}


void CChildView::OnMenuRotatex()
{
	// TODO: 在此添加命令处理程序代码
	initCuboid();

	direction = 1;
	
	Invalidate();
}


void CChildView::OnMenuRotatey()
{
	// TODO: 在此添加命令处理程序代码
	initCuboid();

	direction = 2;
	
	Invalidate();
}


void CChildView::OnMenuRotatez()
{
	// TODO: 在此添加命令处理程序代码
	initCuboid();

	direction = 3;
	
	Invalidate();
}


void CChildView::OnMenuStoprotate()
{
	// TODO: 在此添加命令处理程序代码
	initCuboid();
	Invalidate();
}


void CChildView::OnMenuStoptran()
{
	// TODO: 在此添加命令处理程序代码
	initCuboid();

	translation = 0;
	Invalidate();
}


void CChildView::OnMenuTranx()
{
	// TODO: 在此添加命令处理程序代码
	initCuboid();

	translation = 1;
	Invalidate();
}


void CChildView::OnMenuTrany()
{
	// TODO: 在此添加命令处理程序代码
	initCuboid();

	translation = 2;
	Invalidate();
}


void CChildView::OnMenuTranz()
{
	// TODO: 在此添加命令处理程序代码
	initCuboid();
	translation = 3;
	Invalidate();
}

void CChildView::initCuboid()
{
	double shape_x = 200, shape_y = 100, shape_z = 250;
	double shape[36] = {
		0 ,0 ,0,0,
		shape_x ,0 ,0,0,
		shape_x ,shape_y ,0,0,
		0 ,shape_y ,0,0,
		0 ,0 ,shape_z,0,
		shape_x ,0 ,shape_z,0,
		shape_x ,shape_y ,shape_z,0,
		0 ,shape_y ,shape_z,0,
		0,0,0,1
	};

	Matrix M_Shape = Matrix(shape, 9, 4);

	cuboid = Cuboid(M_Shape);
	th = 0;
	direction = 0;
	move = 0;
	flag = 1;
	tape = 4;
	translation = 0;
}


//void CChildView::OnMenuSmall()
//{
//	// TODO: 在此添加命令处理程序代码
//}


void CChildView::OnMenuStopchange()
{
	// TODO: 在此添加命令处理程序代码
}


void CChildView::OnMenuChange()
{
	// TODO: 在此添加命令处理程序代码

}
