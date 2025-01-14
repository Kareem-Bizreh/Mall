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
		{Point(152.85,10.7308,-198.408),Point(155.024,59.6898,-33.1319)},//الحيط الامامي يلي بين القهوة والمطعم
		{Point(152.339,11.6413,-226.996),Point(202.545,58.951,-214.098)},//الحيط اليساري للمطعم
		{Point(152.339,11.6413,-226.996),Point(213.292,107.733,-212.523)},//الحيط اليساري للمطعم
		{Point(202.712,11.2172,-214.531),Point(206.958,59.8031,-15.9319)},//الحيط الخلفي للقهوة والمطعم
		{Point(155.447,10.9828,-127.671),Point(202.486,58.91,-98.9376)},//الحيط الجانبي يلي بين القهوة والمطعم
		{Point(178.986,11.1494,-186.543),Point(202.597,21.7033,-168.764)},//الطاولة التانية يلي بالمطعم
		{Point(177.485,11.8957,-211.941),Point(202.304,27.085,-194.964)},//الطاولة الأولى يلي بالمطعم
		{Point(152.288,60.7939,-214.158),Point(204.297,61.5689,-115.8)},//السقف تبع المطعم
		{Point(154.241,8.84553,-215.287),Point(202.567,11.5747,-127.998)},//الأرضية تبع المطعم 
		{Point(156.083,9.3674,-98.3077),Point(201.592,11.7341,-18.1637)},//الأرضية تبع القهوة
		{Point(128.231,14.0543,-18.6829),Point(204.015,112.668,-8.2248)},//الحيط اليساري للقهوة مع الحيط اليميني للمول 
		{Point(151.766,35.8452,-32.5091),Point(155.04,59.2969,-16.4593)},//الحيط يلي فوق باب القهوة
		{Point(151.011,34.8764,-215.352),Point(156.176,59.3207,-196.408)},//الحيط يلي فوق باب المطعم
		{Point(155.064,10.6455,-158.305),Point(191.547,25.6861,-147.865)},//الحيط يلي جوا المطعم
		{Point(172.641,12.0636,-80.9752),Point(182.166,27.7222,-52.5672)},//الطاولة يلي بالقهوة جنب البراد
		{Point(155.088,11.3802,-53.96),Point(176.061,25.9976,-48.1549)},//الطاولة يلي بالقهوة جنب البراد
		{Point(155.026,13.2252,-73.2753),Point(163.99,36.9216,-50.8852)},//البراد يلي بالقهوة 
		{Point(173.789,11.9664,-24.5818),Point(202.478,30.2351,-19.0607)},//الطاولات الجانبية يلي بالقهوة
		{Point(186.888,11.8883,-87.5818),Point(202.478,30.2351,-19.0607)},//الطاولات الجانبية يلي بالقهوة
		{Point(155.121,11.3071,-99.0372),Point(184.842,26.5823,-85.2615)},//الطاولات الجانبية يلي بالقهوة 

		// Electronic Department
		// front wall
		{Point(55, 61.3, -215),Point(59, 112, -168)},// right of the right door
		{Point(55, 82, -168),Point(59, 112, -158)},// above of the right door
		{Point(55, 61.3, -158),Point(59, 112, -102)},// between the right door and the middle door
		{Point(55, 82, -102),Point(59, 112, -92)},// above of the middle door
		{Point(55, 61.3, -92),Point(59, 112, -36)},// between the left door and the middle door
		{Point(55, 82, -36),Point(59, 112, -26)},// above of the middle door
		{Point(55, 61.3, -26),Point(59, 112, -14)},// left of the left door

		// right wall
		{Point(0, 61.3, -218),Point(51.5, 112, -214)},

		// tech store
		{Point(40, 53, -70),Point(59, 88, -45)},	// office
		{Point(15, 60, -69),Point(33, 80, -31)},	// laptops table

		// counter strike		
		{Point(45, 61.3, -150),Point(59, 80, -106)},// right table
		{Point(3, 61.3, -150),Point(16, 80, -106)}, // left table
		{Point(22, 61.3, -150),Point(39, 80, -106)},// middle table
		{Point(3, 61.3, -100),Point(30, 88, -80)},  // office

		// mobile store
		{Point(3, 61.3, -167),Point(30, 88, -147)},  // office
		{Point(3, 61.3, -208),Point(18, 85, -175)},  // cabinet
	};

private:
	float m_x, m_y, m_z;   // Position
	float m_lx, m_ly, m_lz; // Direction vector of where we are looking at
	float m_yaw, m_pitch; // Various rotation angles
	float m_strafe_lx, m_strafe_lz; // Always 90 degree to direction vector
};

#endif
