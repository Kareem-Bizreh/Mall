#include "flag.h"


Flag::Flag(Point center, float width, float height, float depth, int rows, int cols, Texture flag, Texture stick)
    : Cuboid(center, width, height, depth), rows(rows), cols(cols), flag(flag),stick(stick) {
    waveAmplitude = 0.1f;
    waveFrequency = 2.0f;
    waveSpeed = 10.0f;
}

void Flag::setWaveProperties(float amplitude, float frequency, float speed) {
    waveAmplitude = amplitude;
    waveFrequency = frequency;
    waveSpeed = speed;
}
void Flag::drawWavingFlag() {
    glPushMatrix();

    float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;  

    glTranslatef(center.x, center.y, center.z);


    flag.Use();  

    float waveAmplitude = 1.0f;  
    float waveFrequency = 5.0f;  
    float waveSpeed = 2.0f;     

    glBegin(GL_QUADS);
    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
            float x1 = (float)j / cols * width - width / 2;
            float y1 = (float)i / rows * height - height / 2;
            float x2 = (float)(j + 1) / cols * width - width / 2;
            float y2 = (float)(i + 1) / rows * height - height / 2;

            float z1 = waveAmplitude * sin(waveFrequency * (x1 + time * waveSpeed));
            float z2 = waveAmplitude * sin(waveFrequency * (x2 + time * waveSpeed));
            float z3 = waveAmplitude * sin(waveFrequency * (x2 + time * waveSpeed));
            float z4 = waveAmplitude * sin(waveFrequency * (x1 + time * waveSpeed));

            float texCoordX1 = (float)j / cols;
            float texCoordY1 = (float)i / rows;
            float texCoordX2 = (float)(j + 1) / cols;
            float texCoordY2 = (float)(i + 1) / rows;

            glTexCoord2f(texCoordX1, texCoordY1);
            glVertex3f(x1, y1, z1);

            glTexCoord2f(texCoordX2, texCoordY1);
            glVertex3f(x2, y1, z2);

            glTexCoord2f(texCoordX2, texCoordY2);
            glVertex3f(x2, y2, z3);

            glTexCoord2f(texCoordX1, texCoordY2);
            glVertex3f(x1, y2, z4);
        }
    }
    glEnd();

    glPopMatrix();
}



