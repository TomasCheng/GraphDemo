#pragma once
#include "Matrix.h"
#include <afxwin.h>


class Cuboid
{
public:
	Matrix M_apex;

public:
	Cuboid();
	Cuboid(Matrix m);
	Matrix rotate_X(double th);
	Matrix rotate_Y(double th);
	Matrix rotate_Z(double th);
	Matrix translate(double x, double y, double z);
	MPoint* getPoints();

	void drawInfo(CDC *p,int x,int y);
	void draw(CDC *p);
	~Cuboid();
};

