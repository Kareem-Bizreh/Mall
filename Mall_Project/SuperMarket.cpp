#include "SuperMarket.h"
#include <iostream>
#include "Gl/glut.h"
#include "Camera.h"
#include "Cuboid.h"
#include "Point.h"
#include "Texture.h"
#include<bits/stdc++.h>
#include "FurnitureStore.h"

void SuperMarket::loadTextures()
{
	roof.loadTexture("textures\\SuperMarket\\roof.jpg");
	backWall.loadTexture("textures\\SuperMarket\\all.jpg");
	floor.loadTexture("textures\\SuperMarket\\floor3.jpg");
	products.loadTexture("textures\\SuperMarket\\products.jpg");
	products2.loadTexture("textures\\SuperMarket\\products2.jpg");
	products3.loadTexture("textures\\SuperMarket\\products3.jpg");
	products5.loadTexture("textures\\SuperMarket\\products5.jpg");
	logo.loadTexture("textures\\SuperMarket\\logo.png");
	woodTable.loadTexture("textures\\SuperMarket\\table.jpg");
	keyBoard.loadTexture("textures\\SuperMarket\\keyboard2.jpg");
	laptopScreen.loadTexture("textures\\SuperMarket\\screen.png");
	friends.loadTexture("textures\\SuperMarket\\HelloWorld.jpg");
	discounts.loadTexture("textures\\SuperMarket\\discounts.jpg");
	marketImage.loadTexture("textures\\SuperMarket\\MarketLogo.jpg");
	welcome.loadTexture("textures\\SuperMarket\\welcome.png");
	floorLake.loadTexture("textures\\SuperMarket\\floorLake2.jpg");
	lakeWall.loadTexture("textures\\SuperMarket\\lakeWall5.jpg");
	partie.loadTexture("textures\\SuperMarket\\parties.jpg");
	Water.loadTexture("textures\\SuperMarket\\water.jpg");
	Cylinder.loadTexture("textures\\SuperMarket\\lakeWall2.jpg");


}

void SuperMarket::drawTable(Point center) {

	glColor3ub(255, 255, 255);
	Cuboid(Point(center.x, center.y, center.z), 15, 1, 40).drawWithTexture(woodTable.textureID, 3, 4);

	Cuboid(Point(center.x - 20.5, center.y, center.z - 7), 15, 15, 1).drawWithTexture(woodTable.textureID, 3, 3);

	Cuboid(Point(center.x + 20.5, center.y, center.z - 7), 15, 15, 1).drawWithTexture(woodTable.textureID, 3, 3);

	Cuboid(Point(center.x, center.y + 15, center.z - 7), 1, 15, 42).drawWithTexture(woodTable.textureID, 3, 4);
}

void SuperMarket::drawMonitor(Point center) {
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


void SuperMarket::drawChair(Point center) {
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


void SuperMarket::drawLight()
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

void SuperMarket::drawParties()
{
	Cuboid parties(Point(0, 0, 0), 11, 5, 5), upParties(Point(0, 11, 0), 2, 7, 7);

	glColor3ub(255, 255, 255);
	parties.drawWithTexture(partie.textureID, 1, 1);
	upParties.drawWithTexture(partie.textureID,1,1);
}

void SuperMarket::drawLake()
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

	Cuboid left(Point(0, 0, -25), 10, 45,5), right(Point(50, 0, -25), 10, 45, 5);
	Cuboid top(Point(25, 0, -50), 10, 5, 45), bottom(Point(25, 0, 0), 10, 5, 45);
	Cuboid center(Point(25, 0, -25), 12, 5, 5), floor(Point(25, -0.2, -25), 0.2, 50, 50);
	Cuboid topOfCenter(Point(25, 12.1, -25), 0.2, 10, 10);

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
	glTranslatef(25, 12.2, -25);
	glRotated(-90, 1, 0, 0);
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Cylinder.textureID);
	gluCylinder(quad, 3, 3, 2, 32, 32);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix();
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Cylinder.textureID);
	glTranslatef(25, 12.3, -25);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 3, 4, 2, 32, 32);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix();
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Cylinder.textureID);
	glTranslatef(25, 14.2, -25);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 1.5, 2.5, 1, 32, 32);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glPushMatrix();
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Cylinder.textureID);
	glTranslatef(25, 12.2, -25);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 0.1, 0.1, 5, 32, 32);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	Cuboid water(Point(25, 0.2, -12.5), 5, 19, 44);
	Cuboid water2(Point(25, 0.2, -37.5), 5, 19, 44);
	Cuboid water3(Point(12.5, 0.2, -25), 5, 5.4, 19);
	Cuboid water4(Point(37.5, 0.2, -25), 5, 5.4, 19);

	glColor3ub(84, 64, 63);
	

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDepthMask(GL_FALSE);

	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);

	water.drawWithTexture(Water.textureID, 10, 2);
	water2.drawWithTexture(Water.textureID, 10, 2);
	water3.drawWithTexture(Water.textureID, 6, 2);
	water4.drawWithTexture(Water.textureID, 6, 2);

	glDepthMask(GL_TRUE);

	glDisable(GL_BLEND);
}


