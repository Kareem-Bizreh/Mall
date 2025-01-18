#include <GL/glut.h>
#include <bits/stdc++.h>
#include "stb_image.h"
#include "math3d.h"
#include "stairsMall.h"
#include "Texture.h"
#include "Cuboid.h"
#include "SkyBox.h"
#include "FurnitureStore.h"
#include "Pyramid.h"
#include "Camera.h"
#include "Cafe.h"
#include "SuperMarket.h"
#include "ElectronicDepartment.h"
#include "Outside.h"

using namespace std;

struct color3f
{
	float r, g, b;
	color3f() { r = 0; g = 0; b = 0; }
	color3f(float r, float g, float b) { this->r = r; this->g = g; this->b = b; }
};
//==================================================================================================================
// Global variables
Point center = Point(0, -3, 0);
Texture texture;
SkyBox skybox;
Outside outside(texture);
int g_iWidth = 800;
int g_iHeight = 600;
const float g_fNear = 1;
const float g_fFar = 1000000000.0f;
color3f g_background;
GLuint displayListID;

//camera variables
Camera g_camera;
bool g_key[256];	//all keys 2^8
bool g_shift_down = false;
bool g_fps_mode = false;
bool g_mouse_left_down = false;
bool g_mouse_right_down = false;

// Movement settings
const float g_translation_speed = 1.5;
const float g_rotation_speed = M_PI / 180 * 0.1;
const float elevator_speed = 0.7;
const float elevator_door_speed = 0.05;
const float door_speed = 0.06;
const float auto_door_speed = 0.08;

// light settings
GLfloat LightPos[] = { -1.0f, 3.0f, 0.0f, 0.0f };
GLfloat LightAmb[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat LightDiff[] = { 0.6f,0.6f,0.6f,1.0f };

GLfloat LightDir[] = { 0.0f,0.0f,-60.0f,1.0f };
GLfloat LightSpec[] = { 0.2f,0.2f,0.2f,1.0f };


GLfloat MatAmb[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat MatDif[] = { 0.6f,0.6f,0.6f,1.0f };
GLfloat MatSpec[] = { 0.2f,0.2f,0.2f,1.0f };

GLfloat MatShn[] = { 128.0f };
M3DMatrix44f shadowMat;
M3DVector4f vPlaneEquation;

//==================================================================================================================

/***********************
 * Fountain Configuration
 ***********************/
const float DROP_SIZE = 4.0f;
FInitializer initializers[] = {
	FInitializer(4, 30, 30, DROP_SIZE, 75.0f, 90.0f, 0.2f, 0.10f),  // 1
	FInitializer(4, 30, 8, DROP_SIZE, 80.0f, 90.0f, 0.2f, 0.08f),   // 2
	FInitializer(2, 40, 10, DROP_SIZE, 50.0f, 90.0f, 1.5f, 0.13f),  // 3
	FInitializer(3, 5, 100, DROP_SIZE, 75.0f, 90.0f, 0.4f, 0.07f),  // 4
	FInitializer(3, 50, 35, DROP_SIZE, 30.0f, 90.0f, 0.2f, 0.15f),  // 5
	FInitializer(1, 20, 60, DROP_SIZE, 50.0f, 60.0f, 5.0f, 0.13f),  // 6
	FInitializer(6, 20, 30, DROP_SIZE, 90.0f, 90.0f, 1.0f, 0.12f),  // 7
	FInitializer(2, 10, 60, DROP_SIZE, 73.0f, 85.0f, 6.0f, 0.08f)   // 8
};

const float WATER_COLOR[] = { 26.0 / 255.0f, 126 / 255.0f, 227 / 255.0f, 0.5f };
const float TIME_DELTA = 0.1f;

//==================================================================================================================

//definition of all functions

void display();
void reshape(int w, int h);
void init();
void keyboard(unsigned char key, int x, int y);
void keyboardup(unsigned char key, int x, int y);
void mousemotion(int x, int y);
void specialKeys(int key, int x, int y);
void specialKeysUp(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void timer(int value);
void idle();
void menucreate();
void menufunction(int option);

//==================================================================================================================

void setupLighting()
{
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_POSITION, LightPos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec);
	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDir);
	//glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 5.0);

	glEnable(GL_LIGHTING);
	glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MatDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MatSpec);
	glMaterialfv(GL_FRONT, GL_SHININESS, MatShn);
	glEnable(GL_COLOR_MATERIAL);
}

