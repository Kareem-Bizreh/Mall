#pragma once
#include "Cuboid.h"
#include "Texture.h"
#include "flag.h"
#include "Model_3DS.h"
#include "Point.h"
#include "SuperMarket.h"
#include "FurnitureStore.h"
#include "Cafe.h"
#include "Restaurant.h"
#include "Audio.h"
#include "Garage.h"

class Outside {
private:
	Texture ground, mall_ground, side, right_door, left_door, mall_name, flag, stick, street, entry,platform,cafe_ad,market_ad;
	Flag wavingFlag;
	SuperMarket superMarket;
	FurnitureStore furnitureStore;
	Garage garage;
	Cafe cafe = Cafe(Point(0, 0, 0));
	Restaurant restaurant = Restaurant(Point(0, 0, 0));
	Model_3DS* tree;
	void drawMarkets();
public:
	Outside(Texture flagTexture);
	void OutsideTextures();
	void drawStreetLight(Point baseCenter, double poleHeight, double poleRadius, double armLength, double verticalArmLength, double lampSize, bool isLeftSide);
	void draw();
	void render3DModel(float x, float y, float z, float scale, Model_3DS* model);
};