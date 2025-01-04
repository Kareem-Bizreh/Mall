#include <gl/glut.h>
#include "Cylinder.h"

void Cylinder::draw(Point center, float radius, float height, int slices) {
	GLUquadric* quad = gluNewQuadric();

	glPushMatrix();
	glTranslated(center.x, center.y, center.z);
	glRotatef(90, 1.0f, 0.0f, 0.0f);

	gluCylinder(quad, radius, radius, height, slices, slices);
	gluDisk(quad, 0, radius, slices, slices); // قاعدة الأسطوانة السفلى
	glPushMatrix();
	glTranslatef(0, 0, center.z + height);
	gluDisk(quad, 0, radius, slices, slices); // قاعدة الأسطوانة العليا
	glPopMatrix();
	glPopMatrix();
	gluDeleteQuadric(quad);
}