void setupShadow()
{
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_POSITION, LightPos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec);

	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDir);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 5.0);

	glEnable(GL_LIGHTING);

	glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MatDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MatSpec);
	glMaterialfv(GL_FRONT, GL_SHININESS, MatShn);
	glEnable(GL_COLOR_MATERIAL);
	M3DVector3f points[3] = { { -30.0f, -2.0f, -20.0f },{ -30.0f, -2.0f,
		20.0f },
		{ 40.0f, -2.0f, 20.0f } };
	m3dGetPlaneEquation(vPlaneEquation, points[0], points[1],
		points[2]);
	// Calculate projection matrix to draw shadow on the ground
	m3dMakePlanarShadowMatrix(shadowMat, vPlaneEquation,
		LightPos);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(g_iWidth, g_iHeight);
	glutCreateWindow("ALO Mall");
	glutFullScreen();
	init();
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mousemotion);
	glutPassiveMotionFunc(mousemotion);
	glutKeyboardUpFunc(keyboardup);
	glutSpecialFunc(specialKeys);
	glutSpecialUpFunc(specialKeysUp);


	glutTimerFunc(1, timer, 0);
	glutMainLoop();
}

//the entry point to display objects
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(g_background.r, g_background.g, g_background.b, 1.0);
	glLoadIdentity();
	g_camera.Refresh();	//to update the camera position
	glTranslatef(0, 0, -10);

	//setupLighting();
	//setupShadow();
	glColor3ub(80, 80, 80);
	skybox.Draw_Skybox(105, 149.5, - 60, 470, 300, 925);
	glColor3ub(255, 255, 255);
	outside.drawDynamic();
	glCallList(displayListID);
	outside.drawFountain(WATER_COLOR);

	glutSwapBuffers();
}


//key press method. When ESC is pressed (exit) and when space is pressed (camera)
void keyboard(unsigned char key, int x, int y)
{
	if (key == 27)	//esc
	{
		exit(0);
	}
	if (key == ' ') {	//space
		g_fps_mode = !g_fps_mode;

		if (g_fps_mode) {
			glutSetCursor(GLUT_CURSOR_NONE);
			glutWarpPointer(g_iWidth / 2, g_iHeight / 2);
		}
		else {
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		}
	}

	if (glutGetModifiers() == GLUT_ACTIVE_SHIFT) {
		g_shift_down = true;
	}
	else {
		g_shift_down = false;
	}
	if (key == 'f' || key == 'F')
	{
		float x, y, z;
		g_camera.GetPos(x, y, z);
		Point playerPos = Point(x, y, z);
		for (Door* door : outside.Doors) {
			Point doorCenter = door->center;
			double dist = sqrt((playerPos.x - doorCenter.x) * (playerPos.x - doorCenter.x) +
				(playerPos.y - doorCenter.y) * (playerPos.y - doorCenter.y) +
				(playerPos.z - doorCenter.z) * (playerPos.z - doorCenter.z));
			if (dist <= 15)
				door->open = !door->open;
		}
		if (outside.elevator.elevatorDoor->OpenRate >= 1) {
			double dist;
			dist = sqrt((playerPos.x - outside.elevator.elevatorDoorDown->center.x) * (playerPos.x - outside.elevator.elevatorDoorDown->center.x) +
				(playerPos.y - outside.elevator.elevatorDoorDown->center.y) * (playerPos.y - outside.elevator.elevatorDoorDown->center.y) +
				(playerPos.z - outside.elevator.elevatorDoorDown->center.z) * (playerPos.z - outside.elevator.elevatorDoorDown->center.z));
			if (dist <= 15 && outside.elevator.height >= 50) {
				outside.elevator.up = false;
				outside.elevator.elevatorDoor->open = false;
				outside.elevator.elevatorDoorUp->open = false;
			}
			dist = sqrt((playerPos.x - outside.elevator.elevatorDoorUp->center.x) * (playerPos.x - outside.elevator.elevatorDoorUp->center.x) +
				(playerPos.y - outside.elevator.elevatorDoorUp->center.y) * (playerPos.y - outside.elevator.elevatorDoorUp->center.y) +
				(playerPos.z - outside.elevator.elevatorDoorUp->center.z) * (playerPos.z - outside.elevator.elevatorDoorUp->center.z));
			if (dist <= 15 && outside.elevator.height <= 0) {
				outside.elevator.up = true;
				outside.elevator.elevatorDoor->open = false;
				outside.elevator.elevatorDoorDown->open = false;
			}
			dist = sqrt((playerPos.x - outside.elevator.elevatorDoor->center.x) * (playerPos.x - outside.elevator.elevatorDoor->center.x) +
				(playerPos.y - outside.elevator.elevatorDoor->center.y) * (playerPos.y - outside.elevator.elevatorDoor->center.y) +
				(playerPos.z - outside.elevator.elevatorDoor->center.z) * (playerPos.z - outside.elevator.elevatorDoor->center.z));
			if (dist < 10) {
				outside.elevator.up = !outside.elevator.up;
				outside.elevator.elevatorDoor->open = false;
				outside.elevator.elevatorDoorDown->open = false;
				outside.elevator.elevatorDoorUp->open = false;
				outside.elevator.in = true;
			}
		}
	}

	g_key[key] = true;
	if (outside.elevator.in)
	{
		g_key['w'] = false;
		g_key['a'] = false;
		g_key['s'] = false;
		g_key['d'] = false;
	}
}

