#include "stdafx.h"
#include "Matrix.h"



Matrix::Matrix(int m, int n)
{
	row = m;
	col = n;
	data = (double **)malloc(sizeof(double *)*m);
	for (int i = 0;i < m;i++)
	{
		data[i] = (double *)malloc(sizeof(double)*n);
	}
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			data[i][j] = 0;
		}
	}
}

Matrix::Matrix(double x[], int m, int n)
{	
	row = m;
	col = n;
	data = (double **)malloc(sizeof(double *)*m);
	for (int i = 0;i < m;i++)
	{
		data[i] = (double *)malloc(sizeof(double)*n);
	}	
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			data[i][j] = x[i*n+j];		
		}
	}
}

Matrix::~Matrix()
{
	/*for (int i = 0;i < row;i++)
	{
		free(data[i]);
		data[i] = NULL;
	}*/
}

Matrix::Matrix()
{
	
}

void Matrix::setValue(double x, int m, int n)
{
	data[m][n] = x;
}

double Matrix::getValue(int m, int n)
{
	return data[m][n];
}

Matrix Matrix::operator+(Matrix matrix)
{
	if (matrix.getRow() != row || matrix.getCol() != col)
	{
		cout << "row or col is not capable" <<endl;
		Matrix error;
		return error;
	}
	Matrix m = Matrix(row, col);
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			m.setValue(matrix.getValue(i, j) + data[i][j], i, j);
		}
	}
	return m;
}

Matrix Matrix::operator-(Matrix matrix)
{
	if (matrix.getRow() != row || matrix.getCol() != col)
	{
		cout << "row or col is not capable" << endl;
		Matrix error;
		return error;
	}
	Matrix m = Matrix(row, col);
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			m.setValue(data[i][j] - matrix.getValue(i, j), i, j);
		}
	}
	return m;
}

Matrix Matrix::operator*(Matrix matrix)
{

	if (matrix.getRow() != col)
	{
		cout << "row is not capable" << endl;
		Matrix error;
		return error;
	}
	Matrix m = Matrix(row, matrix.getCol());
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < matrix.getCol();j++)
		{
			for (int r = 0;r < col;r++)
			{
				m.data[i][j] = m.data[i][j] + data[i][r] * matrix.data[r][j];
			}
		}
	}
	return m;
}

void Matrix::reverse()
{
	Matrix m = Matrix(row, col);
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			m.data[j][i] = data[i][j];
		}
	}
	data = m.data;
	row = m.row;
	col = m.col;
}

Matrix Matrix::getSubMatrix(int x1, int y1, int x2, int y2)
{
	if (x1 >= x2 || y1 >= y2)
	{
		cout << "parm error"<<endl;
		Matrix error;
		return error;
	}
	Matrix m = Matrix(x2-x1+1,y2-y1+1);
	int p = 0, q = 0;
	for (int i = x1;i <= x2;i++)
	{
		for (int j = y1;j <= y2;j++)
		{
			m.data[q][p] = data[j][i];
			p++;
		}
		p = 0;
		q++;
	}
	return m;
}

Matrix Matrix::getSubMatrix(int x, int y)
{
	return getSubMatrix(0,0,x,y);
}

MPoint * Matrix::getPoints(int size,int num)
{
	if (size > row) {
		return nullptr;
	}
	MPoint* points = (MPoint*)malloc(sizeof(MPoint)*size);

	if (num == 2)
	{
		for (int i = 0;i < size;i++)
		{
			points[i].x = data[i][0];
			points[i].y = data[i][1];
		}
	}
	else if (num == 3)
	{
		for (int i = 0;i < size;i++)
		{
			points[i].x = data[i][0];
			points[i].y = data[i][1];
			points[i].z = data[i][2];
		}
	}
	
	return points;
}

void Matrix::show()
{
	for (int i=0;i < row;i++)
	{
		for (int j = 0;j < col;j++) {
			//cout <<setw(4)<< data[i][j] << "  ";
		}
		cout << endl;
	}	
}


