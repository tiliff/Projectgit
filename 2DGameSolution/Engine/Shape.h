#pragma once
#include "Core.h"
#include "Vector2d.h"
class Shape
{
	int numLines;
	Vector2d* lines;
public:
	Shape(int lineCount,Vector2d* lineArray)
	{
		numLines=lineCount;
		lines=lineArray;
	}

	void Draw(Core::Graphics& g, Vector2d where)
	{
     for(int i = 0;i<numLines;i++)
	  {
		  g.DrawLine(lines[i].x + where.x ,lines[i].y+ where.y, lines[i+1%numLines].x+ where.x ,lines[i+1%numLines].y+where.y);
	  }
	}
};