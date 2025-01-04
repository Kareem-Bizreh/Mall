#pragma once
#include "Point.h"
#include "Texture.h"
#include "Closet.h"
#include "Sofa.h"
#include "Cylinder.h"
class FurnitureStore
{
private:
	void drawTable(Point center);
	void drawGround(Point center);
	void drawMonitor(Point center);
	void drawDrawer(Point center);
	void drawChair(Point center);
	void drawCarpet(Point center);
	void drawDiningTable(Point center);
public:
	void moveDrawer(float offset);
	void drawStore(Point center);
	void loadTextures();

	float drawerOffset = 0.0f;
	Sofa sofa1, sofa2, sofa3;
	Closet closet1, closet2;
	Cylinder cylinder;
	Texture floor, wall, laptopScreen, keyBoard, woodTable, money, woodChair, carpet;
};

