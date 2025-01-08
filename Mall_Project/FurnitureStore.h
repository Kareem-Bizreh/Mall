#pragma once
#include "Point.h"
#include "Texture.h"
#include "Closet.h"
#include "Sofa.h"
#include "Cylinder.h"
#include "Model_3DS.h"
class FurnitureStore
{
private:
	void drawTable(Point center);
	void drawGround(Point center);
	void drawMonitor(Point center);
	void drawDrawer(Point center);
	void drawChair(Point center);
	void drawSeat(Point center);
	void drawSeat2(Point center);
	void drawCarpet(Point center);
	void drawCircularTable(Point center);
	void drawBed(Point center,GLint textureId,GLint woodTexture);
	void drawSemiCircle(Point center, float radius, float thickness, int segments, GLint textureId);
	void drawDoubleBed(Point center);
	void drawDrawers(Point center);
	void drawDiningTable(Point center);
	void drawSeats(Point center);
	void drawSeats2(Point center);
	void drawShelves(Point center);
	void drawMirror(Point center);
	void drawDiningTable2(Point center);
public:
	void moveDrawer(float offset);
	void drawStore(Point center);
	void loadTextures();

	float drawerOffset = 0.0f, drawer2Offset = 0.0f, drawer3Offset = 0.0f;
	double leftDoorAngle = 0.0,rightDoorAngle;
	Sofa sofa1, sofa2, sofa3;
	Closet closet1, closet2;
	Cylinder cylinder;
	Texture floor, wall, laptopScreen, keyBoard, woodTable, money, woodChair;
	Texture carpet, wood, chair, bed, bed2, bedwood, bedleg, drawer;
	Texture leftDoor, rightDoor,leftWall,rightWall,furniture,woodChair2,woodTable2;
};