//camera related function: timer, mouse and mouse motion
void timer(int value)
{
	g_camera.Doors = outside.Doors;
	outside.fountain.update(TIME_DELTA);

	if (g_fps_mode) {

		if (g_key['w']) {
			g_camera.Move(g_translation_speed);
		}
		else if (g_key['s']) {
			g_camera.Move(-g_translation_speed);
		}
		if (g_key['a']) {
			g_camera.Strafe(g_translation_speed);
		}
		else if (g_key['d']) {
			g_camera.Strafe(-g_translation_speed);
		}
		if (g_mouse_left_down) {
			g_camera.Fly(-g_translation_speed);
		}
		else if (g_mouse_right_down) {
			g_camera.Fly(g_translation_speed);
		}
	}

	if (outside.elevator.elevatorDoor->OpenRate <= 0)
	{
		if (!outside.elevator.up)
		{
			if (outside.elevator.height > 0)
			{
				outside.elevator.height -= elevator_speed;
				g_camera.Fly(outside.elevator.in ? -elevator_speed : 0.0);
				outside.elevator_moving.playAudio();
			}
			else if (!outside.elevator.elevatorDoor->open)
			{
				outside.elevator_moving.stopAudio();
				outside.arrival_elevator.playAudio();
				outside.elevator.height = 0;
				outside.elevator.elevatorDoor->open = true;
				outside.elevator.elevatorDoorDown->open = true;

			}
		}
		if (outside.elevator.up)
		{
			if (outside.elevator.height < 50)
			{
				outside.elevator.height += elevator_speed;
				g_camera.Fly(outside.elevator.in ? elevator_speed : 0.0);
				outside.elevator_moving.playAudio();
			}
			else if (!outside.elevator.elevatorDoor->open)
			{
				outside.elevator_moving.stopAudio();
				outside.arrival_elevator.playAudio();
				outside.elevator.height = 50;
				outside.elevator.elevatorDoor->open = true;
				outside.elevator.elevatorDoorUp->open = true;
			}
		}
	}
	for (Door* door : outside.Doors) {
		bool flag = false;
		if (door->open && door->OpenRate < 1)
		{
			door->OpenRate += door_speed;
			outside.open_door.playAudio();
			outside.close_door.stopAudio();
			flag = true;
		}
		if (!door->open && door->OpenRate > 0)
		{
			door->OpenRate -= door_speed;
			outside.close_door.playAudio();
			outside.open_door.stopAudio();
			flag = true;
		}
		door->OpenRate = max((double)0, door->OpenRate);
		door->OpenRate = min((double)1, door->OpenRate);
		if (flag && (door->OpenRate == 0 || door->OpenRate == 1))
		{
			outside.close_door.stopAudio();
			outside.open_door.stopAudio();
		}
	}
	for (Door* door : outside.elevatorDoors) {
		if (door->open && door->OpenRate < 1)
			door->OpenRate += elevator_door_speed;
		if (!door->open && door->OpenRate > 0)
			door->OpenRate -= elevator_door_speed;
		door->OpenRate = max((double)0, door->OpenRate);
		door->OpenRate = min((double)1, door->OpenRate);
	}
	if (outside.elevator.elevatorDoor->OpenRate >= 1)
		outside.elevator.in = false;

	float x, y, z;
	g_camera.GetPos(x, y, z);
	Point playerPos = Point(x, y, z);
	for (Door* door : outside.AutoDoors)
	{
		bool flag = false;
		Point doorCenter = door->center;
		double dist = sqrt((playerPos.x - doorCenter.x) * (playerPos.x - doorCenter.x) +
			(playerPos.y - doorCenter.y) * (playerPos.y - doorCenter.y) +
			(playerPos.z - doorCenter.z) * (playerPos.z - doorCenter.z));
		if (dist <= 20 && door->OpenRate < 1)
		{
			flag = true;
			door->OpenRate += auto_door_speed;
			outside.Auto_door.playAudio();
		}
		if (dist > 20 && door->OpenRate > 0)
		{
			flag = true;
			door->OpenRate -= auto_door_speed;
			outside.Auto_door.playAudio();
		}
		door->OpenRate = max((double)0, door->OpenRate);
		door->OpenRate = min((double)1, door->OpenRate);
		if (flag && (door->OpenRate == 0 || door->OpenRate == 1))
		{
			outside.Auto_door.stopAudio();
		}
	}
	glutTimerFunc(1000 / 30, timer, 0);	//call the timer again each 1 millisecond
}

