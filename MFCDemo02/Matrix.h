#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class MPoint
{
public:
	double x;
	double y;
	double z;
};

class Matrix
{
public:
		double  **data;
		int row;
		int col;

public:
		
		Matrix(double x[], int m, int n);
		Matrix(int mm, int nn);
		~Matrix();
		Matrix();

		void setValue(double x,int m,int n);
		double getValue(int m,int n);

		Matrix operator +(Matrix matrix);
		Matrix operator -(Matrix matrix);
		Matrix operator *(Matrix matrix);

		void reverse();

		Matrix getSubMatrix(int x1,int y1,int x2,int y2);
		Matrix getSubMatrix(int x, int y);

		MPoint* getPoints(int size,int num);


		int getRow() {
			return row;
		}

		int getCol() {
			return col;
		}

		void show();
};



