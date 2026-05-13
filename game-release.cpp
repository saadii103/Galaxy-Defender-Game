//============================================================================
// Name        : Galaxy Defender.cpp
// Author      : Saad Shafiq
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Tetris...
//============================================================================
#ifndef TETRIS_CPP_
#define TETRIS_CPP_
#include "util.h"
#include <iostream>
#include<vector>
#include<algorithm>
//#include<cstdlib>
#include<ctime>
#include<string>
//#include<sys/wait.h>
//#include<stdlib.h>
//#include<stdio.h>
#include<unistd.h>
#include<sstream>
#include<fstream>
#include<cmath>      // for basic math functions such as cos, sin, sqrt
using namespace std;

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */

void SetCanvasSize(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
}
/*
 * Main Canvas drawing function.
 * */
 int lives=3;
 int score=0;

int enemySpeed = 3;

bool pose=false;

char scoreText[20];
char livesText[20];
string playerName = "";
bool gameStarted = false;
bool gameOver = false;
 const int MAX_BULLETS = 5000;
int bulletX[MAX_BULLETS];
int bulletY[MAX_BULLETS];
bool bulletActive[MAX_BULLETS];

int bulletCount = 0;

int fireCooldown = 0;
const int maxCooldown = 10;

 int rx=20, ry=75;
int ex[9] = {73, 512, 389, 750, 201, 667, 45, 590, 310};
int ey[9] = {900, 950, 1000, 1050, 1100, 1150, 1200, 1250, 1300};

//string name;
bool saved=false;

