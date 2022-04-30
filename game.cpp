
//FATIMA MUNEER
//BS CS-1D
//l20-2133


//============================================================================
// Name        : brickSlayerITC.cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Brick Slayer...
//============================================================================

#ifndef BSLAYER_CPP_
#define BSLAYER_CPP_
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

//defining some MACROS

#define MAX(A,B) ((A) > (B) ? (A):(B)) // finds max of two numbers
#define MIN(A,B) ((A) < (B) ? (A):(B)) // find min of two numbers
#define ABS(A) ((A) < (0) ? -(A):(A))  // find ABS of a given number

// define some constants
// constant FPS (Frame per second) is  used to specify
// number of frames per second in your game.. if FPS is small 
// your objects will move slowly and if large your objects
// will move faster, see the Timer function below for further help

#define FPS 80 // frame per seconds

// define another constant to hold ASCII for Escape key.
#define KEY_ESC 27 // A

// define some colors as 2D arrays, we have five pre-defined colors here..
// you can add many more if you wish..
int check[234]={0};
struct bricks{

int xa;
int ya;
int xb;
int yb;

};
bricks bb[1000];
int bheight=30;
int bwidth=70;
int xx=0;
int yy=0;
void vanishbricks(int midx,int midy);
float colors[5][3] = { { 1 / 255.0, 164 / 255.0, 164 / 255.0 }, { 215 / 255.0, 0
		/ 255.0, 96 / 255.0 }, { 208 / 255.0, 209 / 255.0, 2 / 255.0 }, { 0
		/ 255.0, 161 / 255.0, 203 / 255.0 }, { 50 / 255.0, 116 / 255.0, 44
		/ 255.0 } };

// defining some utility functions...
/*
 * This function converts an input angle from degree to radians */
float Deg2rad(float degree) {
	return (degree / 180.0) * M_PI;
}
// seed the random numbers generator by current time (see the documentation of srand for further help)...
void InitRandomizer() {
	srand((unsigned int) time(0)); // time(0) returns number of seconds elapsed since January 1, 1970.
}
//This function returns a random value within the specified range of [rmin, rmax] ...
long GetRandInRange(const long &rmin, const long &rmax) {
	long range = rmax - rmin; // find the range
	long value = (rand() % (long) range) + rmin; // translate the generated number ...
//	cout << value << endl << flush;
	return value;
}

/*To draw a triangle we need three vertices with each vertex having 2-coordinates [x, y] and a color for the triangle.
 * This function takes 4 arguments first three arguments (3 vertices + 1 color) to
 * draw the triangle with the given color.
 * */

void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3,
		float color[]) {
	glColor3fv(color); // Set the triangle colour
	// ask library to draw triangle at given position...

	glBegin(GL_TRIANGLES);
	/*Draw triangle using given three vertices...*/
	glVertex4i(x1, y1, 0, 1);
	glVertex4i(x2, y2, 0, 1);
	glVertex4i(x3, y3, 0, 1);
	glEnd();

}
void drawbricks(){

int a=100;
int b=560;
int i=1;
int j;
int k;
while(b>150){
if(i==1)
i=3;
else if(i==3)
i=1;
while(a<680)   
{
j=a;
k=b;

DrawTriangle(j+70,k,j,k,j,k-30,colors[i]);//upper triangle
DrawTriangle(a+70,b,a,b-30,a+70,b-30,colors[i]);//lower triangle

a=a+71;
}
a=100;
b=b-30;
}
}

/*
 * Write two functions DrawRectangle and DrawSphere
 * */

/*
 * Main Canvas drawing function.
 * */
	
   int midx=50;
int midy=520;
  int x=150;
  int y=5;
  int a1=10;
  int b1=30;
void drawball(){	
		float theta = Deg2rad(10);
float theta2=Deg2rad(30);
while(theta<=5720){


   	DrawTriangle(midx, midy, midx + 10 * cos(theta),
				midy + 10 * sin(theta), midx + 10 * cos(theta2),
				midy + 10 * sin(theta2), colors[4]);
	theta = theta+20;
		theta2 = theta2+20;


DrawTriangle(midx, midy, midx + 10 * cos(theta),
				midy + 10 * sin(theta), midx + 10 * cos(theta2),
				midy + 10 * sin(theta2), colors[4]);
	theta = theta+20;
		theta2 = theta2+20;
	}

}
void Display()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(6.0/*Red Component*/, 7.0/*Green Component*/,
			5.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
//drawbricks();
vanishbricks(midx,midy);
	// Drawing set of three triangles at different points of a circle using simple trignometry...
 
   //   for (float theta=Deg2rad(100);theta !=360; midx += 250) {

drawball();
  
	 DrawTriangle(a1+150, b1,a1 , b1, a1, b1-5, colors[4]);

	DrawTriangle(a1+150, b1, a1, b1-5, a1+150, b1-5, colors[4]);


	glutSwapBuffers(); // do not modify this line..
}
/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
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
//int p1=160,p2=20,p3=10,p4=20,p5=10,p6=10;
//int v1=160,v2=20,v3=10,v4=10,v5=160,v6=10;

