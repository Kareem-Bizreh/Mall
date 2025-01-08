#include<gl/glut.h>
#include "FurnitureStore.h"
#include "Point.h"
#include "Cuboid.h"
#include "Closet.h"
#include "Sofa.h"
#include "Cylinder.h"
#define M_PI 3.141592653589793

void FurnitureStore::loadTextures() {
	keyBoard.loadTexture("textures\\FurnitureStore\\keyboard.jpg");
	laptopScreen.loadTexture("textures\\FurnitureStore\\laptop.png");
	woodTable.loadTexture("textures\\FurnitureStore\\wood.jpg");
	floor.loadTexture("textures\\FurnitureStore\\floor.jpg");
	money.loadTexture("textures\\FurnitureStore\\dollar.jpg");
	woodChair.loadTexture("textures\\FurnitureStore\\wood2.jpg");
	wall.loadTexture("textures\\FurnitureStore\\storeWall.jpg");
	carpet.loadTexture("textures\\FurnitureStore\\Carpet.jpg");
	//bedBack.loadTexture("textures\\FurnitureStore\\bedBack.jpg");
	wood.loadTexture("textures\\FurnitureStore\\wood2.jpg");
	chair.loadTexture("textures\\FurnitureStore\\chair.jpg");
	bed.loadTexture("textures\\FurnitureStore\\bed3.jpg");
	bed2.loadTexture("textures\\FurnitureStore\\bed4.jpg");
	bedwood.loadTexture("textures\\FurnitureStore\\wood2.jpg");
	closet1.rightDoor.loadTexture("textures\\FurnitureStore\\leftDoor.png");
	closet1.leftDoor.loadTexture("textures\\FurnitureStore\\rightDoor.png");
	closet2.rightDoor.loadTexture("textures\\FurnitureStore\\leftDoor.png");
	closet2.leftDoor.loadTexture("textures\\FurnitureStore\\rightDoor.png");
	closet1.wood.loadTexture("textures\\FurnitureStore\\closetwood.jpg");
	closet2.wood.loadTexture("textures\\FurnitureStore\\closetwood.jpg");
	drawer.loadTexture("textures\\FurnitureStore\\drawer.png");
	bedleg.loadTexture("textures\\FurnitureStore\\bed.jpg");
	leftDoor.loadTexture("textures\\FurnitureStore\\leftDoor.jpg");
	rightDoor.loadTexture("textures\\FurnitureStore\\rightDoor.jpg");
	rightWall.loadTexture("textures\\FurnitureStore\\rightWall.jpg");
	leftWall.loadTexture("textures\\FurnitureStore\\leftWall.jpg");
	furniture.loadTexture("textures\\FurnitureStore\\furnitureStore.jpg");
	woodChair2.loadTexture("textures\\FurnitureStore\\wood4.jpg");
	woodTable2.loadTexture("textures\\FurnitureStore\\wood5.jpg");
}
void FurnitureStore::drawStore(Point center) {
	//glColor3ub(111, 111, 111);
	this->drawGround(center);

	//darw shelves 
	glPushMatrix();
	//glRotated(180, 0, 1, 0);
	this->drawShelves(Point(center.x + 67, center.y + 20, center.z - 23));
	glPopMatrix();

	//draw dining table
	glPushMatrix();
	glTranslated(center.x - 10, center.y + 7.1, center.z - 10);
	glScaled(1, 0.8, 1);
	glRotated(90, 0, 1, 0);
	this->drawDiningTable(Point(0,0,0));
	glPopMatrix();

	glPushMatrix();
	this->drawDiningTable2(Point(center.x - 45, center.y + 6.8, center.z - 8));
	glPopMatrix();
	
	//seats
	this->drawSeats2(center);

	//seats
	this->drawSeats(center);

	//closets
	glPushMatrix();
	glTranslated(center.x + 99.5, center.y + 1.5, center.z + 15);
	glRotated(-90, 0, 1, 0);
	glScaled(1.5, 2, 1);
	closet1.draw(Point(0, 0, 0));
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(center.x + 99.5, center.y + 1.5, center.z - 10);
	glRotated(-90, 0, 1, 0);
	glScaled(1.5, 2, 1);
    closet2.draw(Point(0, 0, 0));
    glPopMatrix();

	//beds
	glPushMatrix();
	glTranslated(center.x + 75, center.y + 4.1, center.z - 14);
	glRotated(90, 0, 1, 0);
	this->drawBed(Point(0,0,0),bed.textureID,wood.textureID);
	glPopMatrix();

	glPushMatrix();
	glTranslated(center.x + 54.5, center.y + 4.1, center.z - 14);
	glRotated(90, 0, 1, 0);
	this->drawBed(Point(0, 0, 0),bed2.textureID,bedwood.textureID);
	glPopMatrix();

	//drawer
	glPushMatrix();
	glTranslated(center.x + 65, center.y + 1.2, center.z - 22.5);
	glScaled(0.8, 0.8, 0.8);
	this->drawDrawers(Point(0,0,0));
	glPopMatrix();

	//double bed
	glPushMatrix();
	glTranslated(center.x + 67, center.y + 4.1, center.z + 18);
	glRotated(180, 0, 1, 0);
	this->drawDoubleBed(Point(0, 0, 0));
	glPopMatrix();

	//double bed
	glPushMatrix();
	glTranslated(center.x + 30, center.y + 4.1, center.z + 18);
	glRotated(180, 0, 1, 0);
	this->drawDoubleBed(Point(0, 0, 0));
	glPopMatrix();

	//glPushMatrix();
	//glTranslated(center.x, center.y + 4, center.z + 5);
	////glRotated(90, 0, 1, 0);
	//this->drawDoubleBed(Point(0, 0, 0));
	//glPopMatrix();

	//sofa
	glPushMatrix();
	glTranslated(center.x + 40, center.y + 3.1, center.z - 8);
	glRotated(-90, 0, 1, 0);
	glScaled(1.5, 1, 1);
	sofa1.draw(Point(0, 0, 0));
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(center.x + 25, center.y + 3.1, center.z - 20);
	//glRotated(270, 0, 1, 0);
	glScaled(1.5, 1, 1);
	sofa2.draw(Point(0, 0, 0));
	glPopMatrix();
	 
	glPushMatrix();
	glTranslated(center.x + 10, center.y + 3.1, center.z - 6);
	//glScaled(1, 1, 1.5);
	glRotated(90, 0, 1, 0);
	sofa3.drawTriple(Point(0, 0, 0));
	glPopMatrix();


	glPushMatrix();
	this->drawCircularTable(Point(center.x + 24, center.y + 1.5, center.z - 8.5));
	glPopMatrix();

	//this->drawCarpet(Point(center.x, center.y + 4, center.z));

	//glPushMatrix();
	//glScaled(1.5, 1.5, 2);
	//this->drawDiningTable(Point(center.x - 10, center.y, center.z));
	//glPopMatrix();

	//office
	glPushMatrix();
	glTranslated(center.x - 85, center.y + 0.1, center.z - 10);
	glScaled(0.5, 0.5, 0.5);
	this->drawTable(Point(0, 0, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(center.x - 85, center.y + 8.1, center.z - 13);
	glScaled(0.5, 0.5, 0.5);
	this->drawMonitor(Point(0, 0, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(center.x - 92.5, center.y + 4, center.z - 13.9);
	glScaled(0.5, 0.5, 0.5);
	this->drawDrawer(Point(0, 0, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(center.x - 85, center.y + 0.1, center.z - 21);
	glScaled(0.5, 0.5, 0.5);
	this->drawChair(Point(0, 0, 0));
	glPopMatrix();


	//draw mirror
	this->drawMirror(Point(center.x, center.y, center.z));
}

void FurnitureStore::drawSeats(Point center) {
	//first seat
	glPushMatrix();
	glTranslated(center.x , center.y + 3, center.z - 20);
	glRotated(-60, 0, 1, 0);
	glScaled(0.7, 1, 1.2);
	this->drawSeat(Point(0, 0, 0));
	glPopMatrix();

	//second seat
	glPushMatrix();
	glTranslated(center.x + 2, center.y + 3, center.z - 10);
	glRotated(-90, 0, 1, 0);
	glScaled(0.7, 1, 1.2);
	this->drawSeat(Point(0, 0, 0));
	glPopMatrix();

	//third seat
	glPushMatrix();
	glTranslated(center.x , center.y + 3, center.z );
	glRotated(-120, 0, 1, 0);
	glScaled(0.7, 1, 1.2);
	this->drawSeat(Point(0, 0, 0));
	glPopMatrix();

	//fourth seat 
	glPushMatrix();
	glTranslated(center.x - 20, center.y + 3, center.z - 20);
	glRotated(+ 60, 0, 1, 0);
	glScaled(0.7, 1, 1.2);
	this->drawSeat(Point(0, 0, 0));
	glPopMatrix();

	//fifth seat
	glPushMatrix();
	glTranslated(center.x - 22, center.y + 3, center.z - 10);
	glRotated(90, 0, 1, 0);
	glScaled(0.7, 1, 1.2);
	this->drawSeat(Point(0, 0, 0));
	glPopMatrix();

	//sixth seat
	glPushMatrix();
	glTranslated(center.x - 20, center.y + 3, center.z);
	glRotated(+120, 0, 1, 0);
	glScaled(0.7, 1, 1.2);
	this->drawSeat(Point(0, 0, 0));
	glPopMatrix();

}
void FurnitureStore::drawSeats2(Point center) {
	//first seat
	glPushMatrix();
	glTranslated(center.x - 45, center.y + 4.5, center.z - 21.5);
	glScaled(0.7, 1, 1.2);
	this->drawSeat2(Point(0, 0, 0));
	glPopMatrix();

	//second seat
	glPushMatrix();
	glTranslated(center.x - 35, center.y + 4.5, center.z - 17);
	glRotated(-70, 0, 1, 0);
	glScaled(0.7, 1, 1.2);
	this->drawSeat2(Point(0, 0, 0));
	glPopMatrix();

	//third seat
	glPushMatrix();
	glTranslated(center.x - 55, center.y + 4.5, center.z - 17);
	glRotated(70, 0, 1, 0);
	glScaled(0.7, 1, 1.2);
	this->drawSeat2(Point(0, 0, 0));
	glPopMatrix();

	//fourth seat
	glPushMatrix();
	glTranslated(center.x - 58, center.y + 4.5, center.z - 9);
	glRotated(90, 0, 1, 0);
	glScaled(0.7, 1, 1.2);
	this->drawSeat2(Point(0, 0, 0));
	glPopMatrix();

	//fifth seat
	glPushMatrix();
	glTranslated(center.x - 32, center.y + 4.5, center.z - 9);
	glRotated(-90, 0, 1, 0);
	glScaled(0.7, 1, 1.2);
	this->drawSeat2(Point(0, 0, 0));
	glPopMatrix();

	//fifth seat
	glPushMatrix();
	glTranslated(center.x - 45, center.y + 4.5, center.z + 6);
	glRotated(180, 0, 1, 0);
	glScaled(0.7, 1, 1.2);
	this->drawSeat2(Point(0, 0, 0));
	glPopMatrix();

	//seventh seat
	glPushMatrix();
	glTranslated(center.x - 34, center.y + 4.5, center.z + 2);
	glRotated(220, 0, 1, 0);
	glScaled(0.7, 1, 1.2);
	this->drawSeat2(Point(0, 0, 0));
	glPopMatrix();

	//eighth seat
	glPushMatrix();
	glTranslated(center.x - 56.5, center.y + 4.5, center.z + 2);
	glRotated(-220, 0, 1, 0);
	glScaled(0.7, 1, 1.2);
	this->drawSeat2(Point(0, 0, 0));
	glPopMatrix();
}

void FurnitureStore::drawSeat2(Point center) {
	glColor3ub(255, 255, 255);
	Cuboid(Point(center.x, center.y, center.z), 0.5, 4, 7).drawWithTexture(woodChair2.textureID, 1, 1);

	Cuboid(Point(center.x - 3.25, center.y + 0.5, center.z - 1.75), 6, 0.5, 0.5).drawWithTexture(woodChair2.textureID,1,1);

	Cuboid(Point(center.x - 3.25, center.y + 0.5, center.z + 1.75), 2, 0.5, 0.5).drawWithTexture(woodChair2.textureID, 1, 1);
	
	Cuboid(Point(center.x + 3.25, center.y + 0.5, center.z + 1.75), 2, 0.5, 0.5).drawWithTexture(woodChair2.textureID, 1, 1);
	
	Cuboid(Point(center.x + 3.25, center.y + 0.5, center.z - 1.75), 6, 0.5, 0.5).drawWithTexture(woodChair2.textureID, 1, 1);

	Cuboid(Point(center.x - 3.25, center.y + 2.5, center.z + 0.25),0.5,3.5,0.5).drawWithTexture(woodChair2.textureID, 1, 1);

	Cuboid(Point(center.x + 3.25, center.y + 2.5, center.z + 0.25), 0.5, 3.5, 0.5).drawWithTexture(woodChair2.textureID, 1, 1);

	//backs
	Cuboid(Point(center.x, center.y + 4.5, center.z - 1.75), 2, 0.5, 6).drawWithTexture(woodChair2.textureID, 1, 1);
	
	Cuboid(Point(center.x - 2, center.y + 0.5, center.z - 1.75), 4, 0.5, 0.5).drawWithTexture(woodChair2.textureID, 1, 1);

	Cuboid(Point(center.x - 1, center.y + 0.5, center.z - 1.75), 4, 0.5, 0.5).drawWithTexture(woodChair2.textureID, 1, 1);

	Cuboid(Point(center.x - 0, center.y + 0.5, center.z - 1.75), 4, 0.5, 0.5).drawWithTexture(woodChair2.textureID, 1, 1);

	Cuboid(Point(center.x + 1, center.y + 0.5, center.z - 1.75), 4, 0.5, 0.5).drawWithTexture(woodChair2.textureID, 1, 1);

	Cuboid(Point(center.x + 2, center.y + 0.5, center.z - 1.75), 4, 0.5, 0.5).drawWithTexture(woodChair2.textureID, 1, 1);

	//Cuboid(Point(center.x + 2.75, center.y, center.z - 1.75), 4.5, 0.5, 0.5).draw();


	//legs
	Cuboid(Point(center.x + 3.25, center.y - 3.5, center.z + 1.75), 3.5, 0.5, 0.5).drawWithTexture(woodChair2.textureID, 1, 1);

	Cuboid(Point(center.x - 3.25, center.y - 3.5, center.z + 1.75), 3.5, 0.5, 0.5).drawWithTexture(woodChair2.textureID, 1, 1);

	Cuboid(Point(center.x + 3.25, center.y - 3.5, center.z - 1.75), 3.5, 0.5, 0.5).drawWithTexture(woodChair2.textureID, 1, 1);

	Cuboid(Point(center.x - 3.25, center.y - 3.5, center.z - 1.75), 3.5, 0.5, 0.5).drawWithTexture(woodChair2.textureID, 1, 1);
}

void FurnitureStore::drawMirror(Point center) {
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(70, 169, 247, 50);
	//Cuboid(Point(center.x + 16.7, center.y , center.z + 25.5), 20, 1, 168.6).draw();
	Cuboid(Point(center.x + 86, center.y + 7, center.z + 25.5), 43, 1, 30).draw();

	Cuboid(Point(center.x + 46, center.y + 7, center.z + 25.5), 43, 1, 30).draw();

	Cuboid(Point(center.x + 6, center.y + 7, center.z + 25.5), 43, 1, 30).draw();

	Cuboid(Point(center.x - 34, center.y + 7, center.z + 25.5), 43, 1, 30).draw();

	Cuboid(Point(center.x - 63.25, center.y + 7, center.z + 25.5), 43, 1, 8.5).draw();

	glDisable(GL_BLEND);
}
void FurnitureStore::drawGround(Point center) {
	glColor3ub(255, 255, 255);

	Cuboid(Point(center.x, center.y + 0.1, center.z), 1, 50, 200).drawWithTexture(floor.textureID, 15, 3);

	Cuboid(Point(center.x + 100.5, center.y + 0.1, center.z), 50, 50, 1).drawWithTexture(wall.textureID, 3, 3);

	Cuboid(Point(center.x, center.y + 0.1, center.z - 25.5), 50, 1, 202).drawWithTexture(wall.textureID, 10, 3);

	Cuboid(Point(center.x - 100.5, center.y + 0.1, center.z), 50, 50, 1).drawWithTexture(wall.textureID, 3, 3);

	Cuboid(Point(center.x - 84.2, center.y + 20, center.z + 25.5),30,1,33.5).drawWithTexture(wall.textureID,2,2);

	Cuboid(Point(center.x + 16.7, center.y , center.z + 25.5),7,1,168.5).drawWithTexture(wall.textureID, 11, 1);

	Cuboid(Point(center.x + 66, center.y + 7, center.z + 25.5),43,1,10).drawWithTexture(wall.textureID, 1, 3);

	Cuboid(Point(center.x + 26, center.y + 7, center.z + 25.5), 43, 1, 10).drawWithTexture(wall.textureID, 1, 3);

	Cuboid(Point(center.x - 14, center.y + 7, center.z + 25.5), 43, 1, 10).drawWithTexture(wall.textureID, 1, 3);

	Cuboid(Point(center.x - 54, center.y + 7, center.z + 25.5), 43, 1, 10).drawWithTexture(wall.textureID, 1, 3);

	Cuboid(Point(center.x - 84.2, center.y + 20, center.z + 26), 10, 0.2, 33.5).drawWithTexture(furniture.textureID, 1, 1);
	//Cuboid().drawWithTexture(wall.textureID, 1, 5);
	
	Cuboid(Point(center.x, center.y + 50.1, center.z), 1, 52, 202).drawWithTexture(wall.textureID, 12, 3);
	//doors
	glPushMatrix();
	glTranslated(center.x - 94, center.y + 0.1, center.z + 26);
	glRotated(leftDoorAngle,0,1,0);
	glTranslated(-(center.x - 94), -(center.y + 0.1), -(center.z + 26));
	Cuboid(Point(center.x - 89, center.y + 0.1, center.z + 25.5), 20, 1, 10).drawWithTexture(leftDoor.textureID, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(center.x - 74.5, center.y + 0.1, center.z + 26);
	glRotated(rightDoorAngle, 0, 1, 0);
	glTranslated(-(center.x - 74.5), -(center.y + 0.1), -(center.z + 26));
	Cuboid(Point(center.x - 79.5, center.y + 0.1, center.z + 25.5), 20, 1, 10).drawWithTexture(rightDoor.textureID, 1, 1);
	glPopMatrix();

	//wall of doors
	Cuboid(Point(center.x - 97.5, center.y + 0.1, center.z + 25.5),20,1,7).drawWithTexture(leftWall.textureID,1,1);
	Cuboid(Point(center.x - 71, center.y + 0.1, center.z + 25.5), 20, 1, 7).drawWithTexture(rightWall.textureID, 1, 1);
}
void FurnitureStore::drawShelves(Point center) {
	glColor3ub(70, 70, 70);
	Cuboid(Point(center.x, center.y, center.z), 0.5, 4, 20).draw();

	Cuboid(Point(center.x, center.y + 12, center.z), 0.5, 4, 20.75).draw();

	Cuboid(Point(center.x + 10.1, center.y, center.z), 12, 4, 0.5).draw();
	Cuboid(Point(center.x - 10.1, center.y, center.z), 12, 4, 0.5).draw();

	glColor3ub(155, 155, 155);
	Cuboid(Point(center.x + 7.8, center.y + 6, center.z), 0.5, 4, 4).draw();
	Cuboid(Point(center.x - 7.8, center.y + 6, center.z), 0.5, 4, 4).draw();

	Cuboid(Point(center.x + 5.6, center.y + 4, center.z), 4, 4, 0.5).draw();
	Cuboid(Point(center.x - 5.6, center.y + 4, center.z), 4, 4, 0.5).draw();

	Cuboid(Point(center.x , center.y + 8, center.z), 0.5, 4, 11.75).draw();
	Cuboid(Point(center.x , center.y + 3.5, center.z), 0.5, 4, 11.75).draw();


	Cuboid(Point(center.x - 1.5, center.y + 8.5, center.z), 3.5, 4, 0.5).draw();
	Cuboid(Point(center.x + 2.5, center.y + 8.5, center.z), 3.5, 4, 0.5).draw();
	
	Cuboid(Point(center.x - 1.5, center.y + 0.5, center.z), 3, 4, 0.5).draw();
	Cuboid(Point(center.x + 2.5, center.y + 0.5, center.z), 3, 4, 0.5).draw();

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
	//Cuboid(Point(center.x, center.y, center.z), 0.1, 5, 5).drawWithTexture(bedBack.textureID,1,1);
}

void FurnitureStore::drawCircularTable(Point center) {
	//table base
	glColor3ub(123, 123, 123);
	cylinder.draw(Point(center.x, center.y, center.z), 5, 5, 0.3, 36, 36);

	cylinder.draw(Point(center.x, center.y + 4, center.z), 5, 5, 0.3, 36, 3);

	glColor3ub(36, 36, 36);
	cylinder.draw(Point(center.x + 4.7, center.y + 3.75, center.z), 0.15, 0.15, 3.75, 36, 36);
	
	cylinder.draw(Point(center.x, center.y + 3.75, center.z + 4.7), 0.15, 0.15, 3.75, 36, 36);
	
	cylinder.draw(Point(center.x , center.y + 3.75, center.z - 4.7), 0.15, 0.15, 3.75, 36, 36);

	cylinder.draw(Point(center.x - 4.7, center.y + 3.75, center.z), 0.15, 0.15, 3.75, 36, 36);
}

//void FurnitureStore::drawClock(Point center) {
//	glColor3ub(255, 255, 255);
//
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex3f(center.x, center.y, center.z);
//	for (int i = 0; i <= 360; ++i) {
//		float angle = i * M_PI / 180.0f;
//		float x = cos(angle) * 3 + center.x;
//		float y = sin(angle) * 3 + center.y;
//
//		glVertex3f(x, y, center.z);
//	}
//	glEnd();
//
//	glPushMatrix();
//	glLineWidth(4);
//	glColor3ub(0, 0, 0);
//	for (int i = 0; i < 60; ++i) {
//		float angle = i * 6.0f * M_PI / 180.0f; // Each marker is 6 degrees apart
//		float xStart = cos(angle) * (3 * (i % 5 == 0 ? 0.85f : 0.92f)) + center.x;
//		float yStart = sin(angle) * (3 * (i % 5 == 0 ? 0.85f : 0.92f)) + center.y;
//		float xEnd = cos(angle) * 3 + center.x;
//		float yEnd = sin(angle) * 3 + center.y;
//
//		glBegin(GL_LINES);
//		glVertex3f(xStart, yStart, center.z);
//		glVertex3f(xEnd, yEnd, center.z);
//		glEnd();
//	}
//	glPopMatrix();
//
//	double hourAngle = hour * M_PI / 180.0;   // Convert hour angle to radians
//	double minuteAngle = minute * M_PI / 180.0; // Convert minute angle to radians
//	double secondAngle = second * M_PI / 180.0; // Convert second angle to radians
//
//	glPushMatrix();
//	// Hour hand
//	glLineWidth(10);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glBegin(GL_LINES);
//	glVertex3f(center.x, center.y, center.z);
//	glVertex3f(center.x + cos(hourAngle) * 3 * 0.5f, center.y + sin(hourAngle) * 3 * 0.5f, center.z);
//	glEnd();
//
//	// Minute hand
//	glLineWidth(10);
//	glBegin(GL_LINES);
//	glVertex3f(center.x, center.y, center.z);
//	glVertex3f(center.x + cos(minuteAngle) * 3 * 0.7f, center.y + sin(minuteAngle) * 3 * 0.7f, center.z);
//	glEnd();
//
//	// Second hand
//	glLineWidth(10);
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glBegin(GL_LINES);
//	glVertex3f(center.x, center.y, center.z);
//	glVertex3f(center.x + cos(secondAngle) * 3 * 0.9f, center.y + sin(secondAngle) * 3 * 0.9f, center.z);
//	glEnd();
//
//	glPopMatrix();
//
//}

void FurnitureStore::drawSeat(Point center) {

	glColor3ub(255, 255, 255);
	Cuboid(Point(center.x, center.y + 5, center.z), 2, 0.5, 6).drawWithTexture(chair.textureID,1,1);

	Cuboid(Point(center.x, center.y + 4, center.z), 0.5, 0.5, 6).drawWithTexture(chair.textureID, 1, 1);

	Cuboid(Point(center.x, center.y + 3, center.z),0.5,0.5,6).drawWithTexture(chair.textureID, 1, 1);
	

	Cuboid(Point(center.x + 3.25, center.y + 1.25, center.z), 5.75, 0.5, 0.5).drawWithTexture(chair.textureID, 1, 1);

	Cuboid(Point(center.x - 3.25, center.y + 1.25, center.z), 5.75, 0.5, 0.5).drawWithTexture(chair.textureID, 1, 1);

	Cuboid(Point(center.x, center.y + 0.75, center.z + 1.75), 0.5, 4, 7).drawWithTexture(chair.textureID,1,1);

	Cuboid(Point(center.x - 3.25, center.y + 3, center.z + 1.75), 0.5, 3, 0.5).drawWithTexture(chair.textureID, 1, 1);

	Cuboid(Point(center.x - 3.25, center.y + 1.25, center.z + 3.5), 2.25, 0.5, 0.5).drawWithTexture(chair.textureID, 1, 1);

	Cuboid(Point(center.x + 3.25, center.y + 3, center.z + 1.75), 0.5, 3, 0.5).drawWithTexture(chair.textureID, 1, 1);

	Cuboid(Point(center.x + 3.25, center.y + 1.25, center.z + 3.5), 2.25, 0.5, 0.5).drawWithTexture(chair.textureID, 1, 1);

	//legs
	Cuboid(Point(center.x - 3.25, center.y - 1.85, center.z + 3.5), 2.6, 0.5, 0.5).drawWithTexture(chair.textureID, 1, 1);
	Cuboid(Point(center.x + 3.25, center.y - 1.85, center.z + 3.5), 2.6, 0.5, 0.5).drawWithTexture(chair.textureID, 1, 1);
	Cuboid(Point(center.x - 3.25, center.y - 1.85, center.z), 2.6, 0.5, 0.5).drawWithTexture(chair.textureID, 1, 1);
	Cuboid(Point(center.x + 3.25, center.y - 1.85, center.z), 2.6, 0.5, 0.5).drawWithTexture(chair.textureID, 1, 1);
}
void FurnitureStore::drawDiningTable(Point center) {
	
	glColor3ub(255, 255, 255);
	//table back

	Cuboid(Point(center.x, center.y, center.z),0.5,8,10).drawWithTexture(wood.textureID,1,1);
	
	// semi circle front
	glPushMatrix();
	glTranslatef(center.x + 5, center.y + 0.25 , center.z);
	glRotated(90, 1, 0, 0);
	glRotated(-90, 0, 0, 1);
	this->drawSemiCircle(Point(0, 0, 0), 4, 0.5, 50,wood.textureID);
	glPopMatrix();

	//semi circle back
	glPushMatrix();
	glTranslatef(center.x - 5, center.y + 0.25, center.z);
	glRotated(270, 1, 0, 0);
	glRotated(90, 0, 0, 1);
	this->drawSemiCircle(Point(0, 0, 0), 4, 0.5, 50,wood.textureID);
	glPopMatrix();

	//legs
	cylinder.drawWithTexture(Point(center.x, center.y, center.z), 1.1, 0.5, 7, 36, 36,wood.textureID);

	cylinder.drawWithTexture(Point(center.x, center.y - 7, center.z), 3, 3, 0.5, 36, 36,wood.textureID);
}

void FurnitureStore::drawDiningTable2(Point center) {
	glColor3ub(255, 255, 255);
	cylinder.drawWithTexture(Point(center.x,center.y + 0.6,center.z), 9, 9, 0.5, 36, 36,woodTable2.textureID);

	cylinder.drawWithTexture(Point(center.x, center.y + 0.5, center.z),1,1.5,6,36,36, woodTable2.textureID);

	cylinder.drawWithTexture(Point(center.x, center.y - 5.2, center.z), 3, 3, 0.5, 36, 36, woodTable2.textureID);

}
void FurnitureStore::drawBed(Point center,GLint textureId,GLint woodTexture) {

	glColor3ub(255, 255, 255);
	// bed base
	Cuboid(Point(center.x, center.y, center.z), 3, 10, 20).drawWithTexture(textureId,1,1);

	//bed back
	Cuboid(Point(center.x + 10.25, center.y - 3, center.z),8,10,0.5).drawWithTexture(woodTexture, 1, 1);

	Cuboid(Point(center.x - 10.25, center.y - 3, center.z), 5, 10, 0.5).drawWithTexture(woodTexture, 1, 1);

	//legs
	Cuboid(Point(center.x + 9.75, center.y - 3, center.z + 4.75), 3, 0.5, 0.5).drawWithTexture(woodTexture, 1, 1);
	Cuboid(Point(center.x - 9.75, center.y - 3, center.z + 4.75), 3, 0.5, 0.5).drawWithTexture(woodTexture, 1, 1);
	Cuboid(Point(center.x - 9.75, center.y - 3, center.z - 4.75), 3, 0.5, 0.5).drawWithTexture(woodTexture, 1, 1);
	Cuboid(Point(center.x + 9.75, center.y - 3, center.z - 4.75),3,0.5,0.5).drawWithTexture(woodTexture, 1, 1);

	glColor3ub(255, 255, 255);
	//semi circle front
	glPushMatrix();
	glTranslatef(center.x + 10.25, center.y + 5, center.z);
	glRotated(90, 0, 1, 0);
	this->drawSemiCircle(Point(0, 0, 0), 5, 0.5, 50, woodTexture);
	glPopMatrix();

	//semi circle back
	glPushMatrix();
	glTranslatef(center.x - 10.25, center.y + 2, center.z);
	glRotated(90, 0, 1, 0);
	this->drawSemiCircle(Point(0, 0, 0), 5, 0.5, 50, woodTexture);
	glPopMatrix();

}

void FurnitureStore::drawDrawers(Point center) {
	glColor3ub(255, 255, 255);

	//sides
	Cuboid(Point(center.x, center.y, center.z), 0.5, 5, 10).drawWithTexture(woodTable.textureID,1,2);

	Cuboid(Point(center.x + 5.25, center.y, center.z), 10, 5, 0.5).drawWithTexture(woodTable.textureID, 1, 2);

	Cuboid(Point(center.x - 5.25, center.y, center.z), 10, 5, 0.5).drawWithTexture(woodTable.textureID, 1, 2);

	Cuboid(Point(center.x, center.y, center.z - 2.75), 10, 0.5, 11).drawWithTexture(woodTable.textureID, 1, 2);

	Cuboid(Point(center.x, center.y + 10, center.z - 0.25), 0.5, 5.5, 11).drawWithTexture(woodTable.textureID, 1, 2);

	//drawers
	Cuboid(Point(center.x, center.y + 1, center.z - 0.25), 0.5, 4.75, 10).drawWithTexture(woodTable.textureID, 1, 2);
	Cuboid(Point(center.x - 4.75, center.y + 0.5, center.z - 0.25), 5, 4.5, 0.5).drawWithTexture(woodTable.textureID, 1, 2);
	Cuboid(Point(center.x + 4.75, center.y + 0.5, center.z - 0.25), 5, 4.5, 0.5).drawWithTexture(woodTable.textureID, 1, 2);
    Cuboid(Point(center.x, center.y + 0.5, center.z + 2.25), 5, 0.5, 10).drawWithTexture(drawer.textureID,1,1);
	center.z += drawer2Offset;

	Cuboid(Point(center.x, center.y + 5.25, center.z - 0.25), 0.5, 4.75, 10).drawWithTexture(woodTable.textureID, 1, 2);
	Cuboid(Point(center.x - 4.75, center.y + 5.75, center.z - 0.25), 4.25, 4.5, 0.5).drawWithTexture(woodTable.textureID, 1, 2);
	Cuboid(Point(center.x + 4.75, center.y + 5.75, center.z - 0.25), 4.25, 4.5, 0.5).drawWithTexture(woodTable.textureID, 1, 2);
	Cuboid(Point(center.x, center.y + 5.25, center.z - 2.25),4.5,0.5,10).drawWithTexture(woodTable.textureID, 1, 1);
	Cuboid(Point(center.x, center.y + 5.75, center.z + 2.25), 4.25, 0.5, 10).drawWithTexture(drawer.textureID, 1, 1);
}
void FurnitureStore::drawDoubleBed(Point center) {
	//first bed base
	glColor3ub(44, 44, 44);
	Cuboid(Point(center.x, center.y, center.z), 3, 10, 20).draw();

	//first bed back
	glColor3ub(54, 126, 127);
	Cuboid(Point(center.x + 10.25, center.y, center.z), 5, 10, 0.5).draw();
	Cuboid(Point(center.x - 10.25, center.y, center.z), 5, 10, 0.5).draw();

	//second bed base
	glColor3ub(44, 44, 44);
	Cuboid(Point(center.x, center.y + 10, center.z), 3, 10, 20).draw();

	//second bed back
	glColor3ub(54, 126, 127);
	Cuboid(Point(center.x + 10.25, center.y + 10, center.z), 5, 10, 0.5).draw();
	Cuboid(Point(center.x - 10.25, center.y + 10, center.z), 5, 10, 0.5).draw();


	//legs
	glColor3ub(255, 255, 255);
	Cuboid(Point(center.x + 10.25, center.y - 3, center.z + 5.25), 18, 0.5, 0.5).drawWithTexture(bedleg.textureID,1,3);
	Cuboid(Point(center.x - 10.25, center.y - 3, center.z + 5.25), 18, 0.5, 0.5).drawWithTexture(bedleg.textureID,1,3);
	Cuboid(Point(center.x - 10.25, center.y - 3, center.z - 5.25), 18, 0.5, 0.5).drawWithTexture(bedleg.textureID, 1, 3);
	Cuboid(Point(center.x + 10.25, center.y - 3, center.z - 5.25), 18, 0.5, 0.5).drawWithTexture(bedleg.textureID, 1, 3);

	Cuboid(Point(center.x - 2.5, center.y + 13, center.z + 5.25),0.5,0.3,15).drawWithTexture(bedleg.textureID, 3, 1);
	Cuboid(Point(center.x - 2.5, center.y + 14.5, center.z + 5.25), 0.5, 0.3, 15).drawWithTexture(bedleg.textureID, 3, 1);
	Cuboid(Point(center.x, center.y + 13, center.z - 5.25), 0.5, 0.3, 20).drawWithTexture(bedleg.textureID, 4, 1);
	Cuboid(Point(center.x, center.y + 14.5, center.z - 5.25), 0.5, 0.3, 20).drawWithTexture(bedleg.textureID, 4, 1);


	//Ladder 
	Cuboid(Point(center.x + 5.25, center.y - 3, center.z + 5.25), 18, 0.5, 0.5).drawWithTexture(bedleg.textureID, 1, 3);

	Cuboid(Point(center.x + 7.75, center.y - 2, center.z + 5.25),0.5,0.5,4.5).drawWithTexture(bedleg.textureID, 1, 1);
	Cuboid(Point(center.x + 7.75, center.y + 1, center.z + 5.25), 0.5, 0.5, 4.5).drawWithTexture(bedleg.textureID, 1, 1);
	Cuboid(Point(center.x + 7.75, center.y + 4, center.z + 5.25), 0.5, 0.5, 4.5).drawWithTexture(bedleg.textureID, 1, 1);
	Cuboid(Point(center.x + 7.75, center.y + 7, center.z + 5.25), 0.5, 0.5, 4.5).drawWithTexture(bedleg.textureID, 1, 1);
	Cuboid(Point(center.x + 7.75, center.y + 10, center.z + 5.25), 0.5, 0.5, 4.5).drawWithTexture(bedleg.textureID, 1, 1);

}
void FurnitureStore::drawSemiCircle(Point center, float radius, float thickness, int segments,GLint textureId){
	glBindTexture(GL_TEXTURE_2D, textureId); // Bind texture
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();

	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2f(0.5f, 0.5f); 
	glVertex3f(center.x, center.y, thickness / 2.0f); 
	for (int i = 0; i <= segments; ++i) {
		float angle = M_PI * i / segments;
		float x = center.x + radius * cos(angle);
		float y = center.y + radius * sin(angle);

		
		float u = 0.5f + 0.5f * cos(angle); 
		float v = 0.5f + 0.5f * sin(angle); 
		glTexCoord2f(v, u); 

		glVertex3f(x, y, thickness / 2.0f); 
	}
	glEnd();
	glPopMatrix();

	// Drawing the back surface with texture
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureId); 

	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2f(0.5f, 0.5f); 
	glVertex3f(center.x, center.y, -thickness / 2.0f); // Center of the back surface
	for (int i = 0; i <= segments; ++i) {
		float angle = M_PI * i / segments;
		float x = center.x + radius * cos(angle);
		float y = center.y + radius * sin(angle);

		// Map texture coordinates
		float u = 0.5f + 0.5f * cos(angle);
		float v = 0.5f + 0.5f * sin(angle);
		glTexCoord2f(v, u);

		glVertex3f(x, y, -thickness / 2.0f); 
	}
	glEnd();
	glPopMatrix();

	// Drawing the side edges with texture
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureId);
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= segments; ++i) {
		float angle = M_PI * i / segments;
		float x = radius * cos(angle);
		float y = radius * sin(angle);

		float u = float(i) / float(segments); // Horizontal texture coordinate
		float v1 = 0.5f + 0.5f * cos(angle); // Front texture
		float v2 = 0.5f + 0.5f * sin(angle); // Back texture
		glTexCoord2f(v1, u);  // Front side
		glVertex3f(center.x + x, center.y + y, thickness / 2.0f); 
		glTexCoord2f(v2, u);  // Back side
		glVertex3f(center.x + x, center.y + y, -thickness / 2.0f); 
	}
	glEnd();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}
void FurnitureStore::moveDrawer(float offset) {
	drawerOffset += offset;
}