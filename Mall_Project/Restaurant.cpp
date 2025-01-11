#include "Restaurant.h"

Restaurant::Restaurant(Point c)
{
	center = c;
}

void Restaurant::draw()
{
	Cuboid(center, 0.1, 50, 100).drawWithTexture(ground.textureID, 12, 8);
	Cuboid(Point(center.x, center.y + 50, center.z), 0, 50, 100).drawWithTexture(wall.textureID, 12, 8);
	Cuboid(Point(center.x + 50, center.y, center.z), 50, 50, 0.1).drawWithTexture(wall.textureID, 5, 5);
	Cuboid(Point(center.x - 50, center.y, center.z), 50, 50, 0.1).drawWithTexture(wall.textureID, 5, 5);
	Cuboid(Point(center.x, center.y, center.z - 25), 50, 0.1, 100).drawWithTexture(wall.textureID, 10, 5);
	Cuboid(Point(center.x + 8, center.y, center.z + 25), 50, 0.1, 84).drawWithTexture(wall.textureID, 10, 5);
	Cuboid(Point(center.x - 42, center.y + 25, center.z + 25), 25, 0.1, 16).drawWithTexture(wall.textureID, 2, 3);
	Cuboid(Point(center.x - 42, center.y + 30, center.z + 26), 10, 2, 11).drawWithTextureOnOneFace(logo.textureID, "front", 1, 1);
	glPushMatrix();
	glTranslated(center.x - 34, center.y, center.z + 25);
	glRotated(180 - 150 * doorMov->OpenRate, 0, 1, 0);
	Cuboid(Point(8, 0.05, 0), 25, 1, 16).drawWithTexture(door.textureID, 1, 1);
	glPopMatrix();
	Cuboid(Point(center.x + 15, center.y + 0.1, center.z + 7), 15, 36, 3).drawWithTexture(table.textureID, 8, 8);
	glColor3f(0.7, 0.7, 0.7);
	Cuboid(Point(center.x + 11, center.y + 10, center.z + 7), 1, 36, 5).drawWithTexture(table.textureID, 4, 4);
	glColor3f(1, 1, 1);
	drawSideChairs();
	drawSideTable();
	glPushMatrix();
	glTranslatef(26, 0, 0);
	drawSideTable();
	glPopMatrix();
	drawLights();
	drawKitchen();
}

void Restaurant::drawChair()
{
	GLUquadric* quad = gluNewQuadric();
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, chair.textureID);

	glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
	glTranslatef(0, -2.95, 0);
	glRotated(-80, 1, 0, 0);
	glRotated(5, 0, 1, 0);
	gluCylinder(quad, 0.4, 0.3, 7, 32, 32);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -2.95, 4);
	glRotated(-100, 1, 0, 0);
	glRotated(5, 0, 1, 0);
	gluCylinder(quad, 0.4, 0.3, 7, 32, 32);

	glPopMatrix();


	glPushMatrix();
	glTranslatef(4, -2.9, 2);
	glRotated(-90, 1, 0, 0);
	glRotated(-15, 0, 1, 0);
	gluCylinder(quad, 0.4, 0.3, 7, 32, 32);

	glPopMatrix();
	glColor3f(1, 1, 1);

	glPushMatrix();
	glTranslatef(1.2, 3.8, 2);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 2, 2, 0.8, 32, 32);
	gluCylinder(quad, 2, 0, 0, 32, 32);
	glPushMatrix();
	glTranslated(0, 0, 0.8);
	gluCylinder(quad, 2, 0, 0, 32, 32);
	glPopMatrix();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	gluDeleteQuadric(quad);
}

void Restaurant::drawLight()
{
	GLUquadric* quad = gluNewQuadric();

	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(0, 26, 0);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 0.1, 0.1, 21, 32, 32);
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(0, 0, -2);
	gluCylinder(quad, 1.5, 0.1, 2, 32, 32);
	glTranslated(0, 0, -1);
	glColor3f(0.8f, 0.8f, 0.0f);
	glutSolidSphere(2, 32, 32);
	glPopMatrix();

	gluDeleteQuadric(quad);
	glColor3f(1, 1, 1);
}

