#pragma once
#include "Vector2d.h"

struct Matrix2
{
	Vector2d basis1;
	Vector2d basis2;
	Matrix2(const Vector2d& one,const Vector2d& two) : basis1(one),basis2(two)
	{
	}
	Matrix2()
	{
		basis1=Vector2d(1,0);
		basis2=Vector2d(0,1);
	}
	Matrix2 Scale(float valuex,float valuey)
	{
		Matrix2 temp;
		temp.basis1.x *=valuex;
		temp.basis2.y *=valuey;
		return temp;
	}
	Matrix2 rotate(float angle)
	{
		Matrix2 temp;
		temp.basis1.x=cos(angle);
		temp.basis1.y=sin(angle);
		temp.basis2.x=-sin(angle);
		temp.basis2.y=cos(angle);
		return temp;
	}
};

inline Vector2d operator*(const Matrix2& op,const Vector2d& victim)
{
Vector2d result;
result.x=op.basis1.x * victim.x+ op.basis2.x*victim.y;
result.y=op.basis1.y* victim.x+ op.basis2.y*victim.y;
return result;
}
inline Matrix2 multiplymat2(const Matrix2& op,const Matrix2& po)
{
	Vector2d basisx=(op.basis1.x,op.basis2.x);
	Vector2d basisy=(op.basis2.y,op.basis2.y);
	Matrix2 temp;
	temp.basis1.x=dotproduct(basisx,po.basis1);
	temp.basis1.y=dotproduct(basisy,po.basis1);
	temp.basis2.x=dotproduct(basisx,po.basis2);
	temp.basis2.y=dotproduct(basisy,po.basis2);
	return temp;
}