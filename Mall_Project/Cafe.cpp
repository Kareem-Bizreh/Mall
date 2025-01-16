#include "Cafe.h"

Cafe::Cafe(Point c)
{
	center = c;
}

void Cafe::draw()
{
	glColor3d(1, 1, 1);
	Cuboid(center, 0, 50, 85).drawWithTexture(ground.textureID, 12, 8);
	Cuboid(Point(center.x, center.y + 50, center.z), 0, 50, 85).drawWithTexture(backWall.textureID, 4, 4);
	Cuboid(Point(center.x + 42.5, center.y, center.z), 50, 50, 0).drawWithTexture(sideWall.textureID, 1, 1);
	glPushMatrix();
	glTranslated(center.x - 42.5, center.y, center.z);
	glRotated(180, 0, 1, 0);
	Cuboid(Point(0, 0, 0), 50, 50, 0).drawWithTexture(sideWall.textureID, 1, 1);
	glPopMatrix();
	Cuboid(Point(center.x, center.y, center.z - 25), 50, 0, 85).drawWithTexture(frontWall.textureID, 4, 4);
	Cuboid(Point(center.x - 8.5, center.y, center.z + 25), 50, 0, 68).drawWithTexture(backWall.textureID, 4, 4);
	Cuboid(Point(center.x + 34, center.y + 25, center.z + 25), 25, 0.1, 17).drawWithTexture(backWall.textureID, 2, 2);
	Cuboid(Point(center.x + 34, center.y + 30, center.z + 26), 10, 2, 11).drawWithTextureOnOneFace(logo.textureID, "front", 1, 1);

	drawSideTable();

	Cuboid(Point(center.x + 6.5, center.y + 0.05, center.z + 13.5), 15, 22.99, 3).drawWithTexture(sideTable.textureID, 10, 10);
	Cuboid(Point(center.x - 9, center.y + 0.05, center.z + 3.5), 15, 3, 28).drawWithTexture(sideTable.textureID, 10, 10);
	glPushMatrix();
	glTranslated(center.x, center.y + 2.5, center.z + 3);
	drawCup(true);
	glPopMatrix();
	Cuboid(Point(center.x - 5, center.y + 0.1, center.z + 22.5), 25, 4.9, 17).drawWithTextureOnOneFace(fridge.textureID, "back", 1, 1);
}

void Cafe::drawDynamic()
{
	glPushMatrix();
	glTranslated(center.x + 25.5, center.y, center.z + 25);
	glRotated(150 * doorMov->OpenRate, 0, 1, 0);
	Cuboid(Point(8.5, 0.05, 0), 25, 1, 17).drawWithTexture(door.textureID, 1, 1);
	glPopMatrix();
}

void Cafe::drawSideTable()
{
	Cuboid(Point(center.x, center.y + 15, center.z - 21.49), 0.5, 7, 85 - 0.1).drawWithTexture(sideTable.textureID, 10, 10);
	Cuboid(Point(center.x - 38.99, center.y + 15, center.z), 0.5, 50 - 0.1, 7).drawWithTexture(sideTable.textureID, 10, 10);
	Cuboid(Point(center.x + 38.99, center.y + 15, center.z - 10), 0.5, 30 - 0.1, 7).drawWithTexture(sideTable.textureID, 10, 10);
	glPushMatrix();
	glTranslated(center.x, center.y + 3, center.z + 3);
	for (int i = 30; i > -35; i -= 12)
	{
		glPushMatrix();
		glTranslated(i, 0, -16);
		drawChair();
		glPopMatrix();
	}

	for (int i = -3; i < 5; i += 10)
	{
		glPushMatrix();
		glTranslated(33.5, 0, i);
		drawChair();
		glPopMatrix();
	}

	for (int i = -4; i < 25; i += 10)
	{
		glPushMatrix();
		glTranslated(-33.5, 0, i);
		drawChair();
		glPopMatrix();
	}

	for (int i = 30; i > -35; i -= 18)
	{
		glPushMatrix();
		glTranslated(i, 0, -22);
		drawLight();
		drawCup();
		glPopMatrix();
	}

	for (int i = -3; i < 5; i += 18)
	{
		glPushMatrix();
		glTranslated(38.5, 0, i);
		drawLight();
		drawCup();
		glPopMatrix();
	}

	for (int i = -4; i < 25; i += 18)
	{
		glPushMatrix();
		glTranslated(-38.5, 0, i);
		drawLight();
		drawCup();
		glPopMatrix();
	}
	glPopMatrix();
}

void Cafe::drawChair()
{
	GLUquadric* quad = gluNewQuadric();

	glColor3f(0.2, 0.2, 0.2);
	glPushMatrix();
	glTranslatef(0, -3, 0);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 1.0, 1.0, 10, 32, 32);
	glColor3d(0, 0, 0);
	gluCylinder(quad, 2.5, 2.5, 0.5, 32, 32);

	glPushMatrix();
	glTranslated(0, 0, 0.5);
	gluCylinder(quad, 2.5, 0, 0, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, 9);
	gluCylinder(quad, 4, 4, 1, 32, 32);
	gluCylinder(quad, 4, 0, 0, 32, 32);

	glPushMatrix();
	glTranslated(0, 0, 1);
	gluCylinder(quad, 4, 0, 0, 32, 32);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	gluDeleteQuadric(quad);
	glColor3f(1, 1, 1);
}

void Cafe::drawLight()
{
	GLUquadric* quad = gluNewQuadric();

	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(0, 32, 0);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 0.1, 0.1, 15, 32, 32);
	glColor3f(0.5, 0.5, 0.5);
	gluCylinder(quad, 1, 0, 0, 32, 32);

	glPushMatrix();
	glTranslatef(0, 0, -5);
	glColor3f(1.0f, 1.0f, 0.0f);
	glutSolidSphere(1, 32, 32);
	glColor3f(0.5, 0.5, 0.5);
	gluCylinder(quad, 3, 1, 5, 32, 32);

	glPopMatrix();
	glPopMatrix();

	gluDeleteQuadric(quad);
	glColor3f(1, 1, 1);
}

void Cafe::drawCup(bool fill)
{
	GLUquadric* quad = gluNewQuadric();

	glColor3f(0.3, 0.3, 0.3);
	glPushMatrix();
	glTranslatef(0, 12.6, 0);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 0.7, 0, 0, 32, 32);
	glColor3f(1, 1, 1);
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, logo.textureID);
	gluCylinder(quad, 0.7, 1, 2, 32, 32);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	if (fill)
	{
		glColor3f(0.5, 0.35, 0.2);
		glPushMatrix();
		glTranslatef(0, 0, 1.6);
		gluCylinder(quad, 1 - 0.06, 0, 0, 32, 32);
		glColor3f(1, 1, 1);
		glPopMatrix();
	}
	glPopMatrix();

	gluDeleteQuadric(quad);
}

void Cafe::cafeTextures()
{
	ground.loadTexture("textures/cafe/ground.jpg");
	frontWall.loadTexture("textures/cafe/frontWall.jpg");
	sideWall.loadTexture("textures/cafe/sideWall.jpg");
	sideTable.loadTexture("textures/cafe/sideTable.jpg");
	backWall.loadTexture("textures/cafe/backWall.jpg");
	logo.loadTexture("textures/cafe/logo.jpg");
	door.loadTexture("textures/cafe/door.jpg");
	fridge.loadTexture("textures/cafe/fridge.jpg");
}