void specialKeys(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		cout << "up" << endl;
	if (key == GLUT_KEY_DOWN)
		cout << "down" << endl;
	if (key == GLUT_KEY_RIGHT)
		cout << "right" << endl;
	if (key == GLUT_KEY_LEFT)
		cout << "left" << endl;
	g_key[key] = true;
	cout << key << endl;
}

//inactive keys
void keyboardup(unsigned char key, int x, int y)
{
	g_key[key] = false;
}

void specialKeysUp(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
		cout << "up released" << endl;
	if (key == GLUT_KEY_DOWN)
		cout << "down released" << endl;
	if (key == GLUT_KEY_RIGHT)
		cout << "right released" << endl;
	if (key == GLUT_KEY_LEFT)
		cout << "left released" << endl;
	g_key[key] = false;
}

//initialize some variables
void init()
{
	g_background.r = 255;
	g_background.g = 255;
	g_background.b = 255;
	menucreate();

	//load textures here 
	outside.OutsideTextures();
	outside.loadAudios();

	//display list
	displayListID = glGenLists(1);
	glNewList(displayListID, GL_COMPILE);
	outside.drawStatic();
	glEndList();

	//fountain
	outside.fountain.initialize(initializers[0]);
	outside.fountain.center.set(105, 22, -100);

	glClearColor(g_background.r, g_background.g, g_background.b, 1.0);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//function to call when the window is resized
void reshape(int w, int h)
{
	g_iHeight = h;
	g_iWidth = w;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.f, (float)w / (float)h, g_fNear, g_fFar);
	glMatrixMode(GL_MODELVIEW);
}

//call the display function on idle time
void idle()
{
	display();
}

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON) {
			g_mouse_left_down = true;
		}
		else if (button == GLUT_RIGHT_BUTTON) {
			g_mouse_right_down = true;
		}
	}
	else if (state == GLUT_UP) {
		if (button == GLUT_LEFT_BUTTON) {
			g_mouse_left_down = false;
		}
		else if (button == GLUT_RIGHT_BUTTON) {
			g_mouse_right_down = false;
		}
	}
}

void mousemotion(int x, int y)
{
	// This variable is hack to stop glutWarpPointer from triggering an event callback to Mouse(...)
	// This avoids it being called recursively and hanging up the event loop
	static bool just_warped = false;

	if (just_warped) {
		just_warped = false;
		return;
	}

	if (g_fps_mode) {
		int dx = x - g_iWidth / 2;
		int dy = y - g_iHeight / 2;

		if (dx) {
			g_camera.RotateYaw(g_rotation_speed * dx);
		}

		if (dy) {
			g_camera.RotatePitch(-g_rotation_speed * dy);
		}

		glutWarpPointer(g_iWidth / 2, g_iHeight / 2);

		just_warped = true;
	}
}

//is invoke by init function and created the menus options
void menucreate()
{
	int backgroundmenu = glutCreateMenu(menufunction);
	glutAddMenuEntry("Red", 0);
	glutAddMenuEntry("Blue", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Yellow", 3);
	glutAddMenuEntry("Default", 4);

	int mainmenu = glutCreateMenu(menufunction);
	glutAddSubMenu("Color", backgroundmenu);

	glutAddMenuEntry("Light On", 5);
	glutAddMenuEntry("Light Off", 6);
	glutAddMenuEntry("Exit", 7);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//used when click on menu
void menufunction(int option)
{
	if (option == 0)	//red color
	{
		g_background.r = 1;
		g_background.g = 0;
		g_background.b = 0;
	}
	else if (option == 1)	//blue color
	{
		g_background.r = 0;
		g_background.g = 0;
		g_background.b = 1;
	}
	else if (option == 2)	//green color
	{
		g_background.r = 0;
		g_background.g = 1;
		g_background.b = 0;
	}
	else if (option == 3)	//orange color
	{
		g_background.r = 255;
		g_background.g = 153;
		g_background.b = 0;
	}
	else if (option == 4)	//default color (black)
	{
		g_background.r = 0;
		g_background.g = 0;
		g_background.b = 0;
	}
	else if (option == 5)	//light on
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		glEnable(GL_COLOR_MATERIAL);
	}
	else if (option == 6)	//light off
	{
		glDisable(GL_LIGHTING);
	}
	else if (option == 7)	//exit of application
		exit(0);
	glutPostRedisplay();
}
