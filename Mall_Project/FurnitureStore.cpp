#include<gl/glut.h>
#include "FurnitureStore.h"
#include "Point.h"
#include "Cuboid.h"
#include "Closet.h"
#include "Sofa.h"
#include "Cylinder.h"

void FurnitureStore::loadTextures() {
	keyBoard.loadTexture("textures\\FurnitureStore\\keyboard.jpg");
	laptopScreen.loadTexture("textures\\FurnitureStore\\laptop.png");
	woodTable.loadTexture("textures\\FurnitureStore\\wood.jpg");
	floor.loadTexture("textures\\FurnitureStore\\Carpet.jpg");
	money.loadTexture("textures\\FurnitureStore\\dollar.jpg");
	woodChair.loadTexture("textures\\FurnitureStore\\wood2.jpg");
	wall.loadTexture("C:\\Users\\ASUS\\Desktop\\pictures\\WoodFloor017_2K-JPG\\WoodFloor017_2K-JPG_Color.jpg");
	carpet.loadTexture("textures\\FurnitureStore\\Carpet.jpg");
}
void FurnitureStore::drawStore(Point center) {
	this->drawGround(center);


	glPushMatrix();
	glScaled(1.5, 1.5, 2);
	this->drawDiningTable(Point(center.x - 10, center.y, center.z));
	glPopMatrix();

	glPushMatrix();
	glTranslated(center.x - 85, center.y + 0.1, center.z);
	glScaled(0.5, 0.5, 0.5);
	this->drawTable(Point(0, 0, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(center.x - 85, center.y + 8.1, center.z - 3);
	glScaled(0.5, 0.5, 0.5);
	this->drawMonitor(Point(0, 0, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(center.x - 92.5, center.y + 4, center.z - 3.9);
	glScaled(0.5, 0.5, 0.5);
	this->drawDrawer(Point(0, 0, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(center.x - 85, center.y + 0.1, center.z - 14);
	glScaled(0.5, 0.5, 0.5);
	this->drawChair(Point(0, 0, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(center.x - 60, center.y + 1.3, center.z - 20);
	glScaled(1.5, 2, 1);
	closet1.draw(Point(0, 0, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(center.x - 40, center.y + 1.3, center.z - 20);
	glScaled(1.5, 2, 1);
	closet2.draw(Point(0, 0, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(center.x - 10, center.y + 3.1, center.z - 20);
	glScaled(1.5, 1, 1);
	sofa1.draw(Point(0, 0, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(center.x + 5, center.y + 3.1, center.z - 5);
	glRotated(270, 0, 1, 0);
	glScaled(1.5, 1, 1);
	sofa2.draw(Point(0, 0, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(center.x - 25, center.y + 3.1, center.z);
	//glScaled(1.5, 1, 1);
	glRotated(90, 0, 1, 0);
	sofa3.drawTriple(Point(0, 0, 0));
	glPopMatrix();

	this->drawCarpet(Point(center.x + 40, center.y + 3.1, center.z));
}

void FurnitureStore::drawGround(Point center) {
	glColor3ub(255, 255, 255);

	Cuboid(Point(center.x, center.y + 0.1, center.z), 1, 50, 200).drawWithTexture(floor.textureID, 15, 3);

	Cuboid(Point(center.x + 100.5, center.y + 0.1, center.z), 50, 50, 1).drawWithTexture(wall.textureID, 1, 1);

	Cuboid(Point(center.x, center.y + 0.1, center.z - 25.5), 50, 1, 202).drawWithTexture(wall.textureID, 4, 1);

	Cuboid(Point(center.x - 100.5, center.y + 0.1, center.z), 50, 50, 1).drawWithTexture(wall.textureID, 1, 1);
}

void FurnitureStore::drawTable(Point center) {

	glColor3ub(255, 255, 255);
	Cuboid(Point(center.x, center.y, center.z), 15, 1, 40).drawWithTexture(woodTable.textureID, 3, 4);

	Cuboid(Point(center.x - 20.5, center.y, center.z - 7), 15, 15, 1).drawWithTexture(woodTable.textureID, 3, 3);

	Cuboid(Point(center.x + 20.5, center.y, center.z - 7), 15, 15, 1).drawWithTexture(woodTable.textureID, 3, 3);

	Cuboid(Point(center.x, center.y + 15, center.z - 7), 1, 15, 42).drawWithTexture(woodTable.textureID, 3, 4);
}


void FurnitureStore::drawMonitor(Point center) {
	glColor3ub(255, 255, 255);

	//keyboard texture
	glPushMatrix();
	glTranslated(center.x, center.y + 0.1, center.z - 5);
	glRotated(180, 0, 1, 0);
	Cuboid(Point(0, 0, 0), 0.1, 3, 6).drawWithTexture(keyBoard.textureID, 1, 1);
	glPopMatrix();

	//laptop screen texture
	glPushMatrix();
	glTranslated(center.x, center.y + 2, center.z - 0.1);
	glRotated(180, 0, 1, 0);
	Cuboid(Point(0, 0, 0), 5, 0.2, 7).drawWithTexture(laptopScreen.textureID, 1, 1);
	glPopMatrix();

	//monitor
	glColor3ub(10, 10, 10);
	Cuboid(Point(center.x, center.y + 2, center.z), 5, 0.2, 7).draw();

	//stand
	glColor3ub(66, 66, 66);
	Cuboid(Point(center.x, center.y, center.z), 2, 0.2, 1).draw();

	//base 
	glColor3ub(36, 36, 36);
	Cuboid(Point(center.x, center.y, center.z), 0.5, 4, 4).draw();

}

void FurnitureStore::drawDrawer(Point center) {
	glColor3ub(255, 255, 255);
	center.z += drawerOffset;
	//money texture
	Cuboid(Point(center.x, center.y + 0.5, center.z), 0.5, 13, 9).drawWithTexture(money.textureID, 2, 2);
	//base drawer
	Cuboid(Point(center.x, center.y, center.z), 0.5, 14, 10).drawWithTexture(woodTable.textureID, 1, 1);

	//right side
	Cuboid(Point(center.x + 5.25, center.y, center.z), 7, 14, 0.5).drawWithTexture(woodTable.textureID, 1, 1);

	//left side
	Cuboid(Point(center.x - 5.25, center.y, center.z), 7, 14, 0.5).drawWithTexture(woodTable.textureID, 1, 1);

	//back side
	Cuboid(Point(center.x, center.y + 0.5, center.z + 6.75), 6.5, 0.5, 10).drawWithTexture(woodTable.textureID, 1, 1);

	//front side
	Cuboid(Point(center.x, center.y + 0.5, center.z - 6.75), 6.5, 0.5, 10).drawWithTexture(woodTable.textureID, 1, 1);

}

void FurnitureStore::drawChair(Point center) {
	glColor3ub(33, 33, 33);

	//right front side
	Cuboid(Point(center.x + 5, center.y, center.z + 4), 11, 1, 1).draw();

	//left front side
	Cuboid(Point(center.x - 5, center.y, center.z + 4), 11, 1, 1).draw();

	//right back side
	Cuboid(Point(center.x + 5, center.y, center.z - 4), 11, 1, 1).draw();

	//left back side
	Cuboid(Point(center.x - 5, center.y, center.z - 4), 11, 1, 1).draw();

	//base chair
	Cuboid(Point(center.x, center.y + 11, center.z), 0.5, 10, 12).draw();

	//back chair
	Cuboid(Point(center.x, center.y + 11.5, center.z - 4.7), 10, 0.5, 12).draw();
}

void FurnitureStore::drawCarpet(Point center)
{
	glColor3ub(255, 255, 255);
	Cuboid(Point(center.x, center.y, center.z), 0.1, 5, 5);
}

void FurnitureStore::drawDiningTable(Point center) {
	//table legs
	cylinder.draw(Point(center.x + 2, center.y + 4.1, center.z), 0.2, 3, 20);
	cylinder.draw(Point(center.x - 2, center.y + 4.1, center.z), 0.2, 3, 20);
	cylinder.draw(Point(center.x + 2, center.y + 4.1, center.z + 2), 0.2, 3, 20);
	cylinder.draw(Point(center.x - 2, center.y + 4.1, center.z + 2), 0.2, 3, 20);

	//table base
	glColor3ub(126, 132, 247);
	Cuboid(Point(center.x, center.y + 4.1, center.z + 1), 0.5, 3, 6).draw();

}

void FurnitureStore::moveDrawer(float offset) {
	drawerOffset += offset;
}