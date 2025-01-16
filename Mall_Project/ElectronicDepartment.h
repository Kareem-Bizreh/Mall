#pragma once
#include "Texture.h"
#include "Door.h"

class ElectronicDepartment
{
public:
	ElectronicDepartment();
	ElectronicDepartment(float x, float y, float z);
	void drawDynamic();
	void draw();
	void drawDoors(float x,float y,float z, Door* door);
	void loadTextures();
	Door* techDoor = new Door{ Point(55.8, 61.3, -30.9), 0.0, false };
	Door* csDoor = new Door{ Point(55.8, 61.3, -97.9), 0.0, false };
	Door* mobileDoor = new Door{ Point(55.8, 61.3, -164.9), 0.0, false };
	float doorAngle = 120;

Texture 
chip_text1,
chip_text2,
wall_text,
left_door_text,
right_door_text,
ground_text,
logo_text1,
logo_text2,
logo_text3,
wood_text,
money_text,
office_tech_text,
office_cs_text,
office_mobile_text,
// laptops
laptop_screen_text1,
laptop_keyboard_text1,
laptop_back_text1,

laptop_screen_text2,
laptop_keyboard_text2,
laptop_back_text2,

laptop_screen_text3,
laptop_keyboard_text3,
laptop_back_text3,

laptop_screen_text4,
laptop_keyboard_text4,
laptop_back_text4,

laptop_screen_text5,
laptop_keyboard_text5,
laptop_back_text5,

laptop_screen_text6,
laptop_keyboard_text6,
laptop_back_text6,

laptop_screen_text7,
laptop_keyboard_text7,
laptop_back_text7,

laptop_screen_text8,
laptop_keyboard_text8,
laptop_back_text8,
// mouses
mouse_text1,
mouse_text2,
mouse_text3,
mouse_text4,
mouse_text5,
mouse_text6,
// headphones
headphone_text1,
headphone_text2,
headphone_text3,
headphone_text4,
// keyboards
keyboard_text1,
keyboard_text2,
keyboard_text3,
keyboard_text4,
// xbox
xbox_text,
// stanless
stanless_text,
// store sign 1
store_sign_text1,
// store sign 2
store_sign_text2,
// store sign 3
store_sign_text3,
// monitor
monitor_text,
// keyboard
keyboard_text,
// counter strike
cs_text1,
cs_text2,
cs_text3,
cs_text4,
cs_text5,
cs_text6,
cs_text7,
cs_text8,
cs_text9,
cs_text10,
cs_text11,
cs_text12,
cs_text13,
cs_text14,
cs_text15,
cs_text16,
cs_text17,
cs_text18,
cs_text19,
cs_text20,
// phones
mobile_text1,
mobile_text2,
mobile_text3,
mobile_text4,
mobile_text5,
mobile_text6,
mobile_text7,
mobile_text8,
// ipads
ipad_text1,
ipad_text2,
// blutooth speaker
blutooth_speaker_text1,
blutooth_speaker_text2,
// earphones
earphones_text1,
earphones_text2,
earphones_text3,
earphones_text4,
// airpods
airpods_text1,
airpods_text2,
airpods_text3,
// chargers
charger_text1,
charger_text2,
charger_text3,
USP_text;


int 
chipTex1,
chipTex2,
wallTex,
logoTex1,
logoTex2,
logoTex3,
leftDoorTex,
rightDoorTex,
groundTex,
woodTex,
moneyTex,
officeTechTex,
officeCsTex,
officeMobileTex,
// laptops
laptopScreenTex1,
laptopKeyboardTex1,
laptopBackTex1,

laptopScreenTex2,
laptopKeyboardTex2,
laptopBackTex2,

laptopScreenTex3,
laptopKeyboardTex3,
laptopBackTex3,

laptopScreenTex4,
laptopKeyboardTex4,
laptopBackTex4,

laptopScreenTex5,
laptopKeyboardTex5,
laptopBackTex5,

laptopScreenTex6,
laptopKeyboardTex6,
laptopBackTex6,

laptopScreenTex7,
laptopKeyboardTex7,
laptopBackTex7,

laptopScreenTex8,
laptopKeyboardTex8,
laptopBackTex8,
// mouses
mouseTex1,
mouseTex2,
mouseTex3,
mouseTex4,
mouseTex5,
mouseTex6,
// headphones
headphoneTex1,
headphoneTex2,
headphoneTex3,
headphoneTex4,
// keyboards
keyboardTex1,
keyboardTex2,
keyboardTex3,
keyboardTex4,
// xbox
xboxTex,
// stanlessTex
stanslessTex,
// store sign 1
storeSignTex1,
// store sign 2
storeSignTex2,
// store sign 3
storeSignTex3,
// monitor
monitorTex,
// keyboard
keyboardTex,
// counter strike
csTex1,
csTex2,
csTex3,
csTex4,
csTex5,
csTex6,
csTex7,
csTex8,
csTex9,
csTex10,
csTex11,
csTex12,
csTex13,
csTex14,
csTex15,
csTex16,
csTex17,
csTex18,
csTex19,
csTex20,
// phones
mobileTex1,
mobileTex2,
mobileTex3,
mobileTex4,
mobileTex5,
mobileTex6,
mobileTex7,
mobileTex8,
// ipads
ipadTex1,
ipadTex2,
// blutooth speakers
blutoothSpeakerTex1,
blutoothSpeakerTex2,
// earphones
earphonesTex1,
earphonesTex2,
earphonesTex3,
earphonesTex4,
// airpods
airpodsTex1,
airpodsTex2,
airpodsTex3,
// chargers
chargerTex1,
chargerTex2,
chargerTex3,
USPTex;


private:
	float x, y, z;
	void drawStructure(float x, float y, float z, int logo, Door* door);
	void drawTable(float x, float y, float z, float height, float length, float width);
	void drawChair(float x, float y, float z, float angle = 0, float axisX = 0, float axisY = 0, float axisZ = 0);
	void drawOffice(float x, float y, float z, int sticker, float angle = 0, float axisX = 0, float axisY = 0, float axisZ = 0);
	void drawRoof(float x, float y, float z, float height, float length, float width);
	void drawLaptop(float x, float y, float z, int screen_tex, int keyboard_tex, int back_tex, float angle = 0, float axisX = 0, float axisY = 0, float axisZ = 0);
	void drawStoreSign(float x, float y, float z, int tex);
	void drawMonitor(float x, float y, float z, int tex, float angle = 0, float axisX = 0, float axisY = 0, float axisZ = 0);
	void drawCabinet(float x, float y, float z);
	void drawProduct(float x, float y, float z, float height, float length, float width, int tex, float angle = 0, float axisX = 0, float axisY = 0, float axisZ = 0);
};
