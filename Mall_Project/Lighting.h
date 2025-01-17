#pragma once
#include <GL/glut.h>
#include <bits/stdc++.h>
#include "Point.h"
#include "math.h"

typedef float M3DMatrix44f[16]; 
typedef float M3DVector4f[4];   
class Lighting
{
public:
    void setupLighting(Point lightPosition);
    void drawStreetLight(Point baseCenter, double poleHeight, double poleRadius, double curveRadius, double curveAngle, double lampSize, bool isLeftSide);

        // light settings
        GLfloat LightPos[4];  
        GLfloat LightAmb[4];  
        GLfloat LightDiff[4];

        GLfloat LightDir[4];  
        GLfloat LightSpec[4]; 

        GLfloat MatAmb[4];   
        GLfloat MatDif[4];    
        GLfloat MatSpec[4];   

        GLfloat MatShn[1]; 
        M3DMatrix44f shadowMat;
        M3DVector4f vPlaneEquation;
    
};

