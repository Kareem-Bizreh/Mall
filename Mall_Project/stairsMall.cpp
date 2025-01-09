#include "stairsMall.h"

void stairsMall::draw(Point center) {

	//down stairs
	glColor3ub(22, 22, 22);
	Cuboid(Point(center.x, center.y, center.z), 1.5, 10, 20).draw();

	glColor3ub(155, 155, 155);
	Cuboid(Point(center.x, center.y + 1.5, center.z - 4), 1.5, 10, 20).draw();

	glColor3ub(200, 200, 200);
	Cuboid(Point(center.x, center.y + 3, center.z - 8), 1.5, 10, 20).draw();

	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x, center.y + 4.5, center.z - 12), 1.5, 10, 20).draw();

	//------------------------------------
	glColor3ub(215, 215, 215);
	Cuboid(Point(center.x, center.y + 6, center.z - 16), 1.5, 10, 20).draw();

	glColor3ub(155, 155, 155);
	Cuboid(Point(center.x, center.y + 7.5, center.z - 20), 1.5, 10, 20).draw();

	glColor3ub(200, 200, 200);
	Cuboid(Point(center.x, center.y + 9, center.z - 24), 1.5, 10, 20).draw();

	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x, center.y + 10.5, center.z - 28), 1.5, 10, 20).draw();

	glColor3ub(215, 215, 215);
	Cuboid(Point(center.x, center.y + 12, center.z - 32), 1.5, 10, 20).draw();

	glColor3ub(200, 200, 200);
	Cuboid(Point(center.x, center.y + 13.5, center.z - 36), 1.5, 10, 20).draw();

	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x, center.y + 15, center.z - 40), 1.5, 10, 20).draw();

	glColor3ub(215, 215, 215);
	Cuboid(Point(center.x, center.y + 15, center.z - 50), 1.5, 10, 20).draw();

	glColor3ub(215, 215, 215);
	Cuboid(Point(center.x - 66, center.y + 15, center.z - 50), 1.5, 10, 20).draw();

	//Bridge
	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 33, center.y + 15, center.z - 46), 1.5, 18, 46).draw();

	//up stairs
	glColor3ub(180, 180, 180);
	Cuboid(Point(center.x - 66, center.y + 15, center.z - 38), 1.5, 14, 20).draw();

	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 66, center.y + 16.5, center.z - 31), 1.5, 10, 20).draw();

	glColor3ub(180, 180, 180);
	Cuboid(Point(center.x - 66, center.y + 18, center.z - 27), 1.5, 10, 20).draw();

	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 66, center.y + 19.5, center.z - 23), 1.5, 10, 20).draw();

	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 66, center.y + 21, center.z - 19), 1.5, 10, 20).draw();

	glColor3ub(180, 180, 180);
	Cuboid(Point(center.x - 66, center.y + 22.5, center.z - 15), 1.5, 10, 20).draw();

	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 66, center.y + 24, center.z - 11), 1.5, 10, 20).draw();

	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 66, center.y + 25.5, center.z - 7), 1.5, 10, 20).draw();

	glColor3ub(180, 180, 180);
	Cuboid(Point(center.x - 66, center.y + 27, center.z - 3), 1.5, 10, 20).draw();

	//----------------
	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 66, center.y + 28.5, center.z + 1), 1.5, 10, 20).draw();


	glColor3ub(240, 240, 240);
	Cuboid(Point(center.x - 66, center.y + 30, center.z + 5), 1.5, 10, 20).draw();

	glColor3ub(180, 180, 180);
	Cuboid(Point(center.x - 66, center.y + 30, center.z + 16), 1.5, 12, 20).draw();

	glColor3ub(150, 150, 150);
	Cuboid(Point(center.x - 51, center.y + 30, center.z + 12),1.5,20,10).draw();

	glColor3ub(180, 180, 180);
	Cuboid(Point(center.x - 47, center.y + 31.5, center.z + 12), 1.5, 20, 10).draw();

	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 43, center.y + 33, center.z + 12), 1.5, 20, 10).draw();

	glColor3ub(150, 150, 150);
	Cuboid(Point(center.x - 39, center.y + 34.5, center.z + 12), 1.5, 20, 10).draw();

	glColor3ub(180, 180, 180);
	Cuboid(Point(center.x - 35, center.y + 36, center.z + 12), 1.5, 20, 10).draw();

	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 31, center.y + 37.5, center.z + 12), 1.5, 20, 10).draw();

	//------------------
	glColor3ub(150, 150, 150);
	Cuboid(Point(center.x - 27, center.y + 39, center.z + 12), 1.5, 20, 10).draw();

	glColor3ub(180, 180, 180);
	Cuboid(Point(center.x - 23, center.y + 40.5, center.z + 12), 1.5, 20, 10).draw();

	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 19, center.y + 42, center.z + 12), 1.5, 20, 10).draw();
	
	//---------------------------
	glColor3ub(150, 150, 150);
	Cuboid(Point(center.x - 27, center.y + 39, center.z + 12), 1.5, 20, 10).draw();

	glColor3ub(180, 180, 180);
	Cuboid(Point(center.x - 23, center.y + 40.5, center.z + 12), 1.5, 20, 10).draw();

	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 19, center.y + 42, center.z + 12), 1.5, 20, 10).draw();

	//---------------------------
	glColor3ub(150, 150, 150);
	Cuboid(Point(center.x - 15, center.y + 43.5, center.z + 12), 1.5, 20, 10).draw();

	glColor3ub(180, 180, 180);
	Cuboid(Point(center.x - 11, center.y + 45, center.z + 12), 1.5, 20, 10).draw();

	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 7, center.y + 46.5, center.z + 12), 1.5, 20, 10).draw();

	//---------------------------
	glColor3ub(150, 150, 150);
	Cuboid(Point(center.x - 3, center.y + 48, center.z + 12), 1.5, 20, 10).draw();

	glColor3ub(180, 180, 180);
	Cuboid(Point(center.x + 1, center.y + 49.5, center.z + 12), 1, 20, 10).draw();

	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x + 5, center.y + 50.5, center.z + 12), 1, 20, 10).draw();

	glColor3ub(180, 180, 180);
	Cuboid(Point(center.x + 16, center.y + 50.5, center.z + 12), 1, 20, 12).draw();

	//mirrors
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4ub(163, 163, 163, 182);
	//right
	Cuboid(Point(center.x + 10.6, center.y, center.z - 2), 15, 6, 1).draw();
	
	Cuboid(Point(center.x + 10.6, center.y + 1.5, center.z - 7), 15, 4, 1).draw();

	Cuboid(Point(center.x + 10.6, center.y + 3, center.z - 11), 15, 4, 1).draw();

	Cuboid(Point(center.x + 10.6, center.y + 4.5, center.z - 15), 15, 4, 1).draw();

	Cuboid(Point(center.x + 10.6, center.y + 6, center.z - 19), 15, 4, 1).draw();

	Cuboid(Point(center.x + 10.6, center.y + 7.5, center.z - 23), 15, 4, 1).draw();

	Cuboid(Point(center.x + 10.6, center.y + 9, center.z - 27), 15, 4, 1).draw();

	Cuboid(Point(center.x + 10.6, center.y + 10.5, center.z - 31), 15, 4, 1).draw();

	Cuboid(Point(center.x + 10.6, center.y + 12, center.z - 35), 15, 4, 1).draw();

	Cuboid(Point(center.x + 10.6, center.y + 13.5, center.z - 39), 15, 4, 1).draw();

	Cuboid(Point(center.x + 10.6, center.y + 15, center.z - 48), 15, 14, 1).draw();

	//left 
	Cuboid(Point(center.x - 10.6, center.y, center.z - 2), 15, 6, 1).draw();

	Cuboid(Point(center.x - 10.6, center.y + 1.5, center.z - 7), 15, 4, 1).draw();

	Cuboid(Point(center.x - 10.6, center.y + 3, center.z - 11), 15, 4, 1).draw();

	Cuboid(Point(center.x - 10.6, center.y + 4.5, center.z - 15), 15, 4, 1).draw();

	Cuboid(Point(center.x - 10.6, center.y + 6, center.z - 19), 15, 4, 1).draw();

	Cuboid(Point(center.x - 10.6, center.y + 7.5, center.z - 23), 15, 4, 1).draw();

	Cuboid(Point(center.x - 10.6, center.y + 9, center.z - 27), 15, 4, 1).draw();

	Cuboid(Point(center.x - 10.6, center.y + 10.5, center.z - 31), 15, 4, 1).draw();

	Cuboid(Point(center.x - 10.6, center.y + 12, center.z - 35), 15, 4, 1).draw();

	//Bridge
	Cuboid(Point(center.x - 33, center.y + 15, center.z - 36.5), 15, 1, 46).draw();

	//up
	Cuboid(Point(center.x - 55.5, center.y + 15, center.z - 34),15,6,1).draw();

	Cuboid(Point(center.x - 55.5, center.y + 16.5, center.z - 28.5), 15, 5, 1).draw();

	Cuboid(Point(center.x - 55.5, center.y + 18, center.z - 24), 15, 4, 1).draw();

	Cuboid(Point(center.x - 55.5, center.y + 19.5, center.z - 20), 15, 4, 1).draw();

	Cuboid(Point(center.x - 55.5, center.y + 21, center.z - 16), 15, 4, 1).draw();

	Cuboid(Point(center.x - 55.5, center.y + 22.5, center.z - 12), 15, 4, 1).draw();

	Cuboid(Point(center.x - 55.5, center.y + 24, center.z - 8), 15, 4, 1).draw();

	Cuboid(Point(center.x - 55.5, center.y + 25.5, center.z - 4), 15, 4, 1).draw();

	Cuboid(Point(center.x - 55.5, center.y + 27, center.z ), 15, 4, 1).draw();

	Cuboid(Point(center.x - 50.5, center.y + 30, center.z + 1.5), 15, 1, 9).draw();

	Cuboid(Point(center.x - 44, center.y + 31.5, center.z + 1.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 40, center.y + 33, center.z + 1.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 36, center.y + 34.5, center.z + 1.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 32, center.y + 36, center.z + 1.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 28, center.y + 37.5, center.z + 1.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 24, center.y + 39, center.z + 1.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 20, center.y + 40.5, center.z + 1.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 16, center.y + 42, center.z + 1.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 12, center.y + 43.5, center.z + 1.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 8, center.y + 45, center.z + 1.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 4, center.y + 46.5, center.z + 1.5), 15, 1, 4).draw();

	Cuboid(Point(center.x , center.y + 48, center.z + 1.5), 15, 1, 4).draw();

	Cuboid(Point(center.x + 4, center.y + 49.5, center.z + 1.5), 15, 1, 4).draw();
	// bridge
	Cuboid(Point(center.x - 33, center.y + 15, center.z - 55.25),15,0.5,88).draw();

	//------
	Cuboid(Point(center.x - 76.48, center.y + 15, center.z - 43),15,24,1).draw();

	Cuboid(Point(center.x - 76.48, center.y + 16.5, center.z - 28.5), 15, 5, 1).draw();

	Cuboid(Point(center.x - 76.48, center.y + 18, center.z - 24), 15, 4, 1).draw();

	Cuboid(Point(center.x - 76.48, center.y + 19.5, center.z - 20), 15, 4, 1).draw();

	Cuboid(Point(center.x - 76.48, center.y + 21, center.z - 16), 15, 4, 1).draw();
	
	Cuboid(Point(center.x - 76.48, center.y + 22.5, center.z - 12), 15, 4, 1).draw();

	Cuboid(Point(center.x - 76.48, center.y + 24, center.z - 8), 15, 4, 1).draw();

	Cuboid(Point(center.x - 76.48, center.y + 25.5, center.z - 4), 15, 4, 1).draw();

	Cuboid(Point(center.x - 76.48, center.y + 27, center.z ), 15, 4, 1).draw();

	Cuboid(Point(center.x - 76.48, center.y + 28.5, center.z + 4), 15, 4, 1).draw();

	Cuboid(Point(center.x - 76.48, center.y + 30, center.z + 14.5), 15, 17, 1).draw();

	//left up 

	Cuboid(Point(center.x - 66, center.y + 30, center.z + 22.5), 15, 1, 20).draw();

	Cuboid(Point(center.x - 51, center.y + 30, center.z + 22.5), 15, 1, 10).draw();
	
	Cuboid(Point(center.x - 44, center.y + 31.5, center.z + 22.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 40, center.y + 33, center.z + 22.5), 15, 1, 4).draw();
	
	Cuboid(Point(center.x - 36, center.y + 34.5, center.z + 22.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 32, center.y + 36, center.z + 22.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 28, center.y + 37.5, center.z + 22.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 24, center.y + 39, center.z + 22.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 20, center.y + 40.5, center.z + 22.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 16, center.y + 42, center.z + 22.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 12, center.y + 43.5, center.z + 22.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 8, center.y + 45, center.z + 22.5), 15, 1, 4).draw();

	Cuboid(Point(center.x - 4, center.y + 46.5, center.z + 22.5), 15, 1, 4).draw();

	Cuboid(Point(center.x, center.y + 48, center.z + 22.5), 15, 1, 4).draw();

	Cuboid(Point(center.x + 4, center.y + 49.5, center.z + 22.5), 15, 1, 4).draw();

	Cuboid(Point(center.x + 13.75, center.y + 50.5, center.z + 1.5), 15, 1, 15.5).draw();

	Cuboid(Point(center.x + 13.75, center.y + 50.5, center.z + 22.5), 15, 1, 15.5).draw();

	Cuboid(Point(center.x + 22, center.y + 50.5, center.z - 0.5), 15, 5, 1).draw();
	glDisable(GL_BLEND);


	//----------------------------------------------------------------
	/*glColor3ub(155, 155, 155);
	Cuboid(Point(center.x, center.y + 13.5, center.z - 26), 1.5, 14, 20).draw();
	
	glColor3ub(88, 88, 88);
	Cuboid(Point(center.x - 13, center.y + 15, center.z - 23),1.5,20,6).draw();*/
}