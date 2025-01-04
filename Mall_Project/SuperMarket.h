#pragma once
#include <iostream>
#include "Gl/glut.h"
#include "Camera.h"
#include "Cuboid.h"
#include "Point.h"
#include "Texture.h"
#include<bits/stdc++.h>
class SuperMarket
{
public:
	void loadTextures();
	void drawTable(Point center);
	void drawMonitor(Point center);
	void draw();
	Texture roof, wall, floor, products, products2, products3, products4, products5, logo, makeup, keyBoard
		, woodTable, laptopScreen;
};

