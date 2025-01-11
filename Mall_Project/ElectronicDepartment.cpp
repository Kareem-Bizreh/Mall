#include <GL/glut.h>    
#include "ElectronicDepartment.h"
#include "Texture.h"
#include "Cylinder.h"

void ElectronicDepartment::loadTextures() {
    // chip1
    chip_text1.loadTexture("textures/Electronic Department/textures/chip1.jpg");
    chipTex1 = chip_text1.textureID;

    // chip2
    chip_text2.loadTexture("textures/Electronic Department/textures/chip2.jpg");
    chipTex2 = chip_text2.textureID;

    // wall
    wall_text.loadTexture("textures/Electronic Department/textures/wall.jpg");
    wallTex = wall_text.textureID;

    // left door
    left_door_text.loadTexture("textures/Electronic Department/textures/left door.png");
    leftDoorTex = left_door_text.textureID;

    // right door
    right_door_text.loadTexture("textures/Electronic Department/textures/right door.png");
    rightDoorTex = right_door_text.textureID;

    // logo 1
    logo_text1.loadTexture("textures/Electronic Department/signs and logos/wall with logo1.png");
    logoTex1 = logo_text1.textureID;

    // logo 2
    logo_text2.loadTexture("textures/Electronic Department/signs and logos/wall with logo2.png");
    logoTex2 = logo_text2.textureID;

    // logo 3
    logo_text3.loadTexture("textures/Electronic Department/signs and logos/wall with logo3.png");
    logoTex3 = logo_text3.textureID;

    // ground
    ground_text.loadTexture("textures/Electronic Department/textures/carpet.jpg");
    groundTex = ground_text.textureID;

    // wood
    wood_text.loadTexture("textures/Electronic Department/textures/wood.jpg");
    woodTex = wood_text.textureID;

    // money
    money_text.loadTexture("textures/Electronic Department/textures/money.png");
    moneyTex = money_text.textureID;

    // stanless
    stanless_text.loadTexture("textures/Electronic Department/textures/stanless.png");
    stanslessTex = stanless_text.textureID;

    // office tech
    office_tech_text.loadTexture("textures/Electronic Department/signs and logos/office tech.png");
    officeTechTex = office_tech_text.textureID;

    // office cs
    office_cs_text.loadTexture("textures/Electronic Department/signs and logos/office cs.png");
    officeCsTex = office_cs_text.textureID;

    // office mobile
    office_mobile_text.loadTexture("textures/Electronic Department/signs and logos/office mobile.png");
    officeMobileTex = office_mobile_text.textureID;

    // tech store sign
    store_sign_text1.loadTexture("textures/Electronic Department/signs and logos/store sign1.png");
    storeSignTex1 = store_sign_text1.textureID;

    // cs store sign
    store_sign_text2.loadTexture("textures/Electronic Department/signs and logos/store sign2.png");
    storeSignTex2 = store_sign_text2.textureID;

    // mobile store sign
    store_sign_text3.loadTexture("textures/Electronic Department/signs and logos/store sign3.png");
    storeSignTex3 = store_sign_text3.textureID;

    // laptops
    laptop_screen_text1.loadTexture("textures/Electronic Department/laptop screens/laptop_screen1.png");
    laptopScreenTex1 = laptop_screen_text1.textureID;
    laptop_keyboard_text1.loadTexture("textures/Electronic Department/laptop keyboards/laptop_keyboard1.png");
    laptopKeyboardTex1 = laptop_keyboard_text1.textureID;
    laptop_back_text1.loadTexture("textures/Electronic Department/laptop backs/laptop_back1.png");
    laptopBackTex1 = laptop_back_text1.textureID;

    laptop_screen_text2.loadTexture("textures/Electronic Department/laptop screens/laptop_screen2.png");
    laptopScreenTex2 = laptop_screen_text2.textureID;
    laptop_keyboard_text2.loadTexture("textures/Electronic Department/laptop keyboards/laptop_keyboard2.png");
    laptopKeyboardTex2 = laptop_keyboard_text2.textureID;
    laptop_back_text2.loadTexture("textures/Electronic Department/laptop backs/laptop_back2.png");
    laptopBackTex2 = laptop_back_text2.textureID;

    laptop_screen_text3.loadTexture("textures/Electronic Department/laptop screens/laptop_screen3.png");
    laptopScreenTex3 = laptop_screen_text3.textureID;
    laptop_keyboard_text3.loadTexture("textures/Electronic Department/laptop keyboards/laptop_keyboard3.png");
    laptopKeyboardTex3 = laptop_keyboard_text3.textureID;
    laptop_back_text3.loadTexture("textures/Electronic Department/laptop backs/laptop_back3.png");
    laptopBackTex3 = laptop_back_text3.textureID;

    laptop_screen_text4.loadTexture("textures/Electronic Department/laptop screens/laptop_screen4.png");
    laptopScreenTex4 = laptop_screen_text4.textureID;
    laptop_keyboard_text4.loadTexture("textures/Electronic Department/laptop keyboards/laptop_keyboard4.png");
    laptopKeyboardTex4 = laptop_keyboard_text4.textureID;
    laptop_back_text4.loadTexture("textures/Electronic Department/laptop backs/laptop_back4.png");
    laptopBackTex4 = laptop_back_text4.textureID;

    laptop_screen_text5.loadTexture("textures/Electronic Department/laptop screens/laptop_screen5.png");
    laptopScreenTex5 = laptop_screen_text5.textureID;
    laptop_keyboard_text5.loadTexture("textures/Electronic Department/laptop keyboards/laptop_keyboard5.png");
    laptopKeyboardTex5 = laptop_keyboard_text5.textureID;
    laptop_back_text5.loadTexture("textures/Electronic Department/laptop backs/laptop_back5.png");
    laptopBackTex5 = laptop_back_text5.textureID;

    laptop_screen_text6.loadTexture("textures/Electronic Department/laptop screens/laptop_screen6.png");
    laptopScreenTex6 = laptop_screen_text6.textureID;
    laptop_keyboard_text6.loadTexture("textures/Electronic Department/laptop keyboards/laptop_keyboard6.png");
    laptopKeyboardTex6 = laptop_keyboard_text6.textureID;
    laptop_back_text6.loadTexture("textures/Electronic Department/laptop backs/laptop_back6.png");
    laptopBackTex6 = laptop_back_text6.textureID;

    laptop_screen_text7.loadTexture("textures/Electronic Department/laptop screens/laptop_screen7.png");
    laptopScreenTex7 = laptop_screen_text7.textureID;
    laptop_keyboard_text7.loadTexture("textures/Electronic Department/laptop keyboards/laptop_keyboard7.png");
    laptopKeyboardTex7 = laptop_keyboard_text7.textureID;
    laptop_back_text7.loadTexture("textures/Electronic Department/laptop backs/laptop_back7.png");
    laptopBackTex7 = laptop_back_text7.textureID;

    laptop_screen_text8.loadTexture("textures/Electronic Department/laptop screens/laptop_screen8.png");
    laptopScreenTex8 = laptop_screen_text8.textureID;
    laptop_keyboard_text8.loadTexture("textures/Electronic Department/laptop keyboards/laptop_keyboard2.png");
    laptopKeyboardTex8 = laptop_keyboard_text8.textureID;
    laptop_back_text8.loadTexture("textures/Electronic Department/laptop backs/laptop_back8.png");
    laptopBackTex8 = laptop_back_text8.textureID;

    // mouses
    mouse_text1.loadTexture("textures/Electronic Department/products/mouse1.png");
    mouseTex1 = mouse_text1.textureID;

    mouse_text2.loadTexture("textures/Electronic Department/products/mouse2.png");
    mouseTex2 = mouse_text2.textureID;

    mouse_text3.loadTexture("textures/Electronic Department/products/mouse3.png");
    mouseTex3 = mouse_text3.textureID;

    mouse_text4.loadTexture("textures/Electronic Department/products/mouse4.png");
    mouseTex4 = mouse_text4.textureID;

    mouse_text5.loadTexture("textures/Electronic Department/products/mouse5.png");
    mouseTex5 = mouse_text5.textureID;

    mouse_text6.loadTexture("textures/Electronic Department/products/mouse6.png");
    mouseTex6 = mouse_text6.textureID;

    // headphones
    headphone_text1.loadTexture("textures/Electronic Department/products/headphone1.png");
    headphoneTex1 = headphone_text1.textureID;

    headphone_text2.loadTexture("textures/Electronic Department/products/headphone2.png");
    headphoneTex2 = headphone_text2.textureID;

    headphone_text3.loadTexture("textures/Electronic Department/products/headphone3.png");
    headphoneTex3 = headphone_text3.textureID;

    headphone_text4.loadTexture("textures/Electronic Department/products/headphone4.png");
    headphoneTex4 = headphone_text4.textureID;

    // keyboards
    keyboard_text1.loadTexture("textures/Electronic Department/products/keyboard1.png");
    keyboardTex1 = keyboard_text1.textureID;

    keyboard_text2.loadTexture("textures/Electronic Department/products/keyboard2.png");
    keyboardTex2 = keyboard_text2.textureID;

    keyboard_text3.loadTexture("textures/Electronic Department/products/keyboard3.png");
    keyboardTex3 = keyboard_text3.textureID;

    keyboard_text4.loadTexture("textures/Electronic Department/products/keyboard4.png");
    keyboardTex4 = keyboard_text4.textureID;

    // xbox
    xbox_text.loadTexture("textures/Electronic Department/products/xbox.png");
    xboxTex = xbox_text.textureID;

    // monitor
    monitor_text.loadTexture("textures/Electronic Department/computer/monitor.png");
    monitorTex = monitor_text.textureID;

    // keyboard 
    keyboard_text.loadTexture("textures/Electronic Department/computer/keyboard.png");
    keyboardTex = keyboard_text.textureID;

    // counter strike
    cs_text1.loadTexture("textures/Electronic Department/cs/cs1.png");
    csTex1 = cs_text1.textureID;

    cs_text2.loadTexture("textures/Electronic Department/cs/cs2.png");
    csTex2 = cs_text2.textureID;

    cs_text3.loadTexture("textures/Electronic Department/cs/cs3.png");
    csTex3 = cs_text3.textureID;

    cs_text4.loadTexture("textures/Electronic Department/cs/cs4.png");
    csTex4 = cs_text4.textureID;

    cs_text5.loadTexture("textures/Electronic Department/cs/cs5.png");
    csTex5 = cs_text5.textureID;

    cs_text6.loadTexture("textures/Electronic Department/cs/cs6.png");
    csTex6 = cs_text6.textureID;

    cs_text7.loadTexture("textures/Electronic Department/cs/cs7.png");
    csTex7 = cs_text7.textureID;

    cs_text8.loadTexture("textures/Electronic Department/cs/cs8.png");
    csTex8 = cs_text8.textureID;

    cs_text9.loadTexture("textures/Electronic Department/cs/cs9.png");
    csTex9 = cs_text9.textureID;

    cs_text10.loadTexture("textures/Electronic Department/cs/cs10.png");
    csTex10 = cs_text10.textureID;

    cs_text11.loadTexture("textures/Electronic Department/cs/cs11.png");
    csTex11 = cs_text11.textureID;

    cs_text12.loadTexture("textures/Electronic Department/cs/cs12.png");
    csTex12 = cs_text12.textureID;

    cs_text13.loadTexture("textures/Electronic Department/cs/cs13.png");
    csTex13 = cs_text13.textureID;

    cs_text14.loadTexture("textures/Electronic Department/cs/cs14.png");
    csTex14 = cs_text14.textureID;

    cs_text15.loadTexture("textures/Electronic Department/cs/cs15.png");
    csTex15 = cs_text15.textureID;

    cs_text16.loadTexture("textures/Electronic Department/cs/cs16.png");
    csTex16 = cs_text16.textureID;

    cs_text17.loadTexture("textures/Electronic Department/cs/cs17.png");
    csTex17 = cs_text17.textureID;

    cs_text18.loadTexture("textures/Electronic Department/cs/cs18.png");
    csTex18 = cs_text18.textureID;

    cs_text19.loadTexture("textures/Electronic Department/cs/cs19.png");
    csTex19 = cs_text19.textureID;

    cs_text20.loadTexture("textures/Electronic Department/cs/cs20.png");
    csTex20 = cs_text20.textureID;

    // mobiles
    mobile_text1.loadTexture("textures/Electronic Department/mobiles/mobile1.png");
    mobileTex1 = mobile_text1.textureID;

    mobile_text2.loadTexture("textures/Electronic Department/mobiles/mobile2.png");
    mobileTex2 = mobile_text2.textureID;

    mobile_text3.loadTexture("textures/Electronic Department/mobiles/mobile3.png");
    mobileTex3 = mobile_text3.textureID;

    mobile_text4.loadTexture("textures/Electronic Department/mobiles/mobile4.png");
    mobileTex4 = mobile_text4.textureID;

    mobile_text5.loadTexture("textures/Electronic Department/mobiles/mobile5.png");
    mobileTex5 = mobile_text5.textureID;

    mobile_text6.loadTexture("textures/Electronic Department/mobiles/mobile6.png");
    mobileTex6 = mobile_text6.textureID;

    mobile_text7.loadTexture("textures/Electronic Department/mobiles/mobile7.png");
    mobileTex7 = mobile_text7.textureID;

    mobile_text8.loadTexture("textures/Electronic Department/mobiles/mobile8.png");
    mobileTex8 = mobile_text8.textureID;

    // ipads
    ipad_text1.loadTexture("textures/Electronic Department/mobiles/ipad1.png");
    ipadTex1 = ipad_text1.textureID;

    ipad_text2.loadTexture("textures/Electronic Department/mobiles/ipad2.png");
    ipadTex2 = ipad_text2.textureID;

    // blutooth speakers
    blutooth_speaker_text1.loadTexture("textures/Electronic Department/products/blutooth speaker1.png");
    blutoothSpeakerTex1 = blutooth_speaker_text1.textureID;

    blutooth_speaker_text2.loadTexture("textures/Electronic Department/products/blutooth speaker2.png");
    blutoothSpeakerTex2 = blutooth_speaker_text2.textureID;

    // earphones
    earphones_text1.loadTexture("textures/Electronic Department/products/wired earphones1.png");
    earphonesTex1 = earphones_text1.textureID;

    earphones_text2.loadTexture("textures/Electronic Department/products/wired earphones2.png");
    earphonesTex2 = earphones_text2.textureID;

    earphones_text3.loadTexture("textures/Electronic Department/products/wired earphones3.png");
    earphonesTex3 = earphones_text3.textureID;

    earphones_text4.loadTexture("textures/Electronic Department/products/wired earphones4.png");
    earphonesTex4 = earphones_text4.textureID;

    // airpods
    airpods_text1.loadTexture("textures/Electronic Department/products/airpods1.png");
    airpodsTex1 = airpods_text1.textureID;

    airpods_text2.loadTexture("textures/Electronic Department/products/airpods2.png");
    airpodsTex2 = airpods_text2.textureID;

    airpods_text3.loadTexture("textures/Electronic Department/products/airpods3.png");
    airpodsTex3 = airpods_text3.textureID;

    // chargers
    charger_text1.loadTexture("textures/Electronic Department/products/charger1.png");
    chargerTex1 = charger_text1.textureID;

    charger_text2.loadTexture("textures/Electronic Department/products/charger2.png");
    chargerTex2 = charger_text2.textureID;

    charger_text3.loadTexture("textures/Electronic Department/products/charger3.png");
    chargerTex3 = charger_text3.textureID;

    USP_text.loadTexture("textures/Electronic Department/products/USP.png");
    USPTex = USP_text.textureID;
}


