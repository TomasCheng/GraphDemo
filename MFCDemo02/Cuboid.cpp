#include "stdafx.h"
#include "Cuboid.h"
#include "Constants.h"

Cuboid::Cuboid()
{
}

Cuboid::Cuboid(Matrix m)
{
	M_apex = m;
}

Matrix Cuboid::rotate_X(double rotate_X_th)
{
	Matrix m = M_apex;
	double rotate_X_arr[16] = {
		1,0,0,0,
		0,cos(rotate_X_th),sin(rotate_X_th),0,
		0,-sin(rotate_X_th),cos(rotate_X_th),0,
		0,0,0,1
	};
	Matrix M_rotate_X = Matrix(rotate_X_arr, 4, 4);//ÈÆxÖáÐý×ªµÄ±ä»»¾ØÕó
	M_apex = M_apex * M_rotate_X;

	return m;
}

Matrix Cuboid::rotate_Y(double rotate_Y_th)
{
	Matrix m = M_apex;
	double rotate_Y_arr[16] = {
		cos(rotate_Y_th),0,-sin(rotate_Y_th),0,
		0,1,0,0,
		sin(rotate_Y_th),0,cos(rotate_Y_th),0,
		0,0,0,1
	};
	Matrix M_rotate_Y = Matrix(rotate_Y_arr, 4, 4);
	M_apex = M_apex * M_rotate_Y;

	return m;
}

Matrix Cuboid::rotate_Z(double rotate_Z_th)
{
	Matrix m = M_apex;
	double rotate_Z_arr[16] = {
		cos(rotate_Z_th),sin(rotate_Z_th),0,0,
		-sin(rotate_Z_th),cos(rotate_Z_th),0,0,
		0,0,1,0,
		0,0,0,1
	};
	Matrix M_rotate_Z = Matrix(rotate_Z_arr, 4, 4);
	M_apex = M_apex * M_rotate_Z;

	return m;
}

Matrix Cuboid::translate(double x, double y, double z)
{

	Matrix m = M_apex;
	double translate_arr[16] = {
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		x,y,z,1
	};
	Matrix M_translate = Matrix(translate_arr, 4, 4);
	M_apex = M_apex * M_translate;
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			M_apex.data[i][j] = M_apex.data[i][j] + M_apex.data[8][j];
		}
	}
	for (int j = 0;j < 3;j++)
	{
		M_apex.data[8][j] = 0;
	}

	return m;
}


MPoint * Cuboid::getPoints()
{
	return M_apex.getPoints(8, 3);
}


void Cuboid::drawInfo(CDC *p, int x, int y)
{
	
	MPoint *points = M_apex.getPoints(8, 3);
	CString num;
	num = "X";
	p->TextOut(x + 50, y + 20, num);
	num = "Y";
	p->TextOut(x + 120, y + 20, num);
	num = "Z";
	p->TextOut(x + 190, y + 20, num);

	for (int i = 0;i < 8;i++)
	{
		num.Format(_T("%d"), i + 1);
		p->TextOut(x + 20, y + 50 + i * 20, num);
		num.Format(_T("%.1f"), points[i].x);
		p->TextOut(x + 50, y + 50 + i * 20, num);
		num.Format(_T("%.1f"), points[i].y);
		p->TextOut(x + 120, y + 50 + i * 20, num);
		num.Format(_T("%.1f"), points[i].z);
		p->TextOut(x + 190, y + 50 + i * 20, num);
	}

	Matrix m = M_apex*T_3d_To_2d;
	MPoint *points2 = m.getPoints(8, 2);

	num = "X";
	p->TextOut(x + 50, y + 220, num);
	num = "Y";
	p->TextOut(x + 120, y + 220, num);

	for (int i = 0;i < 8;i++)
	{
		num.Format(_T("%d"), i + 1);
		p->TextOut(x + 20, y + 240 + i * 20, num);
		num.Format(_T("%.1f"), points2[i].x);
		p->TextOut(x + 50, y + 240 + i * 20, num);
		num.Format(_T("%.1f"), points2[i].y);
		p->TextOut(x + 120, y + 240 + i * 20, num);
	}
}

void Cuboid::draw(CDC * p)
{
	
	Matrix m = M_apex*T_3d_To_2d;
	MPoint *points = m.getPoints(8, 2);

	for (int i = 0;i < 8;i++)
	{
		CString num;
		num.Format(_T("%d"), i + 1);
		p->TextOut(points[i].x, points[i].y, num);

	}
	for (int i = 0;i < 4;i++)
	{
		p->MoveTo(points[i].x, points[i].y);
		p->LineTo(points[(i + 1) % 4].x, points[(i + 1) % 4].y);

		p->MoveTo(points[i].x, points[i].y);
		p->LineTo(points[i + 4].x, points[i + 4].y);

	}
	for (int i = 4;i < 7;i++)
	{
		p->MoveTo(points[i].x, points[i].y);
		p->LineTo(points[(i + 1) % 8].x, points[(i + 1) % 8].y);

	}
	p->MoveTo(points[7].x, points[7].y);
	p->LineTo(points[4].x, points[4].y);
}

Cuboid::~Cuboid()
{
}
