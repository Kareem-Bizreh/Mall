#include "Outside.h"

void Outside::drawMarkets()
{
	glPushMatrix();
	glTranslated(179, 10.3, -48);
	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	cafe.draw();
	glPopMatrix();
	glTranslated(0, 0, -42.5 - 7.6);
	glColor3f(0.7, 0.7, 0.7);
	Cuboid(Point(0, 0, 0), 50, 15, 50).draw();
	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslated(0, 0, -42.5 - 15.1);
	glRotated(-90, 0, 1, 0);
	restaurant.draw();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(58.1, 10.3, -5.2);
	glRotated(90, 0, 1, 0);
	superMarket.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(178.5, 61.3, -106.1);
	glRotated(-90, 0, 1, 0);
	furnitureStore.drawStore(Point(0, 0, 0));
	glPopMatrix();
}

Outside::Outside(Texture texture)
	: wavingFlag(Point(105, 135, -155), 200, 100, 0, 20, 30, flag, stick) {
};

void Outside::OutsideTextures() {
	furnitureStore.loadTextures();
	cafe.cafeTextures();
	superMarket.loadTextures();
	restaurant.restaurantTextures();
	garage.loadTexturesAndModels();
	ground.loadTexture("textures/Outside/ground.jpg");
	mall_ground.loadTexture("textures/Outside/mall_ground.jpg");
	side.loadTexture("textures/Outside/side.jpg");
	right_door.loadTexture("textures/Outside/right_door.jpg");
	left_door.loadTexture("textures/Outside/left_door.jpg");
	mall_name.loadTexture("textures/Outside/mall_name.jpg");
	flag.loadTexture("textures/Outside/flag.jpg");
	stick.loadTexture("textures/Outside/stick.jpg");
	street.loadTexture("textures/Outside/street.jpg");
	entry.loadTexture("textures/Outside/entry.jpg");
	platform.loadTexture("textures/Outside/platform.jpeg");
	cafe_ad.loadTexture("textures/Outside/cafe_ad.jpeg");
	market_ad.loadTexture("textures/Outside/market_ad.jpeg");
	tree = new Model_3DS();
	tree->Load((char*)"models/Outside/tree1_3ds/Tree1.3ds");
}


void Outside::render3DModel(float x, float y, float z, float scale, Model_3DS* model) {
	if (!model) return;

	glPushMatrix();


	glTranslatef(x, y, z);
	glScalef(scale, scale, scale);
	model->Draw();

	glPopMatrix();
}



