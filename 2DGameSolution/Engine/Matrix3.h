#pragma once
#include "Vector3d.h"
#include "Vector2d.h"

struct Matrix3
{
	Vector3d basis1;
	Vector3d basis2;
	Vector3d basis3;
	Matrix3(const Vector3d& one,const Vector3d& two,const Vector3d& three) : basis1(one),basis2(two),basis3(three){}

	Matrix3()
	{
		basis1 = Vector3d(1,0,0);
		basis2 = Vector3d(0,1,0);
		basis3 = Vector3d(0,0,1);
	}
	static Matrix3 Scale(float valuex,float valuey)
	{
		Matrix3 temp;
		temp.basis1.x *=valuex;
		temp.basis2.y *=valuey;
		return temp;
	}
	static Matrix3 rotate(float angle)
{
	Matrix3 temp;
	temp.basis1.x=cos(angle);
	temp.basis1.y=sin(angle);
	temp.basis2.x=-sin(angle);
	temp.basis2.y=cos(angle);
	return temp;
}
static Matrix3 translate(float value,float valuey)
{
	Matrix3 temp;
	temp.basis1.z =value;
	temp.basis2.z =valuey;
	return temp;
}
};
inline Vector2d operator*(const Matrix3& op,const Vector2d& victim)
{
Vector2d result;
result.x=op.basis1.x * victim.x+ op.basis2.x*victim.y;
result.y=op.basis1.y* victim.x+ op.basis2.y*victim.y;
return result;
}
inline Vector3d operator*(const Matrix3& op,const Vector3d& victim)
{
	Vector3d result;
	result.x=dotpro(op.basis1,victim);
	result.y=dotpro(op.basis2,victim);
	result.z=dotpro(op.basis3,victim);
	return result;
}

inline Matrix3 multiplym(const Matrix3& op,const Matrix3& po)
{
	Matrix3 result;
	Vector3d basisx=Vector3d(op.basis1.x,op.basis2.x,op.basis3.x);
	Vector3d basisy=Vector3d(op.basis1.y,op.basis2.y,op.basis3.y);
	Vector3d basisz=Vector3d(op.basis1.z,op.basis2.z,op.basis3.z);
	result.basis1.x=dotpro(po.basis1,basisx);
	result.basis1.y=dotpro(po.basis1,basisy);
	result.basis1.z=dotpro(po.basis1,basisz);
	result.basis2.x=dotpro(po.basis2,basisx);
	result.basis2.y=dotpro(po.basis2,basisy);
	result.basis2.z=dotpro(po.basis2,basisz);
	result.basis3.x=dotpro(po.basis3,basisx);
	result.basis3.y=dotpro(po.basis3,basisy);
	result.basis3.z=dotpro(po.basis3,basisz);
	return result;
}



