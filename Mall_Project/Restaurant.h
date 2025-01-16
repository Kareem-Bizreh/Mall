#pragma once
#include "Point.h"
#include "Texture.h"
#include "Door.h"

class Restaurant
{
public:
	Restaurant(Point c);
	Point center;
	Texture ground, wall, chair, table, logo, door, frontStove, topStove, washBasin, sideWash, metal, cabinet , shelf;
	Door* doorMov = new Door{ Point(153.5 ,25 ,-210), 0.0, false };
	void draw();
	void drawDynamic();
	void drawChair();
	void drawLight();
	void drawLights();
	void drawWaterTap();
	void drawSideChairs();
	void drawSideTable();
	void drawKitchen();
	void restaurantTextures();
};

