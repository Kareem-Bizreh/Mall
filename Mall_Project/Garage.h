#ifndef GARAGE_H
#define GARAGE_H

#include <GL/glut.h>
#include "Model_3DS.h"
#include "Texture.h"

class Garage {
private:
    Texture floor;
    Texture roof;
    Model_3DS* tank;
    Model_3DS* train;
    Model_3DS* motor;
    Model_3DS* Mercedes;
    float startX = 25.5;
    float startZ = -385;
    float lineWidth = 30.8;
    float spotWidth = 15.5;
    float spotHeight = 50.0;
    int numSpots = 4;
    float columnRadius = 0.1f;
    float columnHeight = 1.0f;
    float canopyWidth = (numSpots * (spotWidth + lineWidth)) - lineWidth;
    float canopyDepth = spotHeight + 1.0f;

public:
    void loadTexturesAndModels();
    void draw();
    void drawColumns(Point floorPosition, float floorLength, float floorWidth, float floorHeight);
    void render3DModel(float x, float y, float z, float scale, Model_3DS* model, float rotationAngle);
};

#endif 
