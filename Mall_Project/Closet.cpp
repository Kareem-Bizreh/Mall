#include<gl/glut.h>
#include "Closet.h"
#include "Cuboid.h"
#include "Point.h"
#include "Texture.h"
#include "Cylinder.h"
void Closet::draw(Point center) {

	//back side
	glColor3ub(200, 200, 200);
	Cuboid(Point(center.x, center.y, center.z), 10, 0.2, 10).drawWithTexture(wood.textureID, 2, 2);
	glColor3ub(255, 255, 255);

	//down side
	Cuboid(Point(center.x, center.y - 0.2, center.z + 3.4), 0.2, 7, 10.2).drawWithTexture(wood.textureID,2,2);

	//left side
	Cuboid(Point(center.x - 5, center.y, center.z + 3.4), 10, 7, 0.2).drawWithTexture(wood.textureID, 2, 2);

	//right side
	Cuboid(Point(center.x + 5, center.y, center.z + 3.4), 10, 7, 0.2).drawWithTexture(wood.textureID, 2, 2);

	//up side
	Cuboid(Point(center.x, center.y + 10, center.z + 3.4), 0.2, 7, 10.2).drawWithTexture(wood.textureID, 2, 2);

	//roof 
	Cuboid(Point(center.x, center.y + 7.5, center.z + 3.4), 0.2, 6.8, 10).drawWithTexture(wood.textureID, 2, 2);


	//right door
	glPushMatrix();
	glTranslatef(center.x + 5, center.y, center.z + 6.8);
	glRotatef(rightDoorAngle * closetMov->OpenRate, 0, 1, 0);
	glTranslatef(-5, 0, -6.8);
	Cuboid(Point(center.x + 2.4, center.y, center.z + 6.8), 10, 0.2, 5).drawWithTexture(rightDoor.textureID, 1, 1);
	glPopMatrix();

	//left door
	glPushMatrix();
	glTranslatef(center.x - 5, center.y, center.z + 6.8);
	glRotatef(-leftDoorAngle * closetMov->OpenRate, 0, 1, 0);
	glTranslatef(5, 0, -6.8);
	Cuboid(Point(center.x - 2.5, center.y, center.z + 6.8), 10, 0.2, 4.8).drawWithTexture(leftDoor.textureID, 1, 1);
	glPopMatrix();
}

void Closet::closeDoors(float angle) {
	if (rightDoorAngle > 0.0f) {
		rightDoorAngle -= angle;
	}
	if (leftDoorAngle > 0.0f) {
		leftDoorAngle -= angle;
	}
}

void Closet::openDoors(float angle) {
	if (rightDoorAngle < 90.0f) {
		rightDoorAngle += angle;
	}
	if (leftDoorAngle < 90.0f) {
		leftDoorAngle += angle;
	}
}