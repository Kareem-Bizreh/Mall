#pragma once
#include "Point.h"
class Closet
{
private:
	float rightDoorAngle = 0.0f;
	float leftDoorAngle = 0.0f;
public:
	void draw(Point center);
	void openDoors(float angle);
	void closeDoors(float angle);
};

