#include "SuperMarket.h"
#include <iostream>
#include "Gl/glut.h"
#include "Camera.h"
#include "Cuboid.h"
#include "Point.h"
#include "Texture.h"
#include<bits/stdc++.h>

void SuperMarket::loadTextures()
{
	roof.loadTexture("textures\\SuperMarket\\roof.jpg");
	wall.loadTexture("textures\\SuperMarket\\wall.jpg");
	floor.loadTexture("textures\\SuperMarket\\floor3.jpg");
	products.loadTexture("textures\\SuperMarket\\products.jpg");
	products2.loadTexture("textures\\SuperMarket\\products2.jpg");
	products3.loadTexture("textures\\SuperMarket\\products3.jpg");
	products5.loadTexture("textures\\SuperMarket\\products5.jpg");
	logo.loadTexture("textures\\SuperMarket\\logo.png");
	//makeup.loadTexture("textures\\SuperMarket\\makeup.jpg");
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


void SuperMarket::draw()
{
	// draw wall
	Cuboid left(Point(0, 0, -25), 52, 48, 2), right(Point(200, 0, -25), 52, 48, 2);
	Cuboid down(Point(100, 0, -25), 2, 48, 198), up(Point(100, 50, -25), 2, 48, 198);
	Cuboid back(Point(100, 0, -50), 50, 2, 198);
	glColor3ub(82, 46, 45);
	left.draw(); back.draw();
	glColor3ub(255, 255, 255);
	down.drawWithTexture(floor.textureID, 1, 1); up.drawWithTexture(roof.textureID, 1, 1);
	right.drawWithTexture(wall.textureID, 1, 1);


	// draw sheleves 
	Cuboid sheleves_1(Point(79, 2, -47), 30, 2, 158);
	Cuboid sheleves_2(Point(38, 2, -35), 30, 6, 40);
	Cuboid sheleves_3(Point(138, 2, -35), 30, 6, 40);
	Cuboid sheleves_4(Point(88, 2, -27), 30, 14, 20);
	Cuboid sheleves_5(Point(38, 2, -19), 30, 6, 40);
	Cuboid sheleves_6(Point(138, 2, -19), 30, 6, 40);
	Cuboid sheleves_7(Point(88, 2, -2.5), 30, 2, 140);
	Cuboid backOfSheleves_7(Point(88, 2, -0.5), 30, 0.2, 140);

	glColor3ub(255, 255, 255);
	sheleves_1.drawWithTextureOnOneFace(products5.textureID, "front", 4, 2);
	sheleves_2.drawWithTextureNoTopBottom(products3.textureID, 1, 1);
	sheleves_3.drawWithTextureNoTopBottom(products3.textureID, 1, 1);
	sheleves_4.drawWithTextureNoTopBottom(products3.textureID, 1, 1);
	sheleves_5.drawWithTextureNoTopBottom(products3.textureID, 1, 1);
	sheleves_6.drawWithTextureNoTopBottom(products3.textureID, 1, 1);
	sheleves_7.drawWithTextureOnOneFace(products2.textureID, "back", 3, 2);
	backOfSheleves_7.drawWithTextureOnOneFace(makeup.textureID, "front", 1, 1);
	Cuboid logoCuboid(Point(9, 30, -2), 10, 0.1, 14);
	logoCuboid.drawWithTextureNoTopBottom(logo.textureID, 1, 1);




}
