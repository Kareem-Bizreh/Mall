#include<gl/glut.h>
#include "Texture.h"
#pragma once
class SkyBox
{
public :
	GLuint SKYFRONT, SKYBACK, SKYLEFT, SKYRIGHT, SKYUP, SKYDOWN;

	void Draw_Skybox(float x, float y, float z, float width, float height, float length);
};

