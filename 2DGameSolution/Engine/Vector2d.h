#pragma once
#include <cmath>


struct Vector2d
{
	float x;
	float y;
	Vector2d(float x =0, float y=0) : x(x), y(y) {}
	operator float*()
	{
		return &x;
	}
};
inline float length(Vector2d v)
{
	return sqrt(pow(v.x,2)+pow(v.y,2));
}
inline float dotlength(Vector2d v1)
{
	return ((v1.x*v1.x)+(v1.y*v1.y));
}
inline Vector2d operator+(const Vector2d& left, const Vector2d& right)
{
	return Vector2d(left.x + right.x, left.y +right.y);
}
inline Vector2d operator-(const Vector2d& left, const Vector2d& right)
{
	return Vector2d(left.x - right.x, left.y -right.y);
}
inline Vector2d operator*(float scaler, const Vector2d& right)
{
	return Vector2d(scaler * right.x, scaler * right.y);
}

inline Vector2d normalize(Vector2d v)
{
	Vector2d temp;
	if(v.x!=0 && v.y!=0)
	{
		temp=Vector2d(v.x*(1/(length(v))),v.y*(1/(length(v))));
	}
	return temp;
}
inline Vector2d perpcw(Vector2d v)
{
	return Vector2d(v.y,-v.x);
}
inline Vector2d perpccw(Vector2d v)
{
	return Vector2d(-v.y,v.x);
}
inline float crossProduct(Vector2d v1, Vector2d v2)
{
	return (v1.x*v2.y) - (v2.x*v1.y);
}
inline float dotproduct(Vector2d v1,Vector2d v2)
{
	return ((v1.x*v2.x)+(v1.y*v2.y));
}
inline Vector2d projection(Vector2d v1)
{
	return Vector2d((v1.x/(dotlength(v1))),(v1.y/(dotlength(v1))));
}
inline Vector2d lerpvector(float beta,Vector2d v1,Vector2d v2)
{
	Vector2d returnvector;
	if(beta >= 0 && beta <=1)
	{
		returnvector=((1-beta)*v1)+((beta)*v2);
	}
	return returnvector;
}
