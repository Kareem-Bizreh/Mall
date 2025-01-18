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
	glTranslated(30.8, 61.3, -105.9);
	glRotated(90, 0, 1, 0);
	electronicDepartment.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(178.5, 61.3, -106.1);
	glRotated(-90, 0, 1, 0);
	furnitureStore.drawStore(Point(0, 0, 0));
	glPopMatrix();
}

void Outside::drawLake()
{
	glPushMatrix();
	glTranslated(80, 10, -75);
	lake.drawLake();
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
	electronicDepartment.loadTextures();
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
	street3.loadTexture("textures/Outside/street3.jpg");
	entry.loadTexture("textures/Outside/entry.jpg");
	platform.loadTexture("textures/Outside/platform.jpeg");
	cafe_ad.loadTexture("textures/Outside/cafe_ad.jpeg");
	market_ad.loadTexture("textures/Outside/market_ad.jpeg");
	tree = new Model_3DS();
	tree->Load((char*)"models/Outside/tree1_3ds/Tree1.3ds");
	fence = new Model_3DS();
	fence->Load((char*)"models/Outside/fence_3ds/fence.3ds");
	garage_street.loadTexture("textures/Outside/street2.jpg");
	sarot.loadTexture("textures/Outside/sarot.jpeg");
	cafe_ad_o.loadTexture("textures/Outside/cafe_ad_O.jpeg");
	market_ad_o.loadTexture("textures/Outside/market_ad_O.jpeg");
	sideWalk.loadTexture("textures/Outside/sidewalk.jpg");
	grass.loadTexture("textures/Outside/grass.jpg");
	lake.loadTextures();
	elevator.loadTextures();
}

void Outside::loadAudios()
{
	arrival_elevator.loadAudio("audios/elevator_arrival.wav");
	elevator_moving.loadAudio("audios/elevator_moving.wav");
	open_door.loadAudio("audios/open_door.wav");
	close_door.loadAudio("audios/close_door.wav");
	Auto_door.loadAudio("audios/automatic_door.wav");
}

void Outside::render3DModel(float x, float y, float z, float scale, Model_3DS* model) {
	if (!model) return;

	glPushMatrix();


	glTranslatef(x, y, z);
	glScalef(scale, scale, scale);


	model->Draw();

	glPopMatrix();
}


