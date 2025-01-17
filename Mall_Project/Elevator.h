#pragma once
#include "Door.h"
#include "Texture.h"
class Elevator
{
public:
	Door* elevatorDoor = new Door{ Point(72, 24.5, -300), 1.0, true };
	Door* elevatorDoorDown = new Door{ Point(72, 24.5, -285), 1.0, true };
	Door* elevatorDoorUp = new Door{ Point(72, 74.5, -285), 0.0, false };
	void draw();
	void drawDynamic();
	void loadTextures();
	double height;//max 50 , min 0
	bool up, in;
private:
	Texture elevator, elevatorGround, elevatorHandle, elevatorDoorR, elevatorDoorL, elevatorDoorControl;
};