void ElectronicDepartment::draw(float x, float y, float z)
{
    // COMPUTER STORE-------COMPUTER STORE-------COMPUTER STORE-------COMPUTER STORE

    glPushMatrix();
    glTranslated(x - 68, y, z);


    // wall
    drawStructure(x, y, z, logoTex1);


    // store sign
    drawStoreSign(x, y + 37, z + 26, storeSignTex1);


    // table
    drawTable(x, y, z - 7, 10, 15, 35);


    // chair
    drawChair(x + 17, y, z + 15);


    // office
    drawOffice(x, y, z + 15, officeTechTex);


    // monitor
    drawMonitor(x + 3, y + 12, z + 15, monitorTex, 90, 0, 1, 0);


    // front roofs
    drawRoof(x + 24, y + 25, z - 23.5, 1, 3, 10);
    drawRoof(x + 12, y + 30, z - 23.5, 1, 3, 10);
    drawRoof(x, y + 25, z - 23.5, 1, 3, 10);
    drawRoof(x - 12, y + 30, z - 23.5, 1, 3, 10);
    drawRoof(x - 24, y + 25, z - 23.5, 1, 3, 10);


    // right roofs
    drawRoof(x + 31, y + 30, z + 12, 1, 20, 4);
    drawRoof(x + 31, y + 26, z - 10, 1, 20, 4);


    // left roofs
    drawRoof(x - 31.5, y + 19, z + 1.5, 1, 12, 3);    // bottom
    drawRoof(x - 31.5, y + 25, z - 1.5, 1, 12, 3);    // top
    drawRoof(x - 31.5, y + 16.5, z + 4, 11, 1, 3);    // left
    drawRoof(x - 31.5, y + 18, z - 4, 11, 1, 3);      // right


    // front laptops
    drawLaptop(x - 13, y + 11, z - 3, laptopScreenTex1, laptopKeyboardTex1, laptopBackTex1);
    drawLaptop(x - 5, y + 11, z - 3, laptopScreenTex2, laptopKeyboardTex2, laptopBackTex2);
    drawLaptop(x + 3, y + 11, z - 3, laptopScreenTex3, laptopKeyboardTex3, laptopBackTex3);
    drawLaptop(x + 11, y + 11, z - 3, laptopScreenTex4, laptopKeyboardTex4, laptopBackTex4);


    // back laptops
    drawLaptop(x - 13, y + 11, z - 11, laptopScreenTex5, laptopKeyboardTex5, laptopBackTex5, 180, 0, 1, 0);
    drawLaptop(x - 5, y + 11, z - 11, laptopScreenTex6, laptopKeyboardTex6, laptopBackTex6, 180, 0, 1, 0);
    drawLaptop(x + 3, y + 11, z - 11, laptopScreenTex7, laptopKeyboardTex7, laptopBackTex7, 180, 0, 1, 0);
    drawLaptop(x + 11, y + 11, z - 11, laptopScreenTex8, laptopKeyboardTex8, laptopBackTex8, 180, 0, 1, 0);

    // mouses
    drawProduct(x - 22, y + 26, z - 23, 3, 1, 1.8, mouseTex1);
    drawProduct(x - 26, y + 26, z - 23, 3, 1, 1.8, mouseTex2);
    drawProduct(x - 2, y + 26, z - 23, 3, 1, 1.8, mouseTex3);
    drawProduct(x + 2, y + 26, z - 23, 3, 1, 1.8, mouseTex4);
    drawProduct(x + 22, y + 26, z - 23, 3, 1, 1.8, mouseTex5);
    drawProduct(x + 26, y + 26, z - 23, 3, 1, 1.8, mouseTex6);


    // headphones
    drawProduct(x + 9.5, y + 31, z - 23.5, 4, 1.8, 4, headphoneTex1);
    drawProduct(x + 14.5, y + 31, z - 23.5, 4, 1.8, 4, headphoneTex2);
    drawProduct(x - 9.5, y + 31, z - 23.5, 4, 1.8, 4, headphoneTex3);
    drawProduct(x - 14.5, y + 31, z - 23.5, 4, 1.8, 4, headphoneTex4);


    // keyboards
    drawProduct(x + 31, y + 27.2, z - 5, 3, 8, 1, keyboardTex1, 26, 0, 0, -1);
    drawProduct(x + 31, y + 27.2, z - 15, 3, 8, 1, keyboardTex2, 26, 0, 0, -1);
    drawProduct(x + 31, y + 31.2, z + 7, 3, 8, 1, keyboardTex3, 26, 0, 0, -1);
    drawProduct(x + 31, y + 31.2, z + 17, 3, 8, 1, keyboardTex4, 26, 0, 0, -1);


    // xbox
    drawProduct(x - 31.5, y + 20, z, 4.5, 4.5, 1.8, xboxTex);


    glPopMatrix();

    // COMPUTER STORE-------COMPUTER STORE-------COMPUTER STORE-------COMPUTER STORE



    // COUNTER STRIKE-------COUNTER STRIKE-------COUNTER STRIKE-------COUNTER STRIKE

    glPushMatrix();
    glTranslated(x, y, z);


    // walls 
    drawStructure(x, y, z, logoTex2);


    // store sign
    drawStoreSign(x, y + 37, z + 26, storeSignTex2);


    // tables
    drawTable(x + 12.2, y, z + 20.7, 10, 8, 42);
    drawTable(x + 12.2, y, z, 10, 13, 42);
    drawTable(x + 12.2, y, z - 20.7, 10, 8, 42);


    // middle laptops 
    glPushMatrix();
    glTranslated(x + 9, y, z + 7);

    // front 
    drawLaptop(x - 13, y + 11, z - 3, csTex1, laptopKeyboardTex1, laptopBackTex1);
    drawLaptop(x - 5, y + 11, z - 3, csTex2, laptopKeyboardTex2, laptopBackTex2);
    drawLaptop(x + 3, y + 11, z - 3, csTex3, laptopKeyboardTex3, laptopBackTex3);
    drawLaptop(x + 11, y + 11, z - 3, csTex4, laptopKeyboardTex4, laptopBackTex4);
    drawLaptop(x + 19, y + 11, z - 3, csTex5, laptopKeyboardTex5, laptopBackTex5);

    // back 
    drawLaptop(x - 13, y + 11, z - 11, csTex6, laptopKeyboardTex6, laptopBackTex6, 180, 0, 1, 0);
    drawLaptop(x - 5, y + 11, z - 11, csTex7, laptopKeyboardTex7, laptopBackTex7, 180, 0, 1, 0);
    drawLaptop(x + 3, y + 11, z - 11, csTex8, laptopKeyboardTex8, laptopBackTex8, 180, 0, 1, 0);
    drawLaptop(x + 11, y + 11, z - 11, csTex9, laptopKeyboardTex1, laptopBackTex1, 180, 0, 1, 0);
    drawLaptop(x + 19, y + 11, z - 11, csTex10, laptopKeyboardTex2, laptopBackTex2, 180, 0, 1, 0);

    glPopMatrix();

    // left laptops
    drawLaptop(x - 4, y + 11, z - 20, csTex11, laptopKeyboardTex3, laptopBackTex3);
    drawLaptop(x + 4, y + 11, z - 20, csTex12, laptopKeyboardTex4, laptopBackTex4);
    drawLaptop(x + 12, y + 11, z - 20, csTex13, laptopKeyboardTex5, laptopBackTex5);
    drawLaptop(x + 20, y + 11, z - 20, csTex14, laptopKeyboardTex6, laptopBackTex6);
    drawLaptop(x + 28, y + 11, z - 20, csTex15, laptopKeyboardTex7, laptopBackTex7);


    // right laptops 
    drawLaptop(x - 4, y + 11, z + 20, csTex16, laptopKeyboardTex8, laptopBackTex8, 180, 0, 1, 0);
    drawLaptop(x + 4, y + 11, z + 20, csTex17, laptopKeyboardTex1, laptopBackTex1, 180, 0, 1, 0);
    drawLaptop(x + 12, y + 11, z + 20, csTex18, laptopKeyboardTex2, laptopBackTex2, 180, 0, 1, 0);
    drawLaptop(x + 20, y + 11, z + 20, csTex19, laptopKeyboardTex3, laptopBackTex3, 180, 0, 1, 0);
    drawLaptop(x + 28, y + 11, z + 20, csTex20, laptopKeyboardTex4, laptopBackTex4, 180, 0, 1, 0);


    // right chairs
    drawChair(x - 4, y, z + 17, 90, 0, 1, 0);
    drawChair(x + 4, y, z + 17, 90, 0, 1, 0);
    drawChair(x + 12, y, z + 17, 90, 0, 1, 0);
    drawChair(x + 20, y, z + 17, 90, 0, 1, 0);
    drawChair(x + 28, y, z + 17, 90, 0, 1, 0);


    // left chairs
    drawChair(x - 4, y, z - 17, 90, 0, -1, 0);
    drawChair(x + 4, y, z - 17, 90, 0, -1, 0);
    drawChair(x + 12, y, z - 17, 90, 0, -1, 0);
    drawChair(x + 20, y, z - 17, 90, 0, -1, 0);
    drawChair(x + 28, y, z - 17, 90, 0, -1, 0);


    // middle chairs (front)
    drawChair(x - 4, y, z - 6, 90, 0, 1, 0);
    drawChair(x + 4, y, z - 6, 90, 0, 1, 0);
    drawChair(x + 12, y, z - 6, 90, 0, 1, 0);
    drawChair(x + 20, y, z - 6, 90, 0, 1, 0);
    drawChair(x + 28, y, z - 6, 90, 0, 1, 0);

    // middle chairs (back)
    drawChair(x - 4, y, z + 6, 90, 0, -1, 0);
    drawChair(x + 4, y, z + 6, 90, 0, -1, 0);
    drawChair(x + 12, y, z + 6, 90, 0, -1, 0);
    drawChair(x + 20, y, z + 6, 90, 0, -1, 0);
    drawChair(x + 28, y, z + 6, 90, 0, -1, 0);


    // office
    drawChair(x - 23, y, z - 18, 90, 0, 1, 0);
    drawOffice(x - 23, y, z - 3, officeCsTex, 90, 0, 1, 0);


    // monitor 
    drawMonitor(x - 23, y + 12, z - 7, monitorTex, 180, 0, 1, 0);


    glPopMatrix();

    // COUNTER STRIKE-------COUNTER STRIKE-------COUNTER STRIKE-------COUNTER STRIKE



    // PHONE STORE----------PHONE STORE----------PHONE STORE----------PHONE STORE

    glPushMatrix();
    glTranslated(x + 68, y, z);


    // walls
    drawStructure(x, y, z, logoTex3);
    glTranslated(x, y + 0.5, z);


    // store sign
    drawStoreSign(x, y + 37, z + 26, storeSignTex3);


    // samsung mobiles
    drawProduct(x, y + 14.5, z - 19, 3, 0.8, 2, mobileTex1);
    drawProduct(x + 7, y + 14.5, z - 19, 3, 0.8, 2, mobileTex2);
    drawProduct(x + 14, y + 14.5, z - 19, 3, 0.8, 2, mobileTex3);
    drawProduct(x + 21, y + 14.5, z - 19, 3, 0.8, 2, mobileTex4);


    // shawmi mobiles
    drawProduct(x, y + 7.5, z - 19, 3, 0.8, 2, mobileTex5);
    drawProduct(x + 7, y + 7.5, z - 19, 3, 0.8, 2, mobileTex6);
    drawProduct(x + 14, y + 7.5, z - 19, 3, 0.8, 2, mobileTex7);
    drawProduct(x + 21, y + 7.5, z - 19, 3, 0.8, 2, mobileTex8);


    // ipads
    drawProduct(x + 5, y + 1.5, z - 19, 4.5, 1.5, 4.5, ipadTex1);
    drawProduct(x + 15, y + 1.5, z - 19, 4.5, 1.5, 4.5, ipadTex2);


    // office
    drawChair(x - 23, y, z - 18, 90, 0, 1, 0);
    drawOffice(x - 23, y, z - 3, officeMobileTex, 90, 0, 1, 0);


    // monitor
    drawMonitor(x - 23, y + 12, z - 7, monitorTex, 180, 0, 1, 0);


    // left square roof
    drawRoof(x + 31.5, y + 19, z - 4.5, 1, 12, 3);    // bottom
    drawRoof(x + 31.5, y + 25, z - 7.5, 1, 12, 3);    // top
    drawRoof(x + 31.5, y + 16.5, z - 2, 11, 1, 3);    // left
    drawRoof(x + 31.5, y + 18, z - 10, 11, 1, 3);     // right


    // right square roof
    glPushMatrix();
    glTranslated(x + 31.5, y + 24, z + 14);
    glRotated(180, 0, 1, 0);
    drawRoof(x, y - 3, z + 2.5, 1, 12, 3);           // bottom
    drawRoof(x, y + 3, z - 1.5, 1, 12, 3);           // top
    drawRoof(x, y - 5.5, z + 4, 11, 1, 3);           // left
    drawRoof(x, y - 4, z - 4, 11, 1, 3);             // right
    glPopMatrix();


    // blutooth speakers
    drawProduct(x + 31.5, y + 20, z - 6, 2, 1.5, 4, blutoothSpeakerTex1, 90, 0, -1, 0);
    drawProduct(x + 31.5, y + 22, z + 14, 4, 1.5, 2.5, blutoothSpeakerTex2, 90, 0, -1, 0);


    // roofs
    drawRoof(x + 10, y + 25, z + 23.3, 1, 3, 20);
    drawRoof(x + 10, y + 20, z + 23.3, 1, 3, 15);
    drawRoof(x + 10, y + 15, z + 23.3, 1, 3, 10);

    // earphones
    drawProduct(x + 4, y + 26, z + 23.3, 2, 1.5, 0.8, earphonesTex1, 90, 0, -1, 0);
    drawProduct(x + 8, y + 26, z + 23.3, 2, 1.5, 0.8, earphonesTex2, 90, 0, -1, 0);
    drawProduct(x + 12, y + 26, z + 23.3, 2, 1.5, 0.8, earphonesTex3, 90, 0, -1, 0);
    drawProduct(x + 16, y + 26, z + 23.3, 2, 1.5, 0.8, earphonesTex4, 90, 0, -1, 0);


    // chargers
    drawProduct(x + 6, y + 21, z + 23.3, 2, 1.5, 0.8, chargerTex1, 90, 0, -1, 0);
    drawProduct(x + 9, y + 21, z + 23.3, 2, 1.5, 0.8, chargerTex2, 90, 0, -1, 0);
    drawProduct(x + 12, y + 21, z + 23.3, 2, 1.5, 0.8, chargerTex3, 90, 0, -1, 0);
    drawProduct(x + 15, y + 21, z + 23.3, 2, 1.5, 0.8, USPTex, 90, 0, -1, 0);


    // airpods
    drawProduct(x + 13, y + 16, z + 23.3, 1.5, 1.5, 0.8, airpodsTex1, 90, 0, -1, 0);
    drawProduct(x + 10, y + 16, z + 23.3, 1.5, 1.5, 0.8, airpodsTex2, 90, 0, -1, 0);
    drawProduct(x + 7, y + 16, z + 23.3, 1.5, 1.5, 0.8, airpodsTex3, 90, 0, -1, 0);


    // cabinet
    drawCabinet(x + 10, y, z - 19);

    glPopMatrix();

    // PHONE STORE----------PHONE STORE----------PHONE STORE----------PHONE STORE
}

