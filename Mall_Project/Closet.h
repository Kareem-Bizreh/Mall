#pragma once
#include "Point.h"
#include "Texture.h"
class Closet
{
private:
	float rightDoorAngle = 0.0f;
	float leftDoorAngle = 0.0f;
public:
	Texture rightDoor,leftDoor,wood;
	void draw(Point center);
	void openDoors(float angle);
	void closeDoors(float angle);
};

