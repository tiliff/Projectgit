#pragma once

#include <cmath>

struct Vector3d
{
	float x;
	float y;
	float z;
	Vector3d(float x =0, float y=0,float z=0) : x(x), y(y),z(z) {}
	operator const float*()
	{
		return &x;
	}
};
inline float dotpro(Vector3d one,Vector3d two)
{
	return (one.x*two.x)+(one.y*two.y)+(one.z*two.z);
}