void ElectronicDepartment::drawStructure(float x, float y, float z, int logo)
{
    float thickness = 0.5;
    float height = 50;
    float width = 66;
    float length = 50;

    glColor3d(1, 1, 1);

    Cuboid(Point(x, y, z), thickness, length, width).drawWithTexture(groundTex, 3, 3);                            // internal bottom face
    Cuboid(Point(x, y - 0.5, z), thickness, length, width).drawWithTexture(wallTex, 1, 1);                        // external bottom face

    Cuboid(Point(x, y + 50, z), thickness, length, width).drawWithTexture(chipTex1, 1, 1);                        // internal top face
    Cuboid(Point(x, y + 50.5, z), thickness, length, width).drawWithTexture(wallTex, 1, 1);                       // external top face

    Cuboid(Point(x, y, z - 25), height, thickness, width).drawWithTextureOnOneFace(chipTex1, "front", 1, 1);      // internal back face
    Cuboid(Point(x, y, z - 25.5), height, thickness, width).drawWithTextureOnOneFace(wallTex, "back", 1, 1);      // external back face

    Cuboid(Point(x + 33, y, z), height, length, thickness).drawWithTextureOnOneFace(chipTex1, "left", 1, 1);      // internal right face
    Cuboid(Point(x + 33.5, y, z), height, length, thickness).drawWithTextureOnOneFace(wallTex, "right", 1, 1);    // external right face

    Cuboid(Point(x - 33, y, z), height, length, thickness).drawWithTextureOnOneFace(chipTex1, "right", 1, 1);     // internal left face
    Cuboid(Point(x - 33.5, y, z), height, length, thickness).drawWithTextureOnOneFace(wallTex, "left", 1, 1);     // external left face


    Cuboid(Point(x + 10, y, z + 25), height, thickness, 46).drawWithTextureOnOneFace(chipTex1, "back", 2, 2);     // internal right part
    Cuboid(Point(x + 10, y, z + 25.5), height, thickness, 46).drawWithTextureOnOneFace(logo, "front", 1, 1);      // external right part
    Cuboid(Point(x - 28, y, z + 25), height, thickness, 10).drawWithTextureOnOneFace(chipTex1, "back", 1, 1);     // internal left part
    Cuboid(Point(x - 28, y, z + 25.5), height, thickness, 10).drawWithTextureOnOneFace(wallTex, "front", 1, 1);   // external left part
    Cuboid(Point(x - 18, y + 20, z + 25), 30, thickness, 10).drawWithTextureOnOneFace(chipTex1, "back", 1, 1);    // internal top part
    Cuboid(Point(x - 18, y + 20, z + 25.5), 30, thickness, 10).drawWithTextureOnOneFace(wallTex, "front", 1, 1);  // internal top part

    Cuboid(Point(x - 15.5, y, z + 25), 20.5, 0.5, 5).drawWithTexture(rightDoorTex, 1, 1);                         // right door
    Cuboid(Point(x - 20.5, y, z + 25), 20.5, 0.5, 5).drawWithTexture(leftDoorTex, 1, 1);                          // left door

}