void Outside::draw() {
	glPushMatrix();
	garage.draw();
	glPopMatrix();

	Cuboid Ground(Point(105, 0, -155), 10, 320, 220);
	Ground.drawWithTexture(ground.textureID, 2, 2);

	Cuboid Platform(Point(105, -1, -155), 2, 630, 400);
	Platform.drawWithTexture(platform.textureID, 2, 2);
	Cuboid Street(Point(105, 1, -495), 0.5, 50, 200);
	Street.drawWithTexture(street.textureID, 1, 1);
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	Cuboid Top(Point(105, 113, -155), 0, 300, 200);
	Top.drawWithTexture(mall_ground.textureID, 0, 0);
	glColor3ub(255, 255, 255);
	glPopMatrix();
	Flag wavingFlag(Point(105, 163, -20.0), 20, 50, 40, 10, 30, flag, stick);
	wavingFlag.setWaveProperties(0.1f, 2.0f, 1.0f);
	glColor3ub(255, 255, 255);
	glPushMatrix();
	wavingFlag.drawWavingFlag();
	glPopMatrix();

	Cuboid stick(Point(85, 113.1, -20.0), 60, 5, 5);
	stick.drawWithTexture(mall_ground.textureID, 1, 1);


	Cuboid Bottom(Point(105, 10.1, -155), 0, 300, 200);
	Bottom.drawWithTexture(mall_ground.textureID, 2, 2);

	Cuboid Entry(Point(105, 10.1, 0), 0, 10, 68);
	Entry.drawWithTexture(entry.textureID, 1, 1);

	Cuboid Floor_bottom(Point(105, 61.2, -155), 0, 300, 200);
	Floor_bottom.drawWithTexture(mall_ground.textureID, 2, 2);
	Cuboid Floor_up(Point(105, 61.1, -155), 0, 300, 200);
	Floor_up.drawWithTexture(mall_ground.textureID, 0, 0);

	Cuboid Right(Point(205, 10, -155), 103, 300, 0);
	Right.drawWithTexture(side.textureID, 1, 1);

	Cuboid Left(Point(5, 10, -155), 103, 300, 0);
	Left.drawWithTexture(side.textureID, 1, 1);

	Cuboid Back(Point(105, 10, -305), 103, 0, 200);
	Back.drawWithTexture(side.textureID, 1, 1);

	Cuboid Mall_Name(Point(110, 67, -4.9), 46.1, 0, 68);
	Mall_Name.drawWithTexture(mall_name.textureID, 1, 1);

	Cuboid Front_Top(Point(105, 41, -5), 72, 0, 200);
	Front_Top.drawWithTexture(side.textureID, 1, 1);
	Cuboid Front_BR(Point(46, 10, -5), 31, 0, 82);
	Front_BR.drawWithTexture(market_ad.textureID, 1, 1);
	Cuboid Front_BL(Point(165, 10, -5), 31, 0, 80);
	Front_BL.drawWithTexture(cafe_ad.textureID, 1, 1);
	Cuboid Right_Door(Point(97, 10.2, -4.9), 31, 1, 20);

	Right_Door.drawWithTexture(right_door.textureID, 1, 1);

	Cuboid Left_Door(Point(117, 10.2, -4.9), 31, 1, 20);
	Left_Door.drawWithTexture(left_door.textureID, 1, 1);


	Cuboid Stairs1(Point(105, 3, 10.1), -2.4, 10.1, 68);
	Stairs1.drawWithTexture(mall_ground.textureID, 2, 2);

	Cuboid Stairs2(Point(105, 6.5, 8.6), -3.51, 7.1, 68);
	Stairs2.drawWithTexture(mall_ground.textureID, 2, 2);

	Cuboid Stairs3(Point(105, 10, 7.6), -3.51, 5.1, 68);
	Stairs3.drawWithTexture(mall_ground.textureID, 2, 2);
	drawMarkets();
	drawStreetLight(Point(Platform.center.x-130, Platform.center.y, Platform.center.z), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, true); 
	render3DModel(Platform.center.x - 130, Platform.center.y, Platform.center.z+25, 4, tree);

	drawStreetLight(Point(Platform.center.x - 130, Platform.center.y, Platform.center.z+100), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, true); 
	render3DModel(Platform.center.x - 130, Platform.center.y, Platform.center.z+75, 4, tree);

	drawStreetLight(Point(Platform.center.x - 130, Platform.center.y, Platform.center.z+50), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, true); 
	render3DModel(Platform.center.x - 130, Platform.center.y, Platform.center.z-25, 4, tree);


	drawStreetLight(Point(Platform.center.x - 130, Platform.center.y, Platform.center.z-100), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, true);
	render3DModel(Platform.center.x - 130, Platform.center.y, Platform.center.z-75, 4, tree);
	
	drawStreetLight(Point(Platform.center.x - 130, Platform.center.y, Platform.center.z -50), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, true); 

	drawStreetLight(Point(Platform.center.x + 130, Platform.center.y, Platform.center.z), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, false); 
	render3DModel(Platform.center.x + 130, Platform.center.y, Platform.center.z + 25, 4, tree);

	drawStreetLight(Point(Platform.center.x + 130, Platform.center.y, Platform.center.z + 100), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, false); 
	render3DModel(Platform.center.x + 130, Platform.center.y, Platform.center.z + 75, 4, tree);

	drawStreetLight(Point(Platform.center.x + 130, Platform.center.y, Platform.center.z + 50), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, false); 
	render3DModel(Platform.center.x + 130, Platform.center.y, Platform.center.z - 25, 4, tree);


	drawStreetLight(Point(Platform.center.x + 130, Platform.center.y, Platform.center.z - 100), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, false); 
	render3DModel(Platform.center.x + 130, Platform.center.y, Platform.center.z - 75, 4, tree);

	drawStreetLight(Point(Platform.center.x + 130, Platform.center.y, Platform.center.z - 50), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, false); 
}

void Outside::drawStreetLight(Point baseCenter, double poleHeight, double poleRadius, double armLength, double verticalArmLength, double lampSize, bool isLeftSide)
{
	glColor3ub(101, 67, 33);
	Cuboid pole(baseCenter, poleHeight, poleRadius, poleRadius);
	pole.draw();

	Point verticalArmStart(baseCenter.x, baseCenter.y + poleHeight, baseCenter.z);
	Cuboid verticalArm(verticalArmStart, verticalArmLength, poleRadius, poleRadius);
	verticalArm.draw();

	double horizontalOffset = (isLeftSide ? -armLength : armLength);
	Point horizontalArmStart(verticalArmStart.x, verticalArmStart.y + verticalArmLength, verticalArmStart.z);
	Point horizontalArmCenter(horizontalArmStart.x + horizontalOffset / 2, horizontalArmStart.y, horizontalArmStart.z);
	Cuboid horizontalArm(horizontalArmCenter, poleRadius, 0, poleRadius + 10);
	horizontalArm.draw();

	glPushMatrix();
	glColor3ub(255, 255, 0); 
	glTranslated(horizontalArmStart.x + horizontalOffset, horizontalArmStart.y - lampSize * 2 + 2, horizontalArmStart.z); // Move downward
	glutSolidSphere(lampSize, 20, 20);
	glPopMatrix();
	glColor3ub(255, 255, 255);
}
