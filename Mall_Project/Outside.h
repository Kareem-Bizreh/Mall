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
#include "Lake.h"
#include "Cylinder.h"
#include <cmath> 
class Outside {
private:
	Texture ground, mall_ground, side, right_door, left_door, mall_name, flag, stick, street, entry, elevator, elevatorGround, elevatorHandle, elevatorDoorR, elevatorDoorL, elevatorDoorControl,platform, cafe_ad, market_ad,garage_street,sarot;
	Flag wavingFlag;
	Lake lake;
	SuperMarket superMarket;
	FurnitureStore furnitureStore;
	Garage garage;
	Cafe cafe = Cafe(Point(0, 0, 0));
	Restaurant restaurant = Restaurant(Point(0, 0, 0));
	Audio mallMusic;
	Model_3DS* tree;
	Model_3DS* tank;
	Door* elevatorDoor = new Door{ Point(22, 24.5, -288), 0.0, false };
	Door* elevatorDoorDown = new Door{ Point(22, 24.5, -288), 0.0, false };
	Door* elevatorDoorUp = new Door{ Point(22, 74.5, -287.9), 0.0, false };

	void drawMarkets();
	void drawLake();
	void drawElevator(double height);
public:
	std::vector <Door*> Doors{
		elevatorDoor,
		elevatorDoorDown,
		elevatorDoorUp
	};
	Outside(Texture flagTexture);
	void OutsideTextures();
	void drawStreetLight(Point baseCenter, double poleHeight, double poleRadius, double armLength, double verticalArmLength, double lampSize, bool isLeftSide);
	void draw();
	void render3DModel(float x, float y, float z, float scale, Model_3DS* model);
	void drawFence();
};