void ElectronicDepartment::drawTable(float x, float y, float z, float height, float length, float width)

{
    glColor3d(0.9, 0.9, 0.9);

    glPushMatrix();
    glTranslated(x, y + 0.5, z);

    // legs
    Cuboid(Point((width - 3) / 2, 0, (length - 3) / 2), height, 1, 1).drawWithTexture(woodTex, 1, 1);
    Cuboid(Point(-(width - 3) / 2, 0, (length - 3) / 2), height, 1, 1).drawWithTexture(woodTex, 1, 1);
    Cuboid(Point((width - 3) / 2, 0, -(length - 3) / 2), height, 1, 1).drawWithTexture(woodTex, 1, 1);
    Cuboid(Point(-(width - 3) / 2, 0, -(length - 3) / 2), height, 1, 1).drawWithTexture(woodTex, 1, 1);

    // face
    Cuboid(Point(0, height, 0), 1, length, width).drawWithTexture(chipTex2, 1, 1);

    glPopMatrix();
}

void ElectronicDepartment::drawChair(float x, float y, float z, float angle, float axisX, float axisY, float axisZ)
{
    float height = 6;
    float length = 2;
    float width = 2;
    float leg_width = 0.3;

    glPushMatrix();
    glTranslated(x, y + 0.5, z);
    glRotated(angle, axisX, axisY, axisZ);

    // legs
    glColor3d(0.9, 0.9, 0.9);
    Cylinder cyl;
    cyl.drawWithTexture(Point(width, height, length), leg_width, leg_width, height, 36, 36, stanslessTex);
    cyl.drawWithTexture(Point(-width, height, length), leg_width, leg_width, height, 36, 36, stanslessTex);
    cyl.drawWithTexture(Point(width, height, -length), leg_width, leg_width, height, 36, 36, stanslessTex);
    cyl.drawWithTexture(Point(-width, height, -length), leg_width, leg_width, height, 36, 36, stanslessTex);

    // base
    glColor3d(0.8, 0.8, 0.8);
    Cuboid(Point(0, height, 0), 1, 2 * length + 1, 2 * width + 1).drawWithTexture(woodTex, 1, 1);

    // stand
    glColor3d(0.9, 0.9, 0.9);
    cyl.drawWithTexture(Point(width, 2 * height, length), leg_width, leg_width, height, 36, 36, stanslessTex);                // stand1
    cyl.drawWithTexture(Point(width, 2 * height, 0), leg_width, leg_width, height, 36, 36, stanslessTex);                     // stand2
    cyl.drawWithTexture(Point(width, 2 * height, -length), leg_width, leg_width, height, 36, 36, stanslessTex);               // stand3
    glColor3d(0.8, 0.8, 0.8);
    Cuboid(Point(width, 2 * height, 0), 2, 2 * length + 2, 1).drawWithTexture(woodTex, 1, 1);                                     // top stand

    glPopMatrix();
}

