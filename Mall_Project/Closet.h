#pragma once
#include "Point.h"
#include "Texture.h"
#include "Door.h"
class Closet
{
public:
	float rightDoorAngle = 120.0f;
	float leftDoorAngle = 120.0f;
	Texture rightDoor, leftDoor, wood;
	void draw(Point center);
	void drawDynamic(Point center);
	void openDoors(float angle);
	void closeDoors(float angle);
	Door* closetMov;
};

