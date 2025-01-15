#include "Lake.h"
#include "SuperMarket.h"
#include <iostream>
#include "Gl/glut.h"
#include "Camera.h"
#include "Cuboid.h"
#include "Point.h"
#include "Texture.h"
#include<bits/stdc++.h>
#include "FurnitureStore.h"

void Lake::loadTextures()
{
	floorLake.loadTexture("textures\\SuperMarket\\floorLake2.jpg");
	lakeWall.loadTexture("textures\\SuperMarket\\lakeWall5.jpg");
	partie.loadTexture("textures\\SuperMarket\\parties.jpg");
	Water.loadTexture("textures\\SuperMarket\\water.jpg");
	Cylinder.loadTexture("textures\\SuperMarket\\lakeWall2.jpg");
}

void Lake::drawParties()
{
	Cuboid parties(Point(0, 0, 0), 11, 5, 5), upParties(Point(0, 11, 0), 2, 7, 7);

	glColor3ub(255, 255, 255);
	parties.drawWithTexture(partie.textureID, 1, 1);
	upParties.drawWithTexture(partie.textureID, 1, 1);
}

inline double toRadians(double degrees) {
	return degrees * M_PI / 180.0;
}
void Lake::drawLake()
{
	GLUquadric* quad = gluNewQuadric();

	glPushMatrix();
	glTranslated(0, 0, 0);
	this->drawParties();
	glPopMatrix();

	glPushMatrix();
	glTranslated(50, 0, 0);
	this->drawParties();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, -50);
	this->drawParties();
	glPopMatrix();

	glPushMatrix();
	glTranslated(50, 0, -50);
	this->drawParties();
	glPopMatrix();

	Cuboid left(Point(0, 0, -25), 10, 45, 5), right(Point(50, 0, -25), 10, 45, 5);
	Cuboid top(Point(25, 0, -50), 10, 5, 45), bottom(Point(25, 0, 0), 10, 5, 45);
	Cuboid center(Point(25, 0, -25), 15, 5, 5), floor(Point(25, -0.2, -25), 0.2, 50, 50);
	Cuboid topOfCenter(Point(25, 15.1, -25), 0.2, 10, 10);

	glColor3ub(255, 255, 255);

	left.drawWithTexture(lakeWall.textureID, 10, 1);
	right.drawWithTexture(lakeWall.textureID, 10, 1);
	top.drawWithTexture(lakeWall.textureID, 10, 1);
	bottom.drawWithTexture(lakeWall.textureID, 10, 1);

	floor.drawWithTexture(floorLake.textureID, 1, 1);

	center.drawWithTextureNoTopBottom(lakeWall.textureID, 1, 1);

	glColor3f(0.5, 0.5, 0.5);
	topOfCenter.draw();

	glColor3f(1, 1, 1);


	glPushMatrix();
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Cylinder.textureID);
	glTranslatef(25, 15.2, -25);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 3, 4, 3, 32, 32);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix();
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Cylinder.textureID);
	glTranslatef(25, 17.2, -25);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 1.5, 2.5, 2, 32, 32);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix();
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Cylinder.textureID);
	glTranslatef(25, 15.2, -25);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 0.1, 0.1, 6, 32, 32);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	float waveAmplitude = 0.5f;
	float waveFrequency = 1.5f;

	float yOffset = waveAmplitude * sin(waveFrequency * time);
	float xOffset = waveAmplitude * cos((waveFrequency - 1) * time);
	float zOffset = waveAmplitude * sin(waveFrequency * time);

	Cuboid water(Point(25 + xOffset, yOffset - 1.5, -11.5 + zOffset), 8, 19, 44);
	Cuboid water2(Point(25 + xOffset, yOffset - 1.5, -36.5 + zOffset), 8, 19, 44);
	Cuboid water3(Point(11.5 + xOffset, yOffset - 1.5, -24 + zOffset), 8, 5.4, 19);
	Cuboid water4(Point(37.5 + xOffset, yOffset - 1.5, -24 + zOffset), 8, 5.4, 19);

	glColor3ub(84, 64, 63);


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDepthMask(GL_FALSE);

	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);

	water.drawWithTexture(Water.textureID, 10, 2);
	water2.drawWithTexture(Water.textureID, 10, 2);
	water3.drawWithTexture(Water.textureID, 6, 2);
	water4.drawWithTexture(Water.textureID, 6, 2);
	glColor3ub(255, 255, 255);

	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);
}