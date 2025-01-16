#pragma once
#include "Point.h"
#include "Texture.h"
#include "Door.h"

class Cafe
{
public:
	Cafe(Point c);
	Point center;
	Texture ground, sideWall, frontWall, sideTable, backWall, logo, door, fridge;
	Door* doorMov = new Door{ Point(153.5 ,25 ,-23), 0.0, false };

	void draw();
	void drawDynamic();
	void drawSideTable();
	void drawChair();
	void drawLight();
	void drawCup(bool fill = false);
	void cafeTextures();
};