void ElectronicDepartment::drawOffice(float x, float y, float z, int sticker, float angle, float axisX, float axisY, float axisZ) {

    float height = 12;

    glColor3d(0.8, 0.8, 0.8);

    glPushMatrix();
    glTranslated(x, y + 0.5, z);
    glRotated(angle, axisX, axisY, axisZ);

    Cuboid(Point(0, 0, 0), height, 11, 1).drawWithTexture(woodTex, 1, 1);                               // back
    Cuboid(Point(-0.5, 0, 0), height, 11, 0.1).drawWithTextureOnOneFace(sticker, "left", 1, 1);         //sticker
    Cuboid(Point(5, 0, 5), height, 1, 10).drawWithTexture(woodTex, 1, 1);                               // left
    Cuboid(Point(5, 0, -5), height, 1, 10).drawWithTexture(woodTex, 1, 1);                              // right
    Cuboid(Point(5, height - 1, 0), 1, 11, 11).drawWithTexture(woodTex, 1, 1);                          // top

    // drawer
    float height_of_drawer = 2;

    Cuboid(Point(10, height - 3, 0), 0.5, 8.5, 10).drawWithTexture(woodTex, 1, 1);                     // bottom 
    Cuboid(Point(10.5, height - 2.5, 0), 0.2, 8, 9).drawWithTexture(moneyTex, 1, 1);                   // money 
    Cuboid(Point(10, height - 3, 4), height_of_drawer, 0.5, 10).drawWithTexture(woodTex, 1, 1);        // left
    Cuboid(Point(10, height - 3, -4), height_of_drawer, 0.5, 10).drawWithTexture(woodTex, 1, 1);       // right
    Cuboid(Point(15, height - 3, 0), height_of_drawer, 8.5, 0.5).drawWithTexture(woodTex, 1, 1);       // front

    // draw handle
    glColor3d(0.9, 0.9, 0.9);
    Cuboid(Point(15.7, height - 2, 0), 0.2, 1.7, 0.2).drawWithTexture(stanslessTex, 1, 1);             // front
    Cuboid(Point(15.4, height - 2, -0.5), 0.2, 0.2, 0.5).drawWithTexture(stanslessTex, 1, 1);          // right
    Cuboid(Point(15.4, height - 2, 0.5), 0.2, 0.2, 0.5).drawWithTexture(stanslessTex, 1, 1);           // left

    glPopMatrix();
}



