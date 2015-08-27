#pragma once
#include "particlemath.h"
#include "Core.h"
using Core::RGB;
struct colorness
{
	float r,g,b;
	randomness ryan;
    public:
       RGB varyColor(RGB colors,int variance)
	   {
		   r=GetRValue(colors);
		   r=r-variance+ryan.randomInRange(0,variance*2+1.0f);
		   g=GetGValue(colors);
		   g=g-variance+ryan.randomInRange(0,variance*2+1.0f);
		   b=GetBValue(colors);
		   b=b-variance+ryan.randomInRange(0,variance*2+1.0f);
		   if(r>255)
			   r=255;
		   if(r<0)
			   r=0;
		   if(g>255)
			   g=255;
		   if(g<0)
			   g=0;
		   if(b>255)
			   b=255;
		   if(b<0)
			   b=0;
		   return RGB(r,g,b);
	   }
	 RGB brightness(RGB color,float brightvalue)
	 {
       r=(GetRValue(color)*brightvalue);
	   g=(GetRValue(color)*brightvalue);
	   b=(GetRValue(color)*brightvalue);
	   return RGB(r,g,b);
	 }
};