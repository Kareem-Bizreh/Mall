#include<gl/glut.h>
#include "Closet.h"
#include "Cuboid.h"
#include "Point.h"

void Closet::draw(Point center) {

	//back side
	glColor3ub(102, 57, 18);
	Cuboid(Point(center.x, center.y, center.z), 10, 0.2, 10).draw();

	glColor3ub(24, 62, 12);
	//down side
	Cuboid(Point(center.x, center.y - 0.2, center.z + 3.4), 0.2, 7, 10.2).draw();

	//left side
	glColor3ub(33, 33, 33);
	Cuboid(Point(center.x - 5, center.y, center.z + 3.4), 10, 7, 0.2).draw();

	//right side
	glColor3ub(145, 144, 48);
	Cuboid(Point(center.x + 5, center.y, center.z + 3.4), 10, 7, 0.2).draw();

	//up side
	glColor3ub(145, 44, 13);
	Cuboid(Point(center.x, center.y + 10, center.z + 3.4), 0.2, 7, 10.2).draw();

	//roof 
	glColor3ub(120, 67, 21);
	Cuboid(Point(center.x, center.y + 7.5, center.z + 3.4), 0.2, 6.8, 10).draw();


	//right door
	glPushMatrix();
	glTranslatef(center.x + 5, center.y, center.z + 6.8);
	glRotatef(rightDoorAngle, 0, 1, 0);
	glTranslatef(-5, 0, -6.8);
	glColor3ub(57, 16, 123);
	Cuboid(Point(center.x + 2.4, center.y, center.z + 6.8), 10, 0.2, 5).draw();
	glPopMatrix();

	//left door
	glPushMatrix();
	glTranslatef(center.x - 5, center.y, center.z + 6.8);
	glRotatef(-leftDoorAngle, 0, 1, 0);
	glTranslatef(5, 0, -6.8);
	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 2.5, center.y, center.z + 6.8), 10, 0.2, 4.8).draw();
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