void ElectronicDepartment::drawRoof(float x, float y, float z, float height, float length, float width)
{
    glColor3d(0.9, 0.9, 0.9);
    Cuboid(Point(x, y, z), height, length, width).drawWithTexture(woodTex, 1, 1);
}

void ElectronicDepartment::drawLaptop(float x, float y, float z, int screen_tex, int keyboard_tex, int back_tex, float angle, float axisX, float axisY, float axisZ)
{
    glColor3d(1, 1, 1);

    glPushMatrix();
    glTranslated(x, y + 0.5, z);
    glRotated(angle, axisX, axisY, axisZ);
    Cuboid(Point(0, 0, 0), 0.1, 3, 4).drawWithTexture(keyboard_tex, 1, 1);                      // keyboard
    glPushMatrix();
    glTranslated(0, 0.1, -1.5);
    glRotated(15, -1, 0, 0);
    Cuboid(Point(0, 0, 0), 2.95, 0.05, 3.95).drawWithTexture(screen_tex, 1, 1);                 // screen
    Cuboid(Point(0, 0, -0.05), 3, 0.1, 4).drawWithTextureOnOneFace(back_tex, "back", 1, 1);    // back
    glPopMatrix();
    glPopMatrix();
}

void ElectronicDepartment::drawStoreSign(float x, float y, float z, int tex)
{
    glColor3d(1, 1, 1);
    Cuboid(Point(x, y, z), 13, 0.5, 66).drawWithTexture(tex, 1, 1);
}

