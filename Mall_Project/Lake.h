#pragma once
#include "Texture.h"
#include "FurnitureStore.h"
#include<bits/stdc++.h>
class Lake
{
public:
	void loadTextures();
	void drawLake();
	void drawParties();
	void drawWater();
	Texture lakeWall, floorLake, partie, Water, Cylinder;
};