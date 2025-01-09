#include <GL/glut.h>
#include <bits/stdc++.h>
#include "stb_image.h"
#include "math3d.h"
#include "stairsMall.h"
#include "Texture.h"
#include "Cuboid.h"
#include "FurnitureStore.h"
#include "Pyramid.h"
#include "Camera.h"
#include "Cafe.h"
#include "SuperMarket.h"
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
Cafe cafe = Cafe(center);
FurnitureStore furnitureStore;
Texture texture;
Outside outside(texture);
GLUquadric* quadric = gluNewQuadric();
int g_iWidth = 800;
int g_iHeight = 600;
const float g_fNear = 1;
const float g_fFar = 1000000000.0f;
color3f g_background;

//camera variables
Camera g_camera;
bool g_key[256];	//all keys 2^8
bool g_shift_down = false;
bool g_fps_mode = false;
bool g_mouse_left_down = false;
bool g_mouse_right_down = false;

// Movement settings
const float g_translation_speed = 2.5;
const float g_rotation_speed = M_PI / 180 * 0.1;

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
	glutCreateWindow("study");
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
	//outside.draw();
	//cafe.draw();
	outside.draw();
	

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
				door->state = !door->state;
		}
	}

	g_key[key] = true;
}

//camera related function: timer, mouse and mouse motion
void timer(int value)
{
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

	for (Door* door : outside.Doors) {
		if (door->state && door->OpenRate < 1)
			door->OpenRate += 0.04;
		if (!door->state && door->OpenRate > 0)
			door->OpenRate -= 0.04;
	}

	glutTimerFunc(1, timer, 0);	//call the timer again each 1 millisecond
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
	cafe.cafeTextures();
	//furnitureStore.loadTextures();
	//outside.OutsideTextures();
	outside.OutsideTextures();

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