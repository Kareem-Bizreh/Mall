#pragma once
#include "Cuboid.h"
#include "Texture.h"
#include "flag.h"
#include "Model_3DS.h"

class Outside {
private:
    Texture ground, mall_ground, side, right_door, left_door, mall_name, flag, stick, street, entry;
    Flag wavingFlag;
    Model_3DS* tank;

    bool isInsideMall = false;
public:
    Outside(Texture flagTexture);
    void OutsideTextures();
 
    void draw();
    void render3DModel(float x, float y, float z, float scale, Model_3DS* model);
};