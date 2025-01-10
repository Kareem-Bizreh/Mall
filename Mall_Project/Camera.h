#ifndef __CAMERA_H__
#define __CAMERA_H__
#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#include <bits/stdc++.h>
#include "Point.h"
struct Wall {
	Point min;//النقطة السفلية اليسرى الأمامية 
	Point max;//النقطة العلوية اليمنى الخلفية 
};

class Camera
{
public:
	Camera() { Init(); }
	~Camera() {}

	void Init();
	void Refresh();
	void SetPos(float x, float y, float z);
	void GetPos(float& x, float& y, float& z);
	void GetDirectionVector(float& x, float& y, float& z);
	void SetYaw(float angle);
	void SetPitch(float angle);
	bool CheckCollision(const Point& newPos);
	// Navigation
	void Move(float incr);
	void Strafe(float incr);
	void Fly(float incr);
	void RotateYaw(float angle);
	void RotatePitch(float angle);

	std::vector<Wall> walls = {
		{Point(150.353,84.2594,-216.69),Point(155.638,110.174,-184.188)},// الحيط الامامي يلي فوق الباب 
	    {Point(149.029,65.9284,-182.904),Point(156.2,109.611,-17.225)},// الحيط الامامي لمحل المفروشات
	    {Point(154,60.9386,-215.393),Point(201.98,63.7939,-17.4412)},// ارضية محل المفروشات 
		{Point(154.081,63.9234,-218.526),Point(202.393,109.872,-214.429)}, // الحيط الجانبي اليساري لمحل المفروشات 
		{Point(153.39, 64.1179, -20.0), Point(200.839, 110.67, -15.0)},//الحيط الجانبي اليميني لمحل المفروشات 
		{Point(201.115,66.159,-214.392),Point(213.045,111.7,-17.4738)},// الحيط الحلفي لمحل المفروشات
		{Point(157.294,109.818,-214.427),Point(213.825,113.99,-19.2851)},// الحيط العلوي لمحل المفروشات 
	};

private:
	float m_x, m_y, m_z;   // Position
	float m_lx, m_ly, m_lz; // Direction vector of where we are looking at
	float m_yaw, m_pitch; // Various rotation angles
	float m_strafe_lx, m_strafe_lz; // Always 90 degree to direction vector
};

#endif