void ElectronicDepartment::drawMonitor(float x, float y, float z, int tex, float angle, float axisX, float axisY, float axisZ)
{
    glColor3d(1, 1, 1);
    glPushMatrix();
    glTranslated(x, y + 0.5, z);
    glRotated(angle, axisX, axisY, axisZ);
    Cuboid(Point(0, 0, 0), 0.1, 2, 2).drawWithTexture(stanslessTex, 1, 1);            // base
    Cuboid(Point(0, 1, 0), 3.95, 0.05, 6.95).drawWithTexture(tex, 1, 1);              // screen
    Cuboid(Point(0, 0, -0.2), 3, 0.1, 1).drawWithTexture(stanslessTex, 1, 1);         // stand
    Cuboid(Point(0, 1, -0.05), 4, 0.1, 7).drawWithTexture(stanslessTex, 1, 1);        // back
    Cuboid(Point(0, 0, 4), 0.2, 2.4, 7).drawWithTexture(keyboardTex, 1, 1);           // keyboard
    glPopMatrix();
}

void ElectronicDepartment::drawCabinet(float x, float y, float z)
{
    glColor3d(1, 1, 1);

    // legs
    Cuboid(Point(x + 14.5, y, z + 4.5), 1, 0.7, 0.7).drawWithTexture(woodTex, 1, 1);
    Cuboid(Point(x + 14.5, y, z - 4.5), 1, 0.7, 0.7).drawWithTexture(woodTex, 1, 1);
    Cuboid(Point(x - 14.5, y, z + 4.5), 1, 0.7, 0.7).drawWithTexture(woodTex, 1, 1);
    Cuboid(Point(x - 14.5, y, z - 4.5), 1, 0.7, 0.7).drawWithTexture(woodTex, 1, 1);

    Cuboid(Point(x, y + 0.5, z), 1, 10, 30).drawWithTexture(woodTex, 1, 1);                // base
    Cuboid(Point(x, y + 20.5, z), 1, 10, 30).drawWithTexture(woodTex, 1, 1);               // top
    Cuboid(Point(x, y + 0.5, z - 5), 20, 1, 30).drawWithTexture(woodTex, 1, 1);            // back
    Cuboid(Point(x + 14.5, y + 0.5, z), 20, 10, 1).drawWithTexture(woodTex, 1, 1);         // right
    Cuboid(Point(x - 14.5, y + 0.5, z), 20, 10, 1).drawWithTexture(woodTex, 1, 1);         // left
    glColor3d(0.9, 0.9, 0.9);
    Cuboid(Point(x, y + 13.5, z), 1, 10, 30).drawWithTexture(woodTex, 1, 1);               // roof 1
    Cuboid(Point(x, y + 6.5, z), 1, 10, 30).drawWithTexture(woodTex, 1, 1);                // roof 2

    glColor3d(1, 1, 1);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glColor4d(1, 1, 1, 0.15);
    Cuboid(Point(x, y + 1.5, z + 4.9), 19, 0.3, 28).draw();                                // front
    glDisable(GL_BLEND);
}

void ElectronicDepartment::drawProduct(float x, float y, float z, float height, float length, float width, int tex, float angle, float axisX, float axisY, float axisZ)
{
    glColor3d(1, 1, 1);

    glPushMatrix();
    glTranslated(x, y, z);
    glRotated(angle, axisX, axisY, axisZ);
    Cuboid(Point(0, 0, 0), height, length, width).drawWithTexture(tex, 1, 1);
    glPopMatrix();
}