void Outside::drawFencesOnSideWalk() {
	//----------------------------------------------------first grass----------------------------------------------------------------
	//----------------------------------------------first side---------------------------------------------------

	//first fence 
	glPushMatrix();
	glTranslated(14.5, 0.5, 237.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//second fence 
	glPushMatrix();
	glTranslated(14.5, 0.5, 247.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//third fence 
	glPushMatrix();
	glTranslated(14.5, 0.5, 257.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fourth fence 
	glPushMatrix();
	glTranslated(14.5, 0.5, 267.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fifth fence 
	glPushMatrix();
	glTranslated(14.5, 0.5, 277.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();


	//----------------------------------------------second side---------------------------------------------------

	//first fence 
	glPushMatrix();
	glTranslated(65.5, 0.5, 237.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//second fence 
	glPushMatrix();
	glTranslated(65.5, 0.5, 247.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//third fence 
	glPushMatrix();
	glTranslated(65.5, 0.5, 257.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fourth fence 
	glPushMatrix();
	glTranslated(65.5, 0.5, 267.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fifth fence 
	glPushMatrix();
	glTranslated(65.5, 0.5, 277.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//----------------------------------------------third side---------------------------------------------------


	//first fence 
	render3DModel(56, 0.5, 227, 5, fence);

	//second fence 
	render3DModel(46, 0.5, 227, 5, fence);


	//third fence 
	render3DModel(14, 0.5, 227, 5, fence);

	//fourth fence 
	render3DModel(24, 0.5, 227, 5, fence);

	//----------------------------------------------fourth side---------------------------------------------------


	//first fence 
	render3DModel(56, 0.5, 278, 5, fence);

	//second fence 
	render3DModel(46, 0.5, 278, 5, fence);


	//third fence 
	render3DModel(14, 0.5, 278, 5, fence);

	//fourth fence 
	render3DModel(24, 0.5, 278, 5, fence);


	//----------------------------------------------------second grass----------------------------------------------------------------
	//----------------------------------------------first side---------------------------------------------------

	//first fence 
	glPushMatrix();
	glTranslated(-14.5, 0.5, 237.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//second fence 
	glPushMatrix();
	glTranslated(-14.5, 0.5, 247.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//third fence 
	glPushMatrix();
	glTranslated(-14.5, 0.5, 257.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fourth fence 
	glPushMatrix();
	glTranslated(-14.5, 0.5, 267.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fifth fence 
	glPushMatrix();
	glTranslated(-14.5, 0.5, 277.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();


	//----------------------------------------------second side---------------------------------------------------

	//first fence 
	glPushMatrix();
	glTranslated(-65.5, 0.5, 237.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//second fence 
	glPushMatrix();
	glTranslated(-65.5, 0.5, 247.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//third fence 
	glPushMatrix();
	glTranslated(-65.5, 0.5, 257.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fourth fence 
	glPushMatrix();
	glTranslated(-65.5, 0.5, 267.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fifth fence 
	glPushMatrix();
	glTranslated(-65.5, 0.5, 277.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//----------------------------------------------third side---------------------------------------------------


	//first fence 
	render3DModel(-66, 0.5, 227, 5, fence);

	//second fence 
	render3DModel(-56, 0.5, 227, 5, fence);


	//third fence 
	render3DModel(-34, 0.5, 227, 5, fence);

	//fourth fence 
	render3DModel(-24, 0.5, 227, 5, fence);

	//----------------------------------------------fourth side---------------------------------------------------


	//first fence 
	render3DModel(-66, 0.5, 278, 5, fence);

	//second fence 
	render3DModel(-56, 0.5, 278, 5, fence);


	//third fence 
	render3DModel(-34, 0.5, 278, 5, fence);

	//fourth fence 
	render3DModel(-24, 0.5, 278, 5, fence);


	//----------------------------------------------------third grass----------------------------------------------------------------
	//----------------------------------------------first side---------------------------------------------------

	//first fence 
	glPushMatrix();
	glTranslated(224.5, 0.5, 237.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//second fence 
	glPushMatrix();
	glTranslated(224.5, 0.5, 247.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//third fence 
	glPushMatrix();
	glTranslated(224.5, 0.5, 257.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fourth fence 
	glPushMatrix();
	glTranslated(224.5, 0.5, 267.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fifth fence 
	glPushMatrix();
	glTranslated(224.5, 0.5, 277.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();


	//----------------------------------------------second side---------------------------------------------------

	//first fence 
	glPushMatrix();
	glTranslated(275.5, 0.5, 237.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//second fence 
	glPushMatrix();
	glTranslated(275.5, 0.5, 247.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//third fence 
	glPushMatrix();
	glTranslated(275.5, 0.5, 257.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fourth fence 
	glPushMatrix();
	glTranslated(275.5, 0.5, 267.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fifth fence 
	glPushMatrix();
	glTranslated(275.5, 0.5, 277.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//----------------------------------------------third side---------------------------------------------------


	//first fence 
	render3DModel(266, 0.5, 227, 5, fence);

	//second fence 
	render3DModel(256, 0.5, 227, 5, fence);

	//third fence 
	render3DModel(234, 0.5, 227, 5, fence);

	//fourth fence 
	render3DModel(224, 0.5, 227, 5, fence);

	//----------------------------------------------fourth side---------------------------------------------------


	//first fence 
	render3DModel(266, 0.5, 278, 5, fence);

	//second fence 
	render3DModel(256, 0.5, 278, 5, fence);

	//third fence 
	render3DModel(234, 0.5, 278, 5, fence);

	//fourth fence 
	render3DModel(224, 0.5, 278, 5, fence);

	//----------------------------------------------------fourth grass----------------------------------------------------------------
	//----------------------------------------------first side---------------------------------------------------

	//first fence 
	glPushMatrix();
	glTranslated(144.5, 0.5, 237.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//second fence 
	glPushMatrix();
	glTranslated(144.5, 0.5, 247.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//third fence 
	glPushMatrix();
	glTranslated(144.5, 0.5, 257.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fourth fence 
	glPushMatrix();
	glTranslated(144.5, 0.5, 267.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fifth fence 
	glPushMatrix();
	glTranslated(144.5, 0.5, 277.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();


	//----------------------------------------------second side---------------------------------------------------

	//first fence 
	glPushMatrix();
	glTranslated(195.5, 0.5, 237.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//second fence 
	glPushMatrix();
	glTranslated(195.5, 0.5, 247.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//third fence 
	glPushMatrix();
	glTranslated(195.5, 0.5, 257.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fourth fence 
	glPushMatrix();
	glTranslated(195.5, 0.5, 267.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//fifth fence 
	glPushMatrix();
	glTranslated(195.5, 0.5, 277.5);
	glRotated(90, 0, 1, 0);
	render3DModel(0, 0, 0, 5, fence);
	glPopMatrix();

	//----------------------------------------------third side---------------------------------------------------


	//first fence 
	render3DModel(186, 0.5, 227, 5, fence);

	//second fence 
	render3DModel(176, 0.5, 227, 5, fence);

	//third fence 
	render3DModel(154, 0.5, 227, 5, fence);

	//fourth fence 
	render3DModel(144, 0.5, 227, 5, fence);

	//----------------------------------------------fourth side---------------------------------------------------


	//first fence 
	render3DModel(186, 0.5, 278, 5, fence);

	//second fence 
	render3DModel(176, 0.5, 278, 5, fence);

	//third fence 
	render3DModel(154, 0.5, 278, 5, fence);

	//fourth fence 
	render3DModel(144, 0.5, 278, 5, fence);
}
void Outside::drawStreets() {
	glColor3ub(255, 255, 255);
	// side right street 
	Cuboid(Point(315, -1, -62.5), 2, 815, 50).drawWithTexture(street3.textureID, 1, 7);
	//first street
	glPushMatrix();
	glTranslated(105, -1, 185);
	glRotated(90, 0, 1, 0);
	Cuboid(Point(0, 0, 0), 2, 370, 50).drawWithTexture(street3.textureID, 1, 5);
	glPopMatrix();

	//second street
	glPushMatrix();
	glTranslated(105,-1,320);
	glRotated(90, 0, 1, 0);
	Cuboid(Point(0, 0, 0), 2, 370, 50).drawWithTexture(street3.textureID, 1, 5);
	glPopMatrix();

	//third street
	Cuboid(Point(105, -1, 252.5), 2, 85, 50).drawWithTexture(street3.textureID, 1, 2);

	//first sidewalk
	Cuboid(Point(0, -1, 252.5), 2, 85, 160).drawWithTexture(sideWalk.textureID, 2, 2);
	Cuboid(Point(210, -1, 252.5), 2, 85, 160).drawWithTexture(sideWalk.textureID, 2, 2);

	//grass
	Cuboid(Point(40, 0.5, 252.5), 1, 50, 50).drawWithTexture(grass.textureID,1,1);
	Cuboid(Point(-40, 0.5, 252.5), 1, 50, 50).drawWithTexture(grass.textureID, 1, 1);
	Cuboid(Point(250, 0.5, 252.5), 1, 50, 50).drawWithTexture(grass.textureID, 1, 1);
	Cuboid(Point(170, 0.5, 252.5), 1, 50, 50).drawWithTexture(grass.textureID, 1, 1);

	drawFencesOnSideWalk();

}
void Outside::drawStatic() {
	drawLake();
	glPushMatrix();
	garage.draw();
	glPopMatrix();
	drawStreets();
	Cuboid Ground(Point(105, 0, -155), 10, 320, 220);
	Ground.drawWithTexture(ground.textureID, 2, 2);
	Cuboid Platform(Point(105, -1, -155), 2, 630, 370);
	Platform.drawWithTexture(platform.textureID, 9, 9);
	glPushMatrix();
	glTranslated(105, -1, -495);
	glRotated(90, 0, 1, 0);
	Cuboid Street(Point(0, 0, 0), 2, 470, 50);
	Street.drawWithTexture(street3.textureID, 1, 7);
	glPopMatrix();
	
	Cuboid Main_Street(Point(-105, -1, - 62.5), 2, 815, 50);
	Main_Street.drawWithTexture(street3.textureID, 1, 7);
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	Cuboid Top(Point(105, 113, -155), 0, 300, 200);
	Top.drawWithTexture(mall_ground.textureID, 0, 0);
	glColor3ub(255, 255, 255);
	glPopMatrix();

	Cuboid stick(Point(85, 113.1, -20.0), 60, 5, 5);
	stick.drawWithTexture(mall_ground.textureID, 1, 1);
	Cuboid Bottom(Point(105, 10.1, -155), 0, 300, 200);
	Bottom.drawWithTexture(mall_ground.textureID, 20, 20);

	Cuboid Entry(Point(105, 10.1, 0), 0, 10, 68);
	Entry.drawWithTexture(entry.textureID, 1, 1);

	Cuboid FloorB_left(Point(40, 61.21, -100), 0, 180, 70);
	Cuboid FloorB_right(Point(165, 61.22, -100), 0, 180, 80);
	Cuboid FloorB_front(Point(105, 61.23, -40), 0, 70, 200);
	Cuboid FloorB_back(Point(105, 61.24, -165), 0, 80, 200);

	FloorB_left.drawWithTexture(mall_ground.textureID, 0, 0);
	FloorB_right.drawWithTexture(mall_ground.textureID, 0, 0);
	FloorB_front.drawWithTexture(mall_ground.textureID, 0, 0);
	FloorB_back.drawWithTexture(mall_ground.textureID, 0, 0);

	Cuboid FloorU_left(Point(40, 61.51, -100), 0, 180, 70);
	Cuboid FloorU_right(Point(165, 61.52, -100), 0, 180, 80);
	Cuboid FloorU_front(Point(105, 61.53, -40), 0, 70, 200);
	Cuboid FloorU_back(Point(105, 61.54, -165), 0, 80, 200);

	FloorU_left.drawWithTexture(mall_ground.textureID, 6, 22);
	FloorU_right.drawWithTexture(mall_ground.textureID, 6, 22);
	FloorU_front.drawWithTexture(mall_ground.textureID, 16, 10);
	FloorU_back.drawWithTexture(mall_ground.textureID, 16, 10);
	drawFence();
	Cuboid Right(Point(205, 10, -155), 103, 300, 0);
	Right.drawWithTexture(side.textureID, 1, 1);

	Cuboid Left(Point(5, 10, -155), 103, 300, 0);
	Left.drawWithTexture(side.textureID, 1, 1);

	Cuboid Back(Point(105, 10, -305), 103, 0, 200);
	Back.drawWithTexture(side.textureID, 1, 1);
	Cuboid Sarot(Point(120, 60, -304.9), 50, 0, 50);
	Sarot.drawWithTexture(sarot.textureID, 1, 1);
	Cuboid Mall_Name(Point(110, 67, -4.9), 46.1, 0, 68);
	Mall_Name.drawWithTexture(mall_name.textureID, 1, 1);

	Cuboid Front_Top(Point(105, 41, -5), 72, 0, 200);
	Front_Top.drawWithTexture(side.textureID, 1, 1);

	Cuboid Front_BR_Outside(Point(46, 10, -5), 31, 0, 82);
	Front_BR_Outside.drawWithTexture(market_ad.textureID, 1, 1);

	Cuboid Front_BL_Outside(Point(165, 10, -5), 31, 0, 80);
	Front_BL_Outside.drawWithTexture(cafe_ad.textureID, 1, 1);

	Cuboid Front_BR_Inside(Point(46, 10, -5.1), 31, 0, 82);
	Front_BR_Inside.drawWithTexture(market_ad_o.textureID, 1, 1);

	Cuboid Front_BL_Inside(Point(165, 10, -5.1), 31, 0, 80);
	Front_BL_Inside.drawWithTexture(cafe_ad_o.textureID, 1, 1);

	Cuboid Stairs1(Point(105, 3, 10.1), -2.4, 10.1, 68);
	Stairs1.drawWithTexture(mall_ground.textureID, 2, 2);

	Cuboid Stairs2(Point(105, 6.5, 8.6), -3.51, 7.1, 68);
	Stairs2.drawWithTexture(mall_ground.textureID, 2, 2);

	Cuboid Stairs3(Point(105, 10, 7.6), -3.51, 5.1, 68);
	Stairs3.drawWithTexture(mall_ground.textureID, 2, 2);

	glPushMatrix();
	glColor3ub(88, 88, 88);
	Cuboid(Point(179, 10, -211), 102.5, 9, 51).draw();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(180, 180, 180);
	Cylinder().draw(Point(165, 112.5, -262), 12, 12, 112.5, 36, 36);
	glPopMatrix();

	render3DModel(105, 0, 150, 3.0, tank);
	drawStreetLight(Point(Platform.center.x - 130, Platform.center.y-1, Platform.center.z), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, false);
	render3DModel(Platform.center.x - 130, Platform.center.y, Platform.center.z + 25, 4, tree);

	drawStreetLight(Point(Platform.center.x - 130, Platform.center.y-1, Platform.center.z + 100), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, false);
	render3DModel(Platform.center.x - 130, Platform.center.y, Platform.center.z + 75, 4, tree);

	drawStreetLight(Point(Platform.center.x - 130, Platform.center.y-1, Platform.center.z + 50), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, false);
	render3DModel(Platform.center.x - 130, Platform.center.y, Platform.center.z - 25, 4, tree);


	drawStreetLight(Point(Platform.center.x - 130, Platform.center.y-1, Platform.center.z - 100), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, false);
	render3DModel(Platform.center.x - 130, Platform.center.y, Platform.center.z - 75, 4, tree);

	drawStreetLight(Point(Platform.center.x - 130, Platform.center.y, Platform.center.z - 50), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, false);

	drawStreetLight(Point(Platform.center.x + 130, Platform.center.y-1, Platform.center.z), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, true);
	render3DModel(Platform.center.x + 130, Platform.center.y, Platform.center.z + 25, 4, tree);

	drawStreetLight(Point(Platform.center.x + 130, Platform.center.y-1, Platform.center.z + 100), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, true);
	render3DModel(Platform.center.x + 130, Platform.center.y, Platform.center.z + 75, 4, tree);

	drawStreetLight(Point(Platform.center.x + 130, Platform.center.y-1, Platform.center.z + 50), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, true);
	render3DModel(Platform.center.x + 130, Platform.center.y, Platform.center.z - 25, 4, tree);


	drawStreetLight(Point(Platform.center.x + 130, Platform.center.y-1, Platform.center.z - 100), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, true);
	render3DModel(Platform.center.x + 130, Platform.center.y, Platform.center.z - 75, 4, tree);

	drawStreetLight(Point(Platform.center.x + 130, Platform.center.y-1, Platform.center.z - 50), 15.0f, 0.5f, 10.0f, 20.0f, 2.0f, true);

	glPushMatrix();
	glTranslated(72, 12, -290);
	glColor3f(0.7, 0.7, 0.7);
	Cuboid(Point(0, -2.1, 0), 2, 28, 34).drawWithTexture(mall_ground.textureID, 1, 1);
	elevator.draw();
	glTranslated(0, 47.9, 50);
	Cuboid(Point(0, 1.6, -1.5), 0, 73, 28).drawWithTexture(mall_ground.textureID, 2, 8);
	glColor3f(1, 1, 1);
	glPopMatrix();

	drawMarkets();

	// draw stairs
	glPushMatrix();
	glTranslated(149, 10, -227);
	glRotated(-90, 0, 1, 0);
	stairsMall().draw(Point(0, 0, 0));
	glPopMatrix();

	// draw glass for elevator
	glPushMatrix();
	glTranslated(72, 12, -290);
	glTranslated(0, 47.9, 50);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(163, 163, 163, 182);
	Cuboid(Point(13, 1.7, -1), 13.5, 72, 1).draw();
	Cuboid(Point(-13, 1.7, -1), 13.5, 72, 1).draw();
	glColor3f(1, 1, 1);
	glDisable(GL_BLEND);
	glPopMatrix();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(163, 163, 163, 182);
	glPushMatrix();
	glTranslated(57, 59.75, -227);
	glRotated(-90, 0, 1, 0);
	Cuboid(Point(21.5, 2, -0.4), 13.30, 4, 1).draw();
	glPopMatrix();
	glColor3f(1, 1, 1);
	glDisable(GL_BLEND);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(163, 163, 163, 182);
	glPushMatrix();
	glTranslated(105.5, 59.75, -227);
	glRotated(-90, 0, 1, 0);
	Cuboid(Point(22, 1.9, 0), 13.3, 41, 1).draw();
	glPopMatrix();
	glColor3f(1, 1, 1);
	glDisable(GL_BLEND);
}

void Outside::drawDynamic()
{
	glPushMatrix();
	glTranslated(80, 11, -75);
	lake.drawWater();
	glPopMatrix();

	Flag wavingFlag(Point(105, 163, -20.0), 20, 50, 40, 10, 30, flag, stick);
	wavingFlag.setWaveProperties(0.1f, 2.0f, 1.0f);
	glColor3ub(255, 255, 255);
	glPushMatrix();
	wavingFlag.drawWavingFlag();
	glPopMatrix();

	Cuboid Right_Door(Point(97 - doorMov->OpenRate * 15, 10.2, -4.9), 31, 1, 20);
	Right_Door.drawWithTexture(right_door.textureID, 1, 1);

	Cuboid Left_Door(Point(117 + doorMov->OpenRate * 15, 10.2, -4.9), 31, 1, 20);
	Left_Door.drawWithTexture(left_door.textureID, 1, 1);

	glPushMatrix();
	glTranslated(179, 10.3, -48);
	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	cafe.drawDynamic();
	glPopMatrix();

	glTranslated(0, 0, -42.5 - 7.6);

	glPushMatrix();
	glTranslated(0, 0, -42.5 - 15.1);
	glRotated(-90, 0, 1, 0);
	restaurant.drawDynamic();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(72, 12, -290);
	elevator.drawDynamic();
	glColor3f(1, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(178.5, 61.3, -106.1);
	glRotated(-90, 0, 1, 0);
	furnitureStore.drawDynamic(Point(0, 0, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(30.8, 61.3, -105.9);
	glRotated(90, 0, 1, 0);
	electronicDepartment.drawDynamic();
	glPopMatrix();
}

inline double toRadians(double degrees) {
	return degrees * M_PI / 180.0;
}

void Outside::drawStreetLight(Point baseCenter, double poleHeight, double poleRadius, double curveRadius, double curveAngle, double lampSize, bool isLeftSide)
{
	GLUquadric* quad = gluNewQuadric();

	Point currentPosition = baseCenter;

	Point verticalArmStart(baseCenter.x, baseCenter.y + poleHeight - 12, baseCenter.z - 0.1);
	glColor3ub(101, 67, 33);
	glPushMatrix();
	glTranslated(verticalArmStart.x, verticalArmStart.y, verticalArmStart.z);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, poleRadius + 0.2, poleRadius + 0.2, poleHeight + 23, 32, 32);
	glPopMatrix();

	currentPosition.z += poleHeight - 15.1;
	double angleStep = 2.0;

	int curveDirection = isLeftSide ? -1 : 1;

	for (double angle = 0; angle <= 180; angle += angleStep)
	{
		glPushMatrix();
		glTranslated(currentPosition.x, currentPosition.y + 40, currentPosition.z);
		glRotated(-90, 1, 0, 0);
		gluCylinder(quad, poleRadius + 0.2, poleRadius + 0.2, angleStep / 360.0 * curveRadius * 2 * M_PI + 0.25, 32, 32);
		glPopMatrix();

		double angleNext = angle + angleStep;
		currentPosition.x += curveRadius * (cos(toRadians(angleNext)) - cos(toRadians(angle))) * curveDirection;
		currentPosition.y += curveRadius * (sin(toRadians(angleNext)) - sin(toRadians(angle)));
	}
	Point lampPosition(currentPosition.x, currentPosition.y, currentPosition.z);
	this->setupLighting(lampPosition);
	this->setupShadows(baseCenter, poleHeight, poleRadius, curveRadius, curveAngle, lampSize, isLeftSide);
	glPushMatrix();
	glColor3ub(255, 255, 0);
	glTranslated(lampPosition.x, lampPosition.y + 40, lampPosition.z);
	glutSolidSphere(lampSize, 20, 20);
	glPopMatrix();

	glColor3ub(255, 255, 255);
}

void drawSphere(Point center, float radius) {
	glPushMatrix();
	glTranslated(center.x, center.y, center.z);
	glutSolidSphere(radius, 20, 20);
	glPopMatrix();
}

void Outside::drawFence() {
	Point cylinderPositions[5] = {
		{74, 72, -126},
		{74, 72, -74},
		{125, 72, -74},
		{125, 72, -126},

	};

	float cylinderRadius = 1.0f;
	float cylinderHeight = 10.0f;

	for (int i = 0; i < 5; i++) {
		glColor3ub(128, 128, 128);
		Cylinder().draw(cylinderPositions[i], cylinderRadius, cylinderRadius, cylinderHeight, 20, 20);

		glColor3ub(70, 70, 70);
		Point sphereCenter = { cylinderPositions[i].x, cylinderPositions[i].y, cylinderPositions[i].z };
		drawSphere(sphereCenter, 2.0f);
	}


	float cuboidWidth = 2.0f;
	float cuboidHeight = 2.0f;


	{
		double cuboidLength = fabs(cylinderPositions[1].z - cylinderPositions[0].z);
		Point midpoint = {
			cylinderPositions[0].x,
			cylinderPositions[0].y + cylinderHeight / 2 - 10,
			(cylinderPositions[0].z + cylinderPositions[1].z) / 2
		};
		glColor3ub(98, 98, 98);
		Cuboid horizontalCuboid(midpoint, cuboidHeight, cuboidLength, cuboidWidth);
		horizontalCuboid.draw();
	}

	{
		double cuboidLength = fabs(cylinderPositions[3].z - cylinderPositions[2].z);
		Point midpoint = {
			cylinderPositions[2].x,
			cylinderPositions[2].y + cylinderHeight / 2 - 10,
			(cylinderPositions[2].z + cylinderPositions[3].z) / 2
		};
		glColor3ub(98, 98, 98);
		Cuboid horizontalCuboid(midpoint, cuboidHeight, cuboidLength, cuboidWidth);
		horizontalCuboid.draw();
	}

	{
		double cuboidLength = fabs(cylinderPositions[2].x - cylinderPositions[1].x);
		Point midpoint = {
			(cylinderPositions[1].x + cylinderPositions[2].x) / 2,
			cylinderPositions[1].y + cylinderHeight / 2 - 10,
			cylinderPositions[1].z
		};
		glColor3ub(98, 98, 98);
		Cuboid verticalCuboid(midpoint, cuboidHeight, cuboidWidth, cuboidLength);
		verticalCuboid.draw();
	}

	{
		double cuboidLength = fabs(cylinderPositions[3].x - cylinderPositions[0].x);
		Point midpoint = {
			(cylinderPositions[0].x + cylinderPositions[3].x) / 2,
			cylinderPositions[0].y + cylinderHeight / 2 - 10,
			cylinderPositions[0].z
		};

		glColor3ub(98, 98, 98);
		Cuboid verticalCuboid(midpoint, cuboidHeight, cuboidWidth, cuboidLength);
		verticalCuboid.draw();
	}

	glColor3ub(255, 255, 255);
}

void Outside::drawFountain(const float WATER_COLOR[])
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4fv(WATER_COLOR);
	fountain.render();
	glDisable(GL_BLEND);
}
void Outside::setupShadows(Point baseCenter, double poleHeight, double poleRadius, double curveRadius, double curveAngle, double lampSize, bool isLeftSide) {
	GLfloat groundHeight = 1.0f;
	GLfloat groundPlane[4] = { 0.0f, 1.0f, 0.0f, -groundHeight };

	GLfloat rightWallPlane[4] = { -1.0f, 0.0f, 0.0f, 205.0f };
	GLfloat leftWallPlane[4] = { 1.0f, 0.0f, 0.0f, -5.0f };

	GLfloat offsetX = isLeftSide ? 150.0f : -150.0f;
	GLfloat offsetY = 130.0f, offsetZ = 20.0f;
	GLfloat lightPosition[4] = { baseCenter.x + offsetX, baseCenter.y + poleHeight + offsetY, baseCenter.z + offsetZ, 1.0 };

	GLfloat groundShadowMatrix[16];
	GLfloat rightWallShadowMatrix[16];
	GLfloat leftWallShadowMatrix[16];

	computeShadowMatrix(groundShadowMatrix, groundPlane, lightPosition);
	 
	offsetX = isLeftSide ? 150.0f : -150.0f;
	offsetY = 50.0f, offsetZ = 20.0f;
	lightPosition[0]= baseCenter.x + offsetX;
	lightPosition[1] = baseCenter.y + poleHeight + offsetY;
	lightPosition[2] = baseCenter.z + offsetZ;
	lightPosition[3] = 1.0;
	computeShadowMatrix(rightWallShadowMatrix, rightWallPlane, lightPosition);
	computeShadowMatrix(leftWallShadowMatrix, leftWallPlane, lightPosition);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDisable(GL_LIGHTING);

	glPushMatrix();
	glMultMatrixf(groundShadowMatrix);
	glColor4f(0.1f, 0.1f, 0.1f, 0.5f);
	drawStreetLightGeometry(baseCenter, poleHeight, poleRadius, curveRadius, curveAngle, lampSize, isLeftSide);
	glPopMatrix();

	glPushMatrix();
	glMultMatrixf(rightWallShadowMatrix);
	glColor4f(0.1f, 0.1f, 0.1f, 0.5f);
	drawStreetLightGeometry(baseCenter, poleHeight, poleRadius, curveRadius, curveAngle, lampSize, isLeftSide);
	glPopMatrix();

	glPushMatrix();
	glMultMatrixf(leftWallShadowMatrix);
	glColor4f(0.1f, 0.1f, 0.1f, 0.5f);
	drawStreetLightGeometry(baseCenter, poleHeight, poleRadius, curveRadius, curveAngle, lampSize, isLeftSide);
	glPopMatrix();

	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
}
void Outside::computeShadowMatrix(GLfloat shadowMat[16], GLfloat plane[4], GLfloat lightPos[4]) {
	GLfloat dot = plane[0] * lightPos[0] +
		plane[1] * lightPos[1] +
		plane[2] * lightPos[2] +
		plane[3] * lightPos[3];

	shadowMat[0] = dot - lightPos[0] * plane[0];
	shadowMat[4] = -lightPos[0] * plane[1];
	shadowMat[8] = -lightPos[0] * plane[2];
	shadowMat[12] = -lightPos[0] * plane[3];

	shadowMat[1] = -lightPos[1] * plane[0];
	shadowMat[5] = dot - lightPos[1] * plane[1];
	shadowMat[9] = -lightPos[1] * plane[2];
	shadowMat[13] = -lightPos[1] * plane[3];

	shadowMat[2] = -lightPos[2] * plane[0];
	shadowMat[6] = -lightPos[2] * plane[1];
	shadowMat[10] = dot - lightPos[2] * plane[2];
	shadowMat[14] = -lightPos[2] * plane[3];

	shadowMat[3] = -lightPos[3] * plane[0];
	shadowMat[7] = -lightPos[3] * plane[1];
	shadowMat[11] = -lightPos[3] * plane[2];
	shadowMat[15] = dot - lightPos[3] * plane[3];
}
void Outside::drawStreetLightGeometry(Point baseCenter, double poleHeight, double poleRadius, double curveRadius, double curveAngle, double lampSize, bool isLeftSide)
{
	GLUquadric* quad = gluNewQuadric();

	Point verticalArmStart(baseCenter.x, baseCenter.y + poleHeight - 12, baseCenter.z - 0.1);
	glPushMatrix();
	glTranslated(verticalArmStart.x, verticalArmStart.y, verticalArmStart.z);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, poleRadius + 0.2, poleRadius + 0.2, poleHeight + 23, 32, 32);
	glPopMatrix();

	Point currentPosition = baseCenter;
	currentPosition.z += poleHeight - 15.1;
	double angleStep = 2.0;
	int curveDirection = isLeftSide ? -1 : 1;

	gluDeleteQuadric(quad); 
}
void Outside::setupLighting(Point lightPosition)
{
	GLfloat LightPos[] = { lightPosition.x, lightPosition.y, lightPosition.z, 1.0f };
	GLfloat LightAmb[] = { 1.0f,1.0f,1.0f,1.0f };
	GLfloat LightDiff[] = { 1.0f,1.0f,1.0f,1.0f };
	GLfloat LightSpec[] = { 1.0f,1.0f,1.0f,1.0f };


	GLfloat MatAmb[] = { 1.0f,1.0f,1.0f,1.0f };
	GLfloat MatDif[] = { 0.8f,0.8f,0.8f,1.0f };
	GLfloat MatSpec[] = { 0.5f,0.5f,0.5f,1.0f };

	GLfloat MatShn[] = { 50.0f };

	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_POSITION, LightPos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec);

	glEnable(GL_LIGHTING);
	glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MatDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MatSpec);
	glMaterialfv(GL_FRONT, GL_SHININESS, MatShn);
	glEnable(GL_COLOR_MATERIAL);
}
