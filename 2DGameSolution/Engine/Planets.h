#pragma once
#include "core.h"
#include "vector2d.h"
#include "matrix3.h"


class Planets
{
 public:
	 Planets()
	 {

	 }
	void drawplanets(int numrecurse,Matrix3 mat,Core::Graphics& g);
	void updateplanets(float dt);
};