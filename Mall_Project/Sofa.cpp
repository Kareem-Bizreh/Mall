#include <gl/glut.h>
#include "Sofa.h"
#include "Point.h"
#include "Cuboid.h"

void Sofa::draw(Point center) {

	// sofa base
	glColor3ub(22, 22, 22);
	Cuboid(Point(center.x, center.y, center.z), 1, 7, 10).draw();

	//left hand
	glColor3ub(55, 55, 55);
	Cuboid(Point(center.x - 5.25, center.y, center.z), 5, 7, 0.5).draw();

	//right hand
	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x + 5.25, center.y, center.z), 5, 7, 0.5).draw();

	//back 
	glColor3ub(136, 0, 21);
	Cuboid(Point(center.x, center.y, center.z - 3.75), 5, 0.5, 11).draw();

	//leg front right
	glColor3ub(55, 55, 55);
	Cuboid(Point(center.x + 5.25, center.y - 2, center.z + 3.2), 2, 0.6, 0.5).draw();

	//leg front left
	glColor3ub(55, 55, 55);
	Cuboid(Point(center.x - 5.25, center.y - 2, center.z + 3.2), 2, 0.6, 0.5).draw();

	//leg back left
	glColor3ub(55, 55, 55);
	Cuboid(Point(center.x + 5.25, center.y - 2, center.z - 3.7), 2, 0.6, 0.5).draw();

	//leg back right
	glColor3ub(55, 55, 55);
	Cuboid(Point(center.x - 5.25, center.y - 2, center.z - 3.7), 2, 0.6, 0.5).draw();

}
void Sofa::drawTriple(Point center) {
	//first base
	glColor3ub(44, 44, 44);
	Cuboid(Point(center.x, center.y, center.z), 0.5, 7, 10).draw();

	//second base
	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 8.5, center.y, center.z + 4), 0.5, 15, 7).draw();

	//right hand 
	glColor3ub(126, 132, 247);
	Cuboid(Point(center.x + 4.75, center.y + 0.5, center.z), 4.5, 7, 0.5).draw();

	//first back
	glColor3ub(22, 22, 22);
	Cuboid(Point(center.x - 3.75, center.y + 0.5, center.z - 3.25), 4.5, 0.5, 16.5).draw();

	//second back
	glColor3ub(155, 155, 155);
	Cuboid(Point(center.x - 11.75, center.y + 0.5, center.z + 4), 4.5, 14, 0.5).draw();

	//left hand
	glColor3ub(123, 20, 60);
	Cuboid(Point(center.x - 8.5, center.y + 0.5, center.z + 11.25), 4.5, 0.5, 7).draw();

	//first front leg
	Cuboid(Point(center.x + 4.75, center.y - 2, center.z + 3.2), 2, 0.6, 0.5).draw();

	//first back leg
	Cuboid(Point(center.x + 4.75, center.y - 2, center.z - 3.2), 2, 0.6, 0.5).draw();

	//second front leg
	Cuboid(Point(center.x - 5.25, center.y - 2, center.z + 3.2), 2, 0.6, 0.5).draw();

	//second back leg
	Cuboid(Point(center.x - 5.25, center.y - 2, center.z - 3.2), 2, 0.6, 0.5).draw();

	//third front leg
	Cuboid(Point(center.x - 5.25, center.y - 2, center.z + 11.2), 2, 0.6, 0.5).draw();

	//third back leg
	Cuboid(Point(center.x - 11.75, center.y - 2, center.z + 11.2), 2, 0.6, 0.5).draw();

	//fourth back leg
	Cuboid(Point(center.x - 11.75, center.y - 2, center.z - 3.2), 2, 0.6, 0.5).draw();
}