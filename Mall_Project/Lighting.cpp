#include "Lighting.h"

#define M_PI 3.14159265358979323846

inline double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}
void Lighting::setupLighting(Point lightPosition)
{
    LightPos[0] = lightPosition.x;
    LightPos[1] = lightPosition.y;
    LightPos[2] = lightPosition.z;
    LightPos[3] = 1.0f; 

    LightAmb[0] = 1.0f; LightAmb[1] = 1.0f; LightAmb[2] = 1.0f; LightAmb[3] = 1.0f; 
    LightDiff[0] = 1.0f; LightDiff[1] = 1.0f; LightDiff[2] = 1.0f; LightDiff[3] = 1.0f;
    LightSpec[0] = 1.0f; LightSpec[1] = 1.0f; LightSpec[2] = 1.0f; LightSpec[3] = 1.0f; 

    MatAmb[0] = 1.0f; MatAmb[1] = 1.0f; MatAmb[2] = 1.0f; MatAmb[3] = 1.0f;
    MatDif[0] = 0.8f; MatDif[1] = 0.8f; MatDif[2] = 0.8f; MatDif[3] = 1.0f;
    MatSpec[0] = 0.5f; MatSpec[1] = 0.5f; MatSpec[2] = 0.5f; MatSpec[3] = 1.0f;
    MatShn[0] = 50.0f; 

    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_POSITION, LightPos);
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff);
    glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec);

    glEnable(GL_LIGHTING);
    glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, MatDif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, MatSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, MatShn);
    glEnable(GL_COLOR_MATERIAL);
}

void Lighting::drawStreetLight(Point baseCenter, double poleHeight, double poleRadius, double curveRadius, double curveAngle, double lampSize, bool isLeftSide)
{
    GLUquadric* quad = gluNewQuadric();
    Point currentPosition = baseCenter;

    Point verticalArmStart(baseCenter.x, baseCenter.y + poleHeight - 12, baseCenter.z - 0.1);
    glColor3ub(101, 67, 33); 
    glPushMatrix();
    glTranslated(verticalArmStart.x, verticalArmStart.y, verticalArmStart.z);
    glRotated(-90, 1, 0, 0);
    gluCylinder(quad, poleRadius + 0.2, poleRadius + 0.2, poleHeight + 23, 32, 32);
    glPopMatrix();

    // Draw the curved arm
    currentPosition.z += poleHeight - 15.5;
    double angleStep = 5.0;
    int curveDirection = isLeftSide ? -1 : 1;

    for (double angle = 0; angle <= 180; angle += angleStep)
    {
        glPushMatrix();
        glTranslated(currentPosition.x, currentPosition.y + 40, currentPosition.z);
        glRotated(curveDirection * angle, 0, 1, 0);
        gluCylinder(quad, poleRadius + 0.4, poleRadius, angleStep / 360.0 * curveRadius * 2 * M_PI, 32, 32);
        glPopMatrix();

        double angleNext = angle + angleStep;
        currentPosition.x += curveRadius * (cos(toRadians(angleNext)) - cos(toRadians(angle))) * curveDirection;
        currentPosition.y += curveRadius * (sin(toRadians(angleNext)) - sin(toRadians(angle)));
    }

    Point lampPosition(currentPosition.x, currentPosition.y + 40, currentPosition.z);

    this->setupLighting(lampPosition); 

    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0f); 
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.05f);  
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.01f); 

    glPushMatrix();
    glColor3ub(255, 255, 0); 
    glTranslated(lampPosition.x, lampPosition.y, lampPosition.z);
    glutSolidSphere(lampSize, 20, 20);
    glPopMatrix();

    glColor3ub(255, 255, 255); 
}