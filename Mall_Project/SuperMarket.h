#pragma once
#include <iostream>
#include "Gl/glut.h"
#include "Camera.h"
#include "Cuboid.h"
#include "Point.h"
#include "Texture.h"
#include "FurnitureStore.h"
#include<bits/stdc++.h>
class SuperMarket
{
public:
	float waveAmplitude, waveFrequency, waveSpeed;
	void loadTextures();
	void drawTable(Point center);
	void drawMonitor(Point center);
	void drawChair(Point center);
	void drawLight();
	void draw();

	FurnitureStore chiar;
	Texture roof, backWall, floor, products, products2, products3, products4, products5, logo, friends, keyBoard
		, woodTable, laptopScreen, discounts, marketImage, welcome;
};

