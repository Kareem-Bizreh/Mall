#include "Elevator.h"

void Elevator::draw()
{
	GLUquadric* quad = gluNewQuadric();

	// elevator home
	Cuboid(Point(-15.1, 0, 0), 75, 24, 0).drawWithTexture(elevator.textureID, 1, 1);
	Cuboid(Point(15.1, 0, 0), 75, 24, 0).drawWithTexture(elevator.textureID, 1, 1);
	Cuboid(Point(0, 75.1, 0), 0, 25, 31).drawWithTexture(elevator.textureID, 1, 1);
	Cuboid(Point(0, 25 - 0.1, 12.22), 25.2, 0, 30).drawWithTexture(elevator.textureID, 1, 1);

	// elevator down door
	Cuboid(Point(12, 0, 12.22), 25, 0, 6).drawWithTexture(elevator.textureID, 1, 1);
	Cuboid(Point(-12, 0, 12.22), 25, 0, 6).drawWithTexture(elevator.textureID, 1, 1);
	Cuboid(Point(11, 12, 12.23), 3, 0, 1.5).drawWithTexture(elevatorDoorControl.textureID, 1, 1);

	// elevator up door
	Cuboid(Point(12, 50, 12.22), 25, 0, 6).drawWithTexture(elevator.textureID, 1, 1);
	Cuboid(Point(-12, 50, 12.22), 25, 0, 6).drawWithTexture(elevator.textureID, 1, 1);
	Cuboid(Point(11, 62, 12.23), 3, 0, 1.5).drawWithTexture(elevatorDoorControl.textureID, 1, 1);

	// Columns
	glColor3f(0.3, 0.3, 0.3);
	glPushMatrix();
	glTranslated(-15, 0, -12);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 1, 1, 100, 32, 32);
	glPopMatrix();
	glPushMatrix();
	glTranslated(15, 0, -12);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 1, 1, 100, 32, 32);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-15, 0, 12);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 1, 1, 100, 32, 32);
	glPopMatrix();
	glPushMatrix();
	glTranslated(15, 0, 12);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 1, 1, 100, 32, 32);
	glPopMatrix();
	glColor3f(1, 1, 1);
	gluDeleteQuadric(quad);
}

void Elevator::drawDynamic()
{
	elevatorDoor->center.y = height + 24.5;
	glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
	glTranslated(0, height, 0);
	// elevator body
	Cuboid(Point(0, 0, -12), 25, 0, 30).drawWithTexture(elevator.textureID, 1, 1);
	glColor3f(1, 1, 1);
	Cuboid(Point(-15, 0, 0), 25, 24, 0).drawWithTexture(elevator.textureID, 1, 1);
	Cuboid(Point(15, 0, 0), 25, 24, 0).drawWithTexture(elevator.textureID, 1, 1);
	Cuboid(Point(0, 0, 0), 0, 24, 30).drawWithTexture(elevatorGround.textureID, 1, 1);
	Cuboid(Point(0, 25, 0), 0, 24.1, 30).drawWithTexture(elevator.textureID, 1, 1);

	GLUquadric* quad = gluNewQuadric();
	// elevator handles
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, elevatorHandle.textureID);

	glPushMatrix();

	glTranslated(12, 12.5, -8);
	gluCylinder(quad, 0.5, 0.5, 16, 32, 32);

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	gluSphere(quad, 0.7, 32, 32);
	glTranslated(0, 0, 16);
	gluSphere(quad, 0.7, 32, 32);
	glColor3f(1, 1, 1);
	glPopMatrix();

	glTranslated(-24, 0, 0);
	gluCylinder(quad, 0.5, 0.5, 16, 32, 32);

	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	gluSphere(quad, 0.7, 32, 32);
	glTranslated(0, 0, 16);
	gluSphere(quad, 0.7, 32, 32);
	glColor3f(1, 1, 1);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(6, 12.5, 12);
	gluCylinder(quad, 0.5, 0.5, 3, 32, 32);
	glTranslated(-12, 0, 0);
	gluCylinder(quad, 0.5, 0.5, 3, 32, 32);

	glTranslated(0, 0, -27);
	gluCylinder(quad, 0.5, 0.5, 3, 32, 32);
	glTranslated(12, 0, 0);
	gluCylinder(quad, 0.5, 0.5, 3, 32, 32);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	// elevator door
	Cuboid(Point(12, 0, 12), 25, 0, 6).drawWithTexture(elevator.textureID, 1, 1);
	Cuboid(Point(-12, 0, 12), 25, 0, 6).drawWithTexture(elevator.textureID, 1, 1);
	Cuboid(Point(-11, 12, 11.98), 3, 0, 1.5).drawWithTexture(elevatorDoorControl.textureID, 1, 1);

	Cuboid(Point(-4.5 - elevatorDoor->OpenRate * 6, 0, 12.1), 25, 0, 9).drawWithTexture(elevatorDoorL.textureID, 1, 1);
	Cuboid(Point(4.5 + elevatorDoor->OpenRate * 6, 0, 12.1), 25, 0, 9).drawWithTexture(elevatorDoorR.textureID, 1, 1);
	glPopMatrix();

	// elevator down door
	Cuboid(Point(-4.5 - elevatorDoorDown->OpenRate * 6, 0, 12.2), 25, 0, 9).drawWithTexture(elevatorDoorL.textureID, 1, 1);
	Cuboid(Point(4.5 + elevatorDoorDown->OpenRate * 6, 0, 12.2), 25, 0, 9).drawWithTexture(elevatorDoorR.textureID, 1, 1);

	// elevator up door
	Cuboid(Point(-4.5 - elevatorDoorUp->OpenRate * 6, 50, 12.2), 25, 0, 9).drawWithTexture(elevatorDoorL.textureID, 1, 1);
	Cuboid(Point(4.5 + elevatorDoorUp->OpenRate * 6, 50, 12.2), 25, 0, 9).drawWithTexture(elevatorDoorR.textureID, 1, 1);

	gluDeleteQuadric(quad);
}

void Elevator::loadTextures()
{
	elevator.loadTexture("textures/Elevator/elevator.jpg");
	elevatorGround.loadTexture("textures/Elevator/elevatorGround.jpg");
	elevatorHandle.loadTexture("textures/Elevator/elevatorHandle.jpg");
	elevatorDoorR.loadTexture("textures/Elevator/elevatorDoorR.jpg");
	elevatorDoorL.loadTexture("textures/Elevator/elevatorDoorL.jpg");
	elevatorDoorControl.loadTexture("textures/Elevator/elevatorDoorControl.jpg");
}
