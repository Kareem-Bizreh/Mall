#pragma once
#include "Point.h"
#include "Texture.h"

class Cafe
{
public:
	Cafe(Point c);
	Point center;
	Texture ground, sideWall, frontWall, sideTable, backWall, logo, door, fridge;
	void draw();
	void drawSideTable();
	void drawChair();
	void drawLight();
	void drawCup(bool fill = false);
	void cafeTextures();
};

