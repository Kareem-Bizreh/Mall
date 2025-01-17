#include "Camera.h"
#include <bits/stdc++.h>
#include "GL/glut.h"
#include "Point.h"
#include "Camera.h"

//init values
void Camera::Init()
{
	m_yaw = 0.0;
	m_pitch = 0.0;
	SetPos(-5, 4, 12);	//to start over the floor
}

//invoke each time in the draw function
void Camera::Refresh()
{
	// Camera parameter according to Riegl's co-ordinate system
	// x/y for flat, z for height
	m_lx = cos(m_yaw) * cos(m_pitch);
	m_ly = sin(m_pitch);
	m_lz = sin(m_yaw) * cos(m_pitch);

	m_strafe_lx = cos(m_yaw - M_PI_2);
	m_strafe_lz = sin(m_yaw - M_PI_2);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(m_x, m_y, m_z, m_x + m_lx, m_y + m_ly, m_z + m_lz, 0.0, 1.0, 0.0);

	//printf("Camera: %f %f %f Direction vector: %f %f %f\n", m_x, m_y, m_z, m_lx, m_ly, m_lz);
}

bool Camera::CheckCollision(const Point& newPos) {
	for (const auto& wall : walls) {
		if (newPos.x > wall.min.x && newPos.x < wall.max.x &&
			newPos.y > wall.min.y && newPos.y < wall.max.y &&
			newPos.z > wall.min.z && newPos.z < wall.max.z) {
			return true; // تصادم مع جدار
		}
	}
	return false; // لا يوجد تصادم
}
bool Camera::CheckDoorCollision(const Point& newPos) {
	if (newPos.x > doorWalls[0].min.x && newPos.x < doorWalls[0].max.x &&
		newPos.y > doorWalls[0].min.y && newPos.y < doorWalls[0].max.y &&
		newPos.z > doorWalls[0].min.z && newPos.z < doorWalls[0].max.z && !Doors[0]->open) {
		return true; // تصادم مع جدار
	}
	if (newPos.x > doorWalls[1].min.x && newPos.x < doorWalls[1].max.x &&
		newPos.y > doorWalls[1].min.y && newPos.y < doorWalls[1].max.y &&
		newPos.z > doorWalls[1].min.z && newPos.z < doorWalls[1].max.z && !Doors[1]->open) {
		return true; // تصادم مع جدار
	}
	if (newPos.x > doorWalls[2].min.x && newPos.x < doorWalls[2].max.x &&
		newPos.y > doorWalls[2].min.y && newPos.y < doorWalls[2].max.y &&
		newPos.z > doorWalls[2].min.z && newPos.z < doorWalls[2].max.z && !Doors[2]->open) {
		return true; // تصادم مع جدار
	}
	if (newPos.x > doorWalls[3].min.x && newPos.x < doorWalls[3].max.x &&
		newPos.y > doorWalls[3].min.y && newPos.y < doorWalls[3].max.y &&
		newPos.z > doorWalls[3].min.z && newPos.z < doorWalls[3].max.z && !ElevetorDoors[1]->open) {
		return true; // تصادم مع جدار
	}
	if (newPos.x > doorWalls[4].min.x && newPos.x < doorWalls[4].max.x &&
		newPos.y > doorWalls[4].min.y && newPos.y < doorWalls[4].max.y &&
		newPos.z > doorWalls[4].min.z && newPos.z < doorWalls[4].max.z && !ElevetorDoors[2]->open) {
		return true; // تصادم مع جدار
	}
	if (newPos.x > doorWalls[5].min.x && newPos.x < doorWalls[5].max.x &&
		newPos.y > doorWalls[5].min.y && newPos.y < doorWalls[5].max.y &&
		newPos.z > doorWalls[5].min.z && newPos.z < doorWalls[5].max.z && !Doors[9]->open) {
		return true; // تصادم مع جدار
	}
	if (newPos.x > doorWalls[6].min.x && newPos.x < doorWalls[6].max.x &&
		newPos.y > doorWalls[6].min.y && newPos.y < doorWalls[6].max.y &&
		newPos.z > doorWalls[6].min.z && newPos.z < doorWalls[6].max.z && !Doors[8]->open) {
		return true; // تصادم مع جدار
	}
	if (newPos.x > doorWalls[7].min.x && newPos.x < doorWalls[7].max.x &&
		newPos.y > doorWalls[7].min.y && newPos.y < doorWalls[7].max.y &&
		newPos.z > doorWalls[7].min.z && newPos.z < doorWalls[7].max.z && !Doors[7]->open) {
		return true; // تصادم مع جدار
	}
	return false; // لا يوجد اصطدام
}
//to place a position of the camera
void Camera::SetPos(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;

	Refresh();
}

//to obtain the position of camera (for debugging)
void Camera::GetPos(float& x, float& y, float& z)
{
	x = m_x;
	y = m_y;
	z = m_z;
}

//to obtain the direction of camera (for debugging)
void Camera::GetDirectionVector(float& x, float& y, float& z)
{
	x = m_lx;
	y = m_ly;
	z = m_lz;
}

//move the camera position
void Camera::Move(float incr) {
	float lx = cos(m_yaw) * cos(m_pitch);
	float ly = sin(m_pitch);
	float lz = sin(m_yaw) * cos(m_pitch);

	Point newPos(m_x + incr * lx, m_y + incr * ly, m_z + incr * lz);

	// التحقق من الاصطدام مع الجدران والأبواب
	if (!CheckCollision(newPos) && !CheckDoorCollision(newPos)) {
		m_x = newPos.x;
		m_y = newPos.y;
		m_z = newPos.z;
	}
	//std::cout << "x = " << m_x << " " << " y = " << m_y << " " << " z = " << m_z << std::endl;
	Refresh();
}

void Camera::Strafe(float incr) {
	float newX = m_x + incr * m_strafe_lx;
	float newZ = m_z + incr * m_strafe_lz;

	Point newPos(newX, m_y, newZ);

	// التحقق من الاصطدام مع الجدران والأبواب
	if (!CheckCollision(newPos) && !CheckDoorCollision(newPos)) {
		m_x = newX;
		m_z = newZ;
	}

	//std::cout << "x = " << m_x << " " << " y = " << m_y << " " << " z = " << m_z << std::endl;


	Refresh();
}

void Camera::Fly(float incr) {
	Point newPos(m_x, m_y + incr, m_z);

	// التحقق من الاصطدام مع الجدران والأبواب
	if (!CheckCollision(newPos) && !CheckDoorCollision(newPos)) {
		m_y = newPos.y;
	}

	Refresh();
}

//pitch, yaw, roll functions

void Camera::RotateYaw(float angle)
{
	m_yaw += angle;

	Refresh();
}

void Camera::RotatePitch(float angle)
{
	const float limit = 89.0 * M_PI / 180.0;

	m_pitch += angle;

	if (m_pitch < -limit)
		m_pitch = -limit;

	if (m_pitch > limit)
		m_pitch = limit;

	Refresh();
}

void Camera::SetYaw(float angle)
{
	m_yaw = angle;

	Refresh();
}

void Camera::SetPitch(float angle)
{
	m_pitch = angle;

	Refresh();
}
