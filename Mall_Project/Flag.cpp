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

    // Get elapsed time from GLUT (in milliseconds)
    float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;  // Convert to seconds

    glTranslatef(center.x, center.y, center.z);


    flag.Use();  // Apply the texture to the flag

    // Adjust these values for better waving effect
    float waveAmplitude = 1.0f;  // Increased for more visible displacement
    float waveFrequency = 5.0f;  // Increased frequency for faster oscillations
    float waveSpeed = 2.0f;      // Increased speed for faster wave movement

    // Draw the flag as a grid of quads, each being deformed by the wave
    glBegin(GL_QUADS);
    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
            // Base coordinates for each quad
            float x1 = (float)j / cols * width - width / 2;
            float y1 = (float)i / rows * height - height / 2;
            float x2 = (float)(j + 1) / cols * width - width / 2;
            float y2 = (float)(i + 1) / rows * height - height / 2;

            // Apply wave effect on the Z-axis (vertical displacement)
            // Use sine waves with time for the waving effect
            // Modify Z-axis motion for dynamic horizontal shift
            float z1 = waveAmplitude * sin(waveFrequency * (x1 + time * waveSpeed));
            float z2 = waveAmplitude * sin(waveFrequency * (x2 + time * waveSpeed));
            float z3 = waveAmplitude * sin(waveFrequency * (x2 + time * waveSpeed));
            float z4 = waveAmplitude * sin(waveFrequency * (x1 + time * waveSpeed));

            // Keep texture coordinates fixed (no movement of texture)
            float texCoordX1 = (float)j / cols;
            float texCoordY1 = (float)i / rows;
            float texCoordX2 = (float)(j + 1) / cols;
            float texCoordY2 = (float)(i + 1) / rows;

            // Apply texture coordinates and vertices for the quad with fixed texture
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



