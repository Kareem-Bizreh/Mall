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
#include "Elevator.h"
class Outside {
private:
	Texture ground, mall_ground, side, right_door, left_door, mall_name, flag, stick, street, entry, platform, cafe_ad, market_ad, garage_street, sarot;
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
	void drawMarkets();
	void drawLake();
public:
	Elevator elevator;
	Door* doorMov = new Door{ Point(108 ,26 ,-15), 0.0, false };
	std::vector <Door*> Doors{
		cafe.doorMov,
		restaurant.doorMov,
		furnitureStore.doorMov,
		furnitureStore.drawerMov1,
		furnitureStore.drawerMov2,
		furnitureStore.closetMov1,
		furnitureStore.closetMov2
	};

	std::vector<Door*> elevatorDoors{
		elevator.elevatorDoor,
		elevator.elevatorDoorUp,
		elevator.elevatorDoorDown
	};

	Outside(Texture flagTexture);
	void OutsideTextures();
	void drawStreetLight(Point baseCenter, double poleHeight, double poleRadius, double armLength, double verticalArmLength, double lampSize, bool isLeftSide);
	void draw();
	void render3DModel(float x, float y, float z, float scale, Model_3DS* model);
	void drawFence();
};