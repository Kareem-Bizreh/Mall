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
#include "ElectronicDepartment.h"
#include "Fountain.h"

class Outside {
private:
	Texture ground, mall_ground, side, right_door, left_door, mall_name, flag, stick, street, entry, platform, cafe_ad, market_ad, garage_street, sarot, cafe_ad_o, market_ad_o;
	Texture sideWalk, grass, street3, floor;
	Flag wavingFlag;
	Lake lake;
	SuperMarket superMarket;
	FurnitureStore furnitureStore;
	Garage garage;
	Cafe cafe = Cafe(Point(0, 0, 0));
	Restaurant restaurant = Restaurant(Point(0, 0, 0));
	ElectronicDepartment electronicDepartment = ElectronicDepartment(0, 0, 0);
	Model_3DS* tree;
	Model_3DS* tank;
	Model_3DS* fence;
	Model_3DS* parkFountain;
	Door* doorMov = new Door{ Point(108 ,26 ,-15), 0.0, false };
	void drawMarkets();
	void drawLake();
public:
	Audio arrival_elevator, elevator_moving, open_door, close_door, Auto_door;
	Fountain fountain;
	Elevator elevator;
	std::vector <Door*> Doors{
		cafe.doorMov,
		restaurant.doorMov,
		furnitureStore.doorMov,
		furnitureStore.drawerMov1,
		furnitureStore.drawerMov2,
		furnitureStore.closetMov1,
		furnitureStore.closetMov2,
		electronicDepartment.techDoor,
		electronicDepartment.csDoor,
		electronicDepartment.mobileDoor
	};

	std::vector<Door*> AutoDoors{
		doorMov
	};

	std::vector<Door*> elevatorDoors{
		elevator.elevatorDoor,
		elevator.elevatorDoorUp,
		elevator.elevatorDoorDown
	};

	Outside(Texture flagTexture);
	void OutsideTextures();
	void loadAudios();
	void drawStreetLight(Point baseCenter, double poleHeight, double poleRadius, double armLength, double verticalArmLength, double lampSize, bool isLeftSide);
	void drawStatic();
	void drawDynamic();
	void render3DModel(float x, float y, float z, float scale, Model_3DS* model);
	void drawFence();
	void drawFencesOnSideWalk();
	void drawStreets();
	void drawFountain(const float WATER_COLOR[]);
	void setupShadows(Point baseCenter, double poleHeight, double poleRadius, double curveRadius, double curveAngle, double lampSize, bool isLeftSide);
	void computeShadowMatrix(GLfloat shadowMat[16], GLfloat plane[4], GLfloat lightPos[4]);
	void setupLighting(Point lightPosition);
	void drawStreetLightGeometry(Point baseCenter, double poleHeight, double poleRadius, double curveRadius, double curveAngle, double lampSize, bool isLeftSide);
};