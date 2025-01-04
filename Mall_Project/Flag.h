#pragma once
#include <GL/glut.h>
#include "stb_image.h"
#include "Cuboid.h"
#include "Texture.h"

class Flag : public Cuboid {
private:
    int rows, cols;                   
    float waveAmplitude, waveFrequency, waveSpeed; 
    Texture flag,stick;

public:
    Flag(Point center, float width, float height, float depth, int rows, int cols, Texture flag,Texture stick);

    void setWaveProperties(float amplitude, float frequency, float speed);

    void drawWavingFlag(); 
   
};