void Restaurant::drawLights()
{
	glPushMatrix();
	glTranslated(center.x, center.y + 3, center.z);
	for (int i = -30; i < 50; i += 30)
	{
		glPushMatrix();
		glTranslated(i, 0, 15);
		drawLight();
		glTranslated(0, 0, -30);
		drawLight();
		glPopMatrix();
	}
	glPopMatrix();
}

void Restaurant::drawWaterTap()
{
	glColor3f(0.8, 0.8, 0.8);
	GLUquadric* quad = gluNewQuadric();
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, metal.textureID);

	glPushMatrix();
	glTranslatef(0, -3, 0);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 0.5, 0.4, 0.2, 32, 32);
	glPushMatrix();
	glTranslated(0, 0, 0.2);
	gluCylinder(quad, 0.4, 0.2, 0, 32, 32);
	glColor3f(1, 1, 1);
	gluCylinder(quad, 0.2, 0.2, 3, 32, 32);

	glPushMatrix();
	glTranslated(-4, 0, 2);
	gluCylinder(quad, 0.2, 0.2, 1, 32, 32);
	glColor3f(0.8, 0.8, 0.8);
	gluCylinder(quad, 0.2, 0.25, 0, 32, 32);
	glTranslated(0, 0, -0.5);
	gluCylinder(quad, 0.35, 0.25, 0.5, 32, 32);
	glColor3f(1, 1, 1);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	gluCylinder(quad, 0.2, 0.2, 4, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -2, 0);
	gluCylinder(quad, 0.2, 0.2, 0.6, 32, 32);
	glColor3f(0.8, 0.8, 0.8);
	glTranslated(0, 0, 0.6);
	gluCylinder(quad, 0.2, 0.2, 0.6, 32, 32);
	glPushMatrix();
	glTranslated(0, 0, 0.6);
	gluCylinder(quad, 0.2, 0, 0, 32, 32);
	glPopMatrix();
	glColor3f(1, 1, 1);
	glTranslated(0, 0, 0.4);
	glRotated(-90, 1, 0, 0);
	//glRotated(-50, 0, 1, 0);
	gluCylinder(quad, 0.07, 0.15, 1, 32, 32);
	glTranslated(0, 0, 1);
	gluCylinder(quad, 0, 0.15, 0, 32, 32);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	gluDeleteQuadric(quad);
}

void Restaurant::drawSideChairs()
{
	for (int i = 16; i > -16; i -= 8)
	{
		glPushMatrix();
		glTranslated(center.x + 7, center.y + 3, center.z + i);
		drawChair();
		glPopMatrix();
	}
}

void Restaurant::drawSideTable()
{
	glColor3ub(90, 56, 30);
	Cuboid(Point(center.x - 38, center.y + 10, center.z - 16), 1, 18, 12).draw();
	GLUquadric* quad = gluNewQuadric();

	glPushMatrix();
	glTranslatef(center.x - 38, center.y + 10.005, center.z - 7);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 6, 6, 0.99, 32, 32);
	gluCylinder(quad, 6, 0, 0, 32, 32);
	glPushMatrix();
	glTranslated(0, 0, 0.99);
	gluCylinder(quad, 6, 0, 0, 32, 32);
	glPopMatrix();
	glPopMatrix();

	glColor3f(0, 0, 0);
	for (int i = 0; i < 3; i++)
	{
		glPushMatrix();
		glTranslatef(center.x - 35, center.y, center.z - 5 - 8 * i);
		glRotated(-90, 1, 0, 0);
		gluCylinder(quad, 0.5, 0.5, 10, 32, 32);
		glTranslatef(-6, 0, 0);
		gluCylinder(quad, 0.5, 0.5, 10, 32, 32);
		glPopMatrix();
	}

	gluDeleteQuadric(quad);
	for (int i = 16; i > -8; i -= 6)
	{
		glPushMatrix();
		glTranslated(center.x - 33, center.y + 3, center.z + i - 22);
		drawChair();
		glPopMatrix();

		glPushMatrix();
		glTranslated(center.x - 46, center.y + 3, center.z + i - 22);
		drawChair();
		glPopMatrix();
	}
}

