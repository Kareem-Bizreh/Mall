#pragma once
#include "Point.h"
#include "Texture.h"

class Restaurant
{
public:
	Restaurant(Point c);
	Point center;
	Texture ground, wall, chair, table, logo, door, frontStove, topStove, washBasin, sideWash, metal, cabinet , shelf;
	void draw();
	void drawChair();
	void drawLight();
	void drawLights();
	void drawWaterTap();
	void drawSideChairs();
	void drawSideTable();
	void drawKitchen();
	void restaurantTextures();
};

