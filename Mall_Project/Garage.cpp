#include "Garage.h"

void Garage::loadTexturesAndModels() {
    t.loadTexture("textures/garage/floor.png");
    a.loadTexture("textures/garage/roof.jpg");
    tank = new Model_3DS();
    tank->Load((char*)"models/garage/Tank/tank.3DS");
    train = new Model_3DS();
    train->Load((char*)"models/garage/3d model of maglev train/3/AVEENG_L.3DS");
    motor = new Model_3DS();
    motor->Load((char*)"models/garage/Motor/suzuki.3DS");
}

void Garage::draw() {
    float floorLength = 200.0f;
    float floorWidth = 150.1f;
    float floorHeight = 0.5f;
    Point floorPosition(105, 1, -395);

    Cuboid floor(floorPosition, floorHeight, floorWidth, floorLength);
    glPushMatrix();
    glColor3ub(255, 255, 255); 
    floor.drawWithTexture(t.textureID, 1, 1);
    glPopMatrix();

    Point barrierPosition(floorPosition.x, floorPosition.y + 35.5f, floorPosition.z + 40);
    Cuboid barrier(barrierPosition, 0, 80.0f, floorLength - 20);
    glPushMatrix();
    glColor3ub(255, 255, 255); 
    barrier.drawWithTexture(a.textureID, 1, 1);
    glPopMatrix();


    glPushMatrix();
    render3DModel(floorPosition.x + 20, floorPosition.y + 1, floorPosition.z + 30, 5, tank, 0);
    glPopMatrix();

    glPushMatrix();
    render3DModel(floorPosition.x - 27, floorPosition.y + 5 , floorPosition.z + 30, 0.002, train, 0);
    glPopMatrix();

    glPushMatrix();
    render3DModel(floorPosition.x - 72.5, floorPosition.y + 1, floorPosition.z + 35, 0.007, motor, 0);
    glPopMatrix();

    drawColumns(floorPosition, floorLength, floorWidth, floorHeight);
}

void Garage::drawColumns(Point floorPosition, float floorLength, float floorWidth, float floorHeight) {
    glLineWidth(10.0f);
    glPushMatrix();

    for (int i = 0; i < numSpots; i++) {
        float x1 = startX + i * (spotWidth + lineWidth);
        float z1 = startZ;
        float x2 = x1 + spotWidth;
        float z2 = startZ + spotHeight;
        float y = 1.5;

        glColor3f(0.8f, 0.8f, 0.8f); 
        glBegin(GL_LINE_LOOP);
        glVertex3f(x1, y, z1);
        glVertex3f(x2, y, z1);
        glVertex3f(x2, y, z2);
        glVertex3f(x1, y, z2);
        glEnd();
    }

    glColor3ub(255, 255, 255);
    glPopMatrix();


    GLUquadric* quad = gluNewQuadric();
    float columnRadius = 1.0f;
    float columnHeight = 10.0f;
    float spacing = 10.0f;

    for (float x = floorPosition.x - floorWidth / 2.0f; x <= floorPosition.x + floorWidth / 2.0f; x += spacing + 35) {
        float z = floorPosition.z + floorLength / 2.7f;
        glPushMatrix();
        glDisable(GL_TEXTURE_2D); 
        glColor3f(0.5f, 0.5f, 0.5f); 
        glTranslatef(x + 5, floorPosition.y - floorHeight / -2.0f, z - 5);
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quad, columnRadius + 3, columnRadius + 3, columnHeight + 25.25, 32, 32);
        glPopMatrix();
    }


    for (float z = floorPosition.z - floorLength / 2.0f; z <= floorPosition.z + floorLength / 5.0f; z += spacing) {
        for (float xOffset : { -floorWidth / 1.53f, floorWidth / 1.53f }) {
            glPushMatrix();
            glDisable(GL_TEXTURE_2D);
            glColor3f(0.5f, 0.5f, 0.5f); 
            glTranslatef(floorPosition.x + xOffset, floorPosition.y+1 - floorHeight / 2.0f, z + 30);
            glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
            gluCylinder(quad, columnRadius, columnRadius, columnHeight, 32, 32);
            glPopMatrix();
        }
    }

    gluDeleteQuadric(quad);
    glColor3ub(255, 255, 255); 
}

void Garage::render3DModel(float x, float y, float z, float scale, Model_3DS* model, float rotationAngle) {
    if (!model) return;

    glPushMatrix();
    glColor3ub(255, 255, 255); 
    glTranslatef(x, y, z);
    glRotatef(rotationAngle, 0, 1, 0);
    glScalef(scale, scale, scale);
    glEnable(GL_TEXTURE_2D); 
    glEnable(GL_DEPTH_TEST);  
    model->Draw();
    glPopMatrix();
}
