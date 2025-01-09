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
	frontSide.loadTexture("textures/Outside/frontSide.jpg");
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

	Cuboid Floor_bottom(Point(105, 61.2, - 106), 0, 201, 200);
	Floor_bottom.drawWithTexture(mall_ground.textureID, 2, 2);
	Cuboid Floor_up(Point(105, 61.1, -106), 0, 201, 200);
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
	Front_BR.drawWithTexture(frontSide.textureID, 1, 1);

	Cuboid Front_BL(Point(165, 10, -5), 31, 0, 80);
	Front_BL.drawWithTexture(frontSide.textureID, 1, 1);

	Cuboid Right_Door(Point(97, 10.1, -4.9), 31, 1, 20);
	Right_Door.drawWithTexture(right_door.textureID, 1, 1);

	Cuboid Left_Door(Point(117, 10.1, -4.9), 31, 1, 20);
	Left_Door.drawWithTexture(left_door.textureID, 1, 1);


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
	Cylinder().draw(Point(165, 112.5, - 262), 12, 12, 112.5, 36, 36);
	glPopMatrix();


	glPushMatrix();
	glTranslated(149, 10, -227);
	glRotated(-90, 0, 1, 0);
	stairsMall().draw(Point(0, 0, 0));
	glPopMatrix();

	drawMarkets();

	render3DModel(105, 0, 150, 3.0, tank);

}