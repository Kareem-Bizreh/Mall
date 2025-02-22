#include <cstdlib>
#include <cmath>
#include "Fountain.h"

#define RAND_FACTOR 2.0f

float randf(float range) {
    return (float)rand() / (float)RAND_MAX * range * RAND_FACTOR;
}

void Drop::setSpeed(FVector3 newSpeed) {
    speed = newSpeed;
}

void Drop::setAcceleration(float newAcc) {
    acceleration = newAcc;
}

void Drop::setTime(float newTime) {
    time = newTime;
}

void Drop::updatePosition(FVector3 & position, float dtime,
                           Fountain & fountain) {
    time += dtime * 20.0f;
    if (time > 0.0f) {
        FVector3 newPosition;
        newPosition.set(speed.x * time,
                        speed.y * time - acceleration * time * time,
                        speed.z * time);
        position = newPosition;
        if (newPosition.y < 0.0) { /* the drop has fallen into the water */
            /* if there are too many drops per ray several drops would be seen as one.
               So we can't just set the time to 0.0  */
            time = time - int(time);
            if (time > 0.0) time -= 1.0;
        }
    } else {
        position.set(0.0f, 0.0f, 0.0f);
    }
}

// center is not set by this function. Just set fountain.center = ...
void Fountain::initialize(int levels, int raysPerStep, int dropsPerRay, float dropSize,
                          float angleMin, float angleMax,
                          float randomAngle, float acceleration) {
    this->numDrops = levels * raysPerStep * dropsPerRay;
    this->dropSize = dropSize;

    this->drops.clear();
    this->dropPositions.clear();
    this->drops.resize(numDrops);
    this->dropPositions.resize(numDrops);

    float randAcc; // acceleration changed randomly
    float timeElapsed;  // initial elapsed time for each drop
    FVector3 initialSpeed;  // initial speed for each drop
    float angleZ; // angle in the front view
    float angleY;  // angle in the top view
    float minSpeed = 0.2f, alpha = 0.5f, mag = 3.0f;

    for (int level = 0; level < levels; level++) {
        for (int ray = 0; ray < raysPerStep; ray++) {
            for (int drop = 0; drop < dropsPerRay; drop++) {
                randAcc = acceleration + randf(0.005f);
                if (levels > 1) {
                    int newAngle = (angleMax - angleMin)
                                   * (float)(level) / (levels - 1);
                    angleZ = angleMin + newAngle + randf(randomAngle);
                } else {
                    angleZ = angleMin + randf(randomAngle);
                }

                // speed update by levels
                float levelFactor = alpha * level + minSpeed;
                initialSpeed.x = cos(angleZ * DEGREE) * levelFactor;
                initialSpeed.y = sin(angleZ * DEGREE) * levelFactor;
                initialSpeed.z = cos(angleZ * DEGREE) * levelFactor;

                // speed update by rays
                angleY = (float)ray / (float)raysPerStep * 360.0f;
                initialSpeed.x = initialSpeed.x * cos(angleY * DEGREE) * mag;
                initialSpeed.z = initialSpeed.z * sin(angleY * DEGREE) * mag;
                initialSpeed.y = initialSpeed.y * mag;

                // initialize the drops
                timeElapsed = initialSpeed.y / randAcc;
                int idx = drop + ray * dropsPerRay + level * dropsPerRay * raysPerStep;
                drops[idx].setSpeed(initialSpeed);
                drops[idx].setAcceleration(randAcc);
                drops[idx].setTime(timeElapsed * drop / dropsPerRay);
            }
        }
    }
}

void Fountain::update(float dtime) {
    for (int i = 0; i < numDrops; i++)
        drops[i].updatePosition(dropPositions[i], dtime, *this);
}

void Fountain::render() const {
    glEnableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);

    glPushMatrix();

    // draw the drops
    glPointSize(dropSize);
    glVertexPointer(3, GL_FLOAT, 0, dropPositions.data());

    // move the fountain to the center of the pool
    glTranslatef(center.x, center.y, center.z);
    glDrawArrays(GL_POINTS, 0, numDrops);

    glPopMatrix();
}