void Restaurant::drawKitchen()
{
	glPushMatrix();
	glTranslated(center.x + 45, center.y, center.z + 25);
	Cuboid(Point(-5, 0, -5), 10, 10, 0).drawWithTexture(frontStove.textureID, 1, 1);
	Cuboid(Point(0, 10, -5), 0, 10, 10).drawWithTexture(topStove.textureID, 1, 1);
	glColor3f(0.65, 0.65, 0.65);
	Cuboid(Point(0, 0, -10), 10, 0, 10).draw();
	Cuboid(Point(0, 0, 0), 10, 0, 10).draw();
	glColor3f(1, 1, 1);
	glTranslated(0, 0, -21);
	Cuboid(Point(-5, 0.1, 0), 9, 20, 0).drawWithTexture(sideWash.textureID, 1, 5);
	Cuboid(Point(0, 0.1, -10), 9, 0, 10).drawWithTexture(sideWash.textureID, 1, 5);
	Cuboid(Point(0, 0.1, 10), 9, 0, 10).drawWithTexture(sideWash.textureID, 1, 5);

	Cuboid(Point(-4, 9.1, 0), 1, 20, 2).drawWithTexture(washBasin.textureID, 1, 1);
	Cuboid(Point(4, 9.1, 0), 1, 20, 2).drawWithTexture(washBasin.textureID, 1, 1);
	Cuboid(Point(0, 9.1, -9), 1, 2, 6).drawWithTexture(washBasin.textureID, 5, 1);
	Cuboid(Point(0, 9.1, 9), 1, 2, 6).drawWithTexture(washBasin.textureID, 5, 1);
	Cuboid(Point(0, 9.1, 0), 1, 4, 6).drawWithTexture(washBasin.textureID, 5, 1);
	for (int i = 0; i <= 1; i++)
	{
		glPushMatrix();
		glTranslated(4, 13.1, -10 * i + 5);
		drawWaterTap();
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 0, -10 * i + 5);
		glColor3f(0.7, 0.7, 0.7);
		Cuboid(Point(0, 7, 0), 0, 6, 6).drawWithTexture(washBasin.textureID, 1, 1);
		glColor3f(0.8, 0.8, 0.8);

		Cuboid(Point(3, 7, 0), 2.1, 6, 0).drawWithTexture(washBasin.textureID, 1, 1);
		Cuboid(Point(-3, 7, 0), 2.1, 6, 0).drawWithTexture(washBasin.textureID, 1, 1);
		Cuboid(Point(0, 7, -3), 2.1, 0, 6).drawWithTexture(washBasin.textureID, 1, 1);
		Cuboid(Point(0, 7, 3), 2.1, 0, 6).drawWithTexture(washBasin.textureID, 1, 1);
		glPopMatrix();
	}
	glTranslated(0, 0.1, -20);
	Cuboid(Point(0, 0, 0), 10, 16, 10).drawWithTextureOnOneFace(cabinet.textureID, "left", 1, 1);
	glTranslated(0, 15, 0);
	Cuboid(Point(2.5, 0, 0), 10, 16, 5).drawWithTexture(sideWash.textureID, 1, 1);
	Cuboid(Point(0, 0, 0), 10, 16, 0).drawWithTexture(shelf.textureID, 1, 1);
	glColor3f(1, 1, 1);
	glPopMatrix();
}

void Restaurant::restaurantTextures()
{
	ground.loadTexture("textures/restaurant/ground.jpg");
	wall.loadTexture("textures/restaurant/wall.jpg");
	chair.loadTexture("textures/restaurant/chair.jpg");
	table.loadTexture("textures/restaurant/table.jpg");
	logo.loadTexture("textures/restaurant/logo.jpg");
	door.loadTexture("textures/restaurant/door.jpg");
	frontStove.loadTexture("textures/restaurant/frontStove.jpg");
	topStove.loadTexture("textures/restaurant/topStove.jpg");
	washBasin.loadTexture("textures/restaurant/washBasin.jpg");
	sideWash.loadTexture("textures/restaurant/sideWash.jpg");
	metal.loadTexture("textures/restaurant/metal.jpg");
	cabinet.loadTexture("textures/restaurant/cabinet.jpg");
	shelf.loadTexture("textures/restaurant/shelf.jpg");
}