//                  a1=10;
  //                b1=20;
    //              x=150;
      //            y=10;
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
             a1=a1-50;


          if(a1>=0&&a1<700)
          {   
     
         glutPostRedisplay();
      }
         else
         a1=a1+50;



	} else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
                 	// what to do when left key is pressed...
       
        a1=a1+50;

          if(a1>=0&&a1<700)
          {   
     
         glutPostRedisplay();


}
else 
a1=a1-50;
	} else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
           
             b1=b1+30;
      if(b1>10&&b1<100)
       {
         glutPostRedisplay(); 
}
else
   b1=b1-30;

	}

	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
                       
                    b1=b1-30;
  if(b1>10&&b1<100)
       {
         glutPostRedisplay(); 
}
else
b1=b1+30;


	}

	

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	/*
	 glutPostRedisplay();
	 */
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == KEY_ESC/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
}

/*
 * This function is called after every 1000.0/FPS milliseconds 
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
int ballmin=2;
int ballmax=2;
void vanishbricks(int midx,int midy){

int a=100;
int b=560;
int i=1;


int xx=0;
int yy=0;
i=2;
while(b>150){
if(i==2)
i=5;
else if(i==5)
i=2;
 
bb[yy].ya=b;
bb[yy].yb=b-30;
while(a<680){

bb[xx].xa=a;
bb[xx].xb=a+71;
//if(midy<=bb[yy].ya&& midy>=bb[yy].yb && midx>=bb[xx].xa && midx<= bb[xx].xb && check[xx]==0){
if(midy==bb[yy].ya && midx>bb[xx].xa && midx< bb[xx].xb && check[xx]==0){
//ballmax=-ballmax;
if(ballmin<0)
ballmin=ballmin;
else
ballmin=-ballmin;
check[xx]=1;


}
if(midy==bb[yy].yb && midx>bb[xx].xa && midx< bb[xx].xb && check[xx]==0){
//ballmax=-ballmax;
if(ballmin<0)
ballmin=-ballmin;
else
ballmin=ballmin;

check[xx]=1;
}
if(midy<bb[yy].ya && midy>bb[yy].yb && midx==bb[xx].xa && check[xx]==0){
if(ballmax<0)
ballmax=-ballmax;
else
ballmax=ballmax;

check[xx]=1;

}
if(midy<bb[yy].ya && midy>bb[yy].yb && midx==bb[xx].xb && check[xx]==0){
if(ballmax<0)
ballmax=ballmax;
else
ballmax=-ballmax;


check[xx]=1;

}
if(check[xx]==0)
{

DrawTriangle(a+70,b,a,b,a,b-30,colors[i]);//upper triangle
DrawTriangle(a+70,b,a,b-30,a+70,b-30,colors[i]);//lower triangle}
}
xx++;
a=a+71;

}
a=100;

b=b-30;
yy++;
}
glutPostRedisplay();
} 

void Timer(int m) {

glutTimerFunc(1000.0 / FPS, Timer, 0);	
	// implement your functionality here

GetRandInRange(midx,midy);

if(midx>=790||midx<=10)
ballmax=-ballmax;
if(midy>=600)
ballmin=-ballmin;
if(midy==b1 && midx>=a1&&midx<=a1+150)
ballmin=-ballmin;
if(midy<=0)
midy=10;
else 
{
midy=midy-ballmin;
midx=midx-ballmax;

}
//vanishbricks(midx,midy);
glutPostRedisplay();
	
	// once again we tell the library to call our Timer function after next 1000/FPS
	
}

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
	int width = 800, height = 600; // i have set my window size to be 800 x 600
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("ITCs Brick Slayer"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	glutDisplayFunc(Display); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0 / FPS, Timer, 0);

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* BSLAYER_CPP_ */