void Display() {

DrawString(750,800,livesText , colors[WHITE]);
    // set the background color using function glClearColotgr.
    // to change the background play with the red, green and blue values below.
    // Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

  glClearColor(0/*Red Component*/, 0.0/*Green Component*/,
            0.0/*Blue Component*/, 0 /*Alpha component*/);// Red==Green==Blue==1 --> White Colour
    glClear(GL_COLOR_BUFFER_BIT);   //Update the colors
    // NAME SCREEN
    if (gameStarted == false) {
        DrawString(230, 550, "---Galaxy Defender Game---", colors[RED]);
        DrawString(130, 500, "Enter Your Name: ", colors[RED]);
        DrawString(350, 500, playerName, colors[WHITE]);
        DrawString(220, 450, "Press ENTER To Start Game", colors[RED]);
        glutSwapBuffers();
        return;  // baaki kuch mat draw karo
    }

    // GAME OVER SCREEN
    if (gameOver == true) {
        DrawString(300, 500, "--- GAME OVER ---", colors[RED]);
        DrawString(200, 450, "Player: ", colors[WHITE]);
        DrawString(310, 450, playerName, colors[HOT_PINK]);
        DrawString(200, 400, scoreText, colors[WHITE]);
        glutSwapBuffers();
        return;  // baaki kuch mat draw karo
    }
    DrawString(10,  820, scoreText, colors[HOT_PINK]);
DrawString(750, 820, livesText, colors[HOT_PINK]);
srand(12345);
for (int i = 0; i < 250; i++)
DrawCircle(rand() % 860, rand() % 850, 2, colors[WHITE]);
    //Rocket
DrawTriangle(rx,ry,rx+40,ry,rx+20,ry+30,colors[RED]); //nose
DrawRoundRect(rx,ry-50,40,50,colors[DARK_OLIVE_GREEN],10);
DrawCircle(rx+20,ry-35,5,colors[BLUE]); //Upper Circle
DrawCircle(rx+20,ry-15,5,colors[BLUE]); //Lower Circle
DrawTriangle(rx,ry-25,rx-8,ry-45,rx,ry-45,colors[ORANGE]);// Left Wing
DrawTriangle(rx+40,ry-25,rx+48,ry-45,rx+40,ry-45,colors[ORANGE]); // Right Wing
DrawTriangle(rx+10, ry-50, rx+30, ry-50, rx+20, ry-60, colors[YELLOW]); //Flame

// draw bullets
    for (int i = 0; i < bulletCount; i++) {

        if (bulletActive[i])
            DrawTriangle(bulletX[i], bulletY[i], bulletX[i] + 6, bulletY[i], bulletX[i] + 3, bulletY[i] + 10, colors[BLUE]);
    }
for (int i = 0; i < 9; i++)
{
    DrawSquare(ex[i], ey[i], 40, colors[GREEN]);
    DrawCircle(ex[i] + 10, ey[i] + 10, 3, colors[WHITE]);
    DrawCircle(ex[i] + 30, ey[i] + 10, 3, colors[WHITE]);
}

   glutSwapBuffers(); // do not modify this line..
}
/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT   /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
			rx-=7;							// what to do when left key is pressed...
                      if (rx<=20)
                      rx=20;
      
    } else if (key == GLUT_KEY_RIGHT  /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		rx+=7;
		if (rx>=800)
		rx=800;
    } 
    /* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
     * this function*/
     glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {

    // ── SABSE PEHLE yeh check karo ──
    if (gameStarted == false) {
        if (key == 13 && playerName.length() > 0) {  // Enter
            gameStarted = true;
        }
        else if (key == 8 && playerName.length() > 0) {  // Backspace
            playerName.pop_back();
        }
        else if (key >= 32 && key <= 126) {  // Normal keys
            playerName += key;
        }
        glutPostRedisplay();
        return;  // yahan se wapas jao, baaki code mat chalaoo
    }

    // ── GAME SHURU HO GAYI TO YAHAN AEGA ──
    if (key == KEY_ESC) {
        exit(1);
    }
    if (key == ' ' || key == 32) {
        if (fireCooldown == 0 && bulletCount < MAX_BULLETS) {
            bulletX[bulletCount] = rx + 20;
            bulletY[bulletCount] = ry + 50;
            bulletActive[bulletCount] = true;
            bulletCount++;
            fireCooldown = maxCooldown;
        }
    }

    if (key == 'P' || key == 'p')
        pose = true;
    else if (key == 'R' || key == 'r')
        pose = false;

    glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */

void Timer(int m) {

srand(time(0));
    // move bullets
    for (int i = 0; i < bulletCount; i++) {

        if (bulletActive[i]) {

            bulletY[i] += 10;


            if (bulletY[i] > 850)
                bulletActive[i] = false;
        }
    }

if (pose) {
    glutPostRedisplay();
    glutTimerFunc(1000.0 / FPS, Timer, 0);
    return;
}
    if (fireCooldown > 0) {
        fireCooldown--;
    }
    // collision
for (int i = 0; i < bulletCount; i++)
{
    if (!bulletActive[i]) continue;  // agar bullet active nahi to skip

    for (int j = 0; j < 9; j++)
    {
        
        if (bulletX[i] > ex[j] - 40 && bulletX[i] < ex[j] + 40 &&
            bulletY[i] > ey[j] - 40 && bulletY[i] < ey[j] + 40)
        {
            bulletActive[i] = false;        // bullet khatam
            ex[j] = 10 + rand() % 760;     // enemy nai jagah
            ey[j] = 900 + rand() % 300;    // enemy wapas upar
            score+=5;
        }
    }
}

for (int i = 0; i < 9; i++)
{
    ey[i] -= enemySpeed;

    if (ey[i] < 5)
    {
       ex[i] = 10 + rand() % 760;
        ey[i] = 900 + rand() % 300;
        lives--;
    }
}

if (score > 0 && score % 50 == 0)
    enemySpeed = 3 + (score / 50);
if (lives <= 0 && gameOver == false) {
    gameOver = true;
    ofstream file("data.txt", ios::app);
    if (file.is_open()) {
        file << "Name: " << playerName << "  |  Score: " << score << endl;
        file.close();
    }
}


sprintf(scoreText, "Score: %d", score);
sprintf(livesText, "Lives: %d", lives);

// implement your functionality here
	glutPostRedisplay();
// once again we tell the library to call our Timer function after next 1000/FPS
    glutTimerFunc(1000.0 / FPS, Timer, 0);
}

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]){     int width = 850, height = 850; // i have set my window size to be 800 x 600
    InitRandomizer(); // seed the random number generator...
    glutInit(&argc, argv); // initialize the graphics library...
    srand(time(0));
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
    glutInitWindowPosition(50, 50); // set the initial position of our window
    glutInitWindowSize(width, height); // set the size of our window
    glutCreateWindow("Saad's Galaxy Defender Game"); // set the title of our game window
    SetCanvasSize(width, height); // set the number of pixels...

// Register your functions to the library,
// you are telling the library names of function to call for different tasks.
//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
    glutDisplayFunc(Display); // tell library which function to call for drawing Canvas.
    glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
    glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
    glutTimerFunc(5.0 / FPS, Timer, 0);

// now handle the control to library and it will call our registered functions when
// it deems necessary...
    glutMainLoop();
    return 1;
}
#endif /* Snake Game */

