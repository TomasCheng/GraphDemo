#pragma once
#include "Matrix.h"
#include <math.h>


double base_x = 0, base_y = 0;//坐标原点
//
//double to_base[16] = {
//	1,0,0,0,
//	0,1,0,0,
//	0,0,1,0,
//	-base_x,-base_y,0,1
//};
//double from_base[16] = {
//	1,0,0,0,
//	0,1,0,0,
//	0,0,1,0,
//	base_x,base_y,0,1
//};
//Matrix M_To_Base = Matrix(to_base, 4, 4);
//Matrix M_From_Base = Matrix(from_base, 4, 4);

//double m[20] = {
//	base_x,base_y, 0, 0,
//	base_x + 400,base_y, 0, 0,
//	base_x,base_y + 300, 0, 0,
//	base_x,base_y,400,0,
//	0,  0,  0,  1 };//坐标轴坐标
double a[16] = {
	1,0,0,0,
	0,1,0,0,
	-sqrt(2) / 2,-sqrt(2) / 2,0,0,
	0,0,0,1
};//3d转2d的转换矩阵数组

//Matrix M_base = Matrix(m, 5, 4);	//坐标系矩阵
Matrix T_3d_To_2d = Matrix(a, 4, 4);//3d转2d的转换矩阵

//double shape_x = 200, shape_y = 100, shape_z = 250;
//double shape[36] = {
//	0+ base_x,0 + base_y,0,0,
//	shape_x + base_x,0 + base_y,0,0,
//	shape_x + base_x,shape_y + base_y,0,0,
//	0 + base_x,shape_y + base_y,0,0,
//	0 + base_x,0 + base_y,shape_z,0,
//	shape_x + base_x,0 + base_y,shape_z,0,
//	shape_x + base_x,shape_y + base_y,shape_z,0,
//	0 + base_x,shape_y + base_y,shape_z,0,
//	0,0,0,1
//};
//
//Matrix M_Shape = Matrix(shape, 9, 4);
//double rotate_X_th=0;
//double rotate_Y_th=0;
//double rotate_Z_th=0;
//
//double rotate_X_arr[16] = {
//	1,0,0,0,
//	0,cos(rotate_X_th),sin(rotate_X_th),0,
//	0,-sin(rotate_X_th),cos(rotate_X_th),0,
//	0,0,0,1
//};
//
//double rotate_Y_arr[16] = {
//	cos(rotate_Y_th),0,-sin(rotate_Y_th),0,
//	0,1,0,0,
//	sin(rotate_Y_th),0,cos(rotate_Y_th),0,
//	0,0,0,1
//};
//
//double rotate_Z_arr[16] = {
//	cos(rotate_Z_th),sin(rotate_Z_th),0,0,
//	-sin(rotate_Z_th),cos(rotate_Z_th),0,0,
//	0,0,1,0,
//	0,0,0,1
//};
//Matrix M_rotate_X = Matrix(rotate_X_arr, 4, 4);//绕x轴旋转的变换矩阵
//Matrix M_rotate_Y = Matrix(rotate_Y_arr, 4, 4);//绕y轴旋转的变换矩阵
//Matrix M_rotate_Z = Matrix(rotate_Z_arr, 4, 4);//绕z轴旋转的变换矩阵




