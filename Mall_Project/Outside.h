#pragma once
#include "Cuboid.h"
#include "Texture.h"
#include "flag.h"
#include "stairsMall.h"
#include "Model_3DS.h"
#include "Point.h"
#include "SuperMarket.h"
#include "FurnitureStore.h"
#include "Cafe.h"
#include "Restaurant.h"
#include "Audio.h"
#include "Garage.h"
#include "Door.h"
class Outside {
private:
	Texture ground, mall_ground, side, right_door, left_door, mall_name, flag, stick, street, entry, frontSide, elevator, elevatorGround, elevatorHandle, elevatorDoorR, elevatorDoorL, elevatorDoorControl;
	Flag wavingFlag;
	SuperMarket superMarket;
	FurnitureStore furnitureStore;
	Garage garage;
	Cafe cafe = Cafe(Point(0, 0, 0));
	Restaurant restaurant = Restaurant(Point(0, 0, 0));
	Audio mallMusic;
	Model_3DS* tank;
	Door* elevatorDoor = new Door{ Point(22, 24.5, -288), 0.0, false };
	Door* elevatorDoorDown = new Door{ Point(22, 24.5, -288), 0.0, false };
	Door* elevatorDoorUp = new Door{ Point(22, 74.5, -287.9), 0.0, false };

	bool isInsideMall = false;
	void drawMarkets();
	void drawElevator(double height);
public:
	std::vector <Door*> Doors{
		elevatorDoor,
		elevatorDoorDown,
		elevatorDoorUp
	};
	Outside(Texture flagTexture);
	void OutsideTextures();

	void draw();
	void render3DModel(float x, float y, float z, float scale, Model_3DS* model);
};