void SuperMarket::draw()
{
	GLUquadric* quad = gluNewQuadric();

	// draw wall
	Cuboid left(Point(0, 0, -25), 50, 49.8, 0.2), right(Point(200, 0, -25), 50, 49.8, 0.2);
	Cuboid down(Point(100, 0, -25), 0.2, 49.8, 199.8), up(Point(100, 50, -25), 2, 49.8, 199.8);
	Cuboid back(Point(100, 0, -50), 50, 0.2, 199.8);

	glColor3ub(255, 255, 255);
	down.drawWithTexture(floor.textureID, 1, 1); up.drawWithTextureOnOneFace(backWall.textureID, "front", 10, 3);
	right.drawWithTextureOnOneFace(welcome.textureID, "left", 1, 1);
	left.drawWithTextureOnOneFace(discounts.textureID, "right", 2, 2);
	back.drawWithTextureOnOneFace(backWall.textureID, "front", 10, 3);

	// draw sheleves 
	Cuboid sheleves_1(Point(79, 0.2, -47), 30, 2, 158);
	Cuboid sheleves_2(Point(38, 0.2, -35), 30, 6, 40);
	Cuboid sheleves_3(Point(138, 0.2, -35), 30, 6, 40);
	Cuboid sheleves_4(Point(88, 0.2, -27), 30, 14, 20);
	Cuboid sheleves_5(Point(38, 0.2, -19), 30, 6, 40);
	Cuboid sheleves_6(Point(138, 0.2, -19), 30, 6, 40);
	Cuboid sheleves_7(Point(88, 0.2, -1.7), 30, 2, 140);
	Cuboid backOfSheleves_7(Point(88, 0.2, -0.5), 49.5, 0.2, 140);
	Cuboid backOfSheleves_7_2(Point(88, 0.2, -0.2), 49.5, 0.1, 140);
	Cuboid logoCuboid(Point(9, 30, -1), 10, 0.1, 14);

	glColor3ub(255, 255, 255);
	sheleves_1.drawWithTextureOnOneFace(products5.textureID, "front", 4, 2);
	sheleves_2.drawWithTextureNoTopBottom(products3.textureID, 1, 1);
	sheleves_3.drawWithTextureNoTopBottom(products3.textureID, 1, 1);
	sheleves_4.drawWithTextureNoTopBottom(products3.textureID, 1, 1);
	sheleves_5.drawWithTextureNoTopBottom(products3.textureID, 1, 1);
	sheleves_6.drawWithTextureNoTopBottom(products3.textureID, 1, 1);
	sheleves_7.drawWithTextureOnOneFace(products2.textureID, "back", 3, 2);
	backOfSheleves_7.drawWithTextureOnOneFace(marketImage.textureID, "front", 1, 1);

	logoCuboid.drawWithTextureNoTopBottom(logo.textureID, 1, 1);

	//draw table 
	glPushMatrix();
	glTranslated(173, 0, -35); // point x = 173 , y = 0 , z = -35
	glRotated(270, 0, 1, 0);
	this->drawMonitor(Point(-5, 16.1, -3));
	glScaled(0.5, 1, 0.7);
	this->drawTable(Point(0, 0.1, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(190, 0, -40);
	glRotated(-45, 0, 1, 0);
	this->drawChair(Point(0, 0, 0));
	glPopMatrix();

	glPushMatrix();
	glTranslated(180, 12, -30);
	glScaled(1, 0.8, 1);
	this->drawLight();
	glPopMatrix();

	glPushMatrix();
	glTranslated(13, 12, -30);
	glScaled(1, 0.8, 1);
	this->drawLight();
	glPopMatrix();

	// 	gluCylinder(quad, 0.1, 0.1, 15, 32, 32);
	// draw cylinder to load logo
	glColor3ub(0, 0, 0);
	glPushMatrix();
	glTranslatef(6, 40, -1);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 0.1, 0.1, 10, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(12, 40, -1);
	glRotated(-90, 1, 0, 0);
	gluCylinder(quad, 0.1, 0.1, 10, 32, 32);
	glPopMatrix();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDepthMask(GL_FALSE);

	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);

	backOfSheleves_7_2.draw();

	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);
}


