
#include <GL/glut.h>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "Vector3.h"
#include "Ground.h"

//window variables
bool isFullScreen = false;

//change in position of camera
float deltaFor = 0.0f;
float deltaHor = 0.0f;
float deltaVert = 0.0f;
//current position of camera
Vector3* camPos = new Vector3(-1.0f,0.0f,1.0f);
//angle of camera
bool camChange = false;
float camTheta = 0.0f;
float camPhi = M_PI/2;
//direction the camera is facing
Vector3* camLook = new Vector3(0.0f,0.0f,-1.0f);
//speed of character
float speed = 0.001f;
float rotSpeed = 0.005f;
//mouse position values
int prevMouseX = -1;
int prevMouseY = -1;

//entity list


void mouseMove(int x, int y) {

    camChange = true;
    int dx = x-prevMouseX;
    int dy = y-prevMouseY;
    camTheta+=dx*rotSpeed;
    if(camTheta>2*M_PI) {
        camTheta-=2*M_PI;
    }
    if(camTheta<0) {
        camTheta = 2*M_PI+camTheta;
    }
    camPhi-=dy*rotSpeed;
    if(camPhi>M_PI) {
        camPhi=M_PI;
    }
    if(camPhi<0) {
        camPhi=0;
    }
    prevMouseX=x;
    prevMouseY=y;

}

void toggleFullScreen() {
    if(!isFullScreen) {
        glutFullScreen();
        isFullScreen=true;
        glutSetCursor(GLUT_CURSOR_NONE);
    }
    else {
        glutReshapeWindow(1920,1080);
        isFullScreen=false;
        glutSetCursor(GLUT_CURSOR_INHERIT);
    }
}

//processes key events of keys with an ASCII code
void processSpecialKeys(int key, int xx, int yy) {

    switch(key) {
        case(GLUT_KEY_F1): toggleFullScreen();
    }

}

//handles when a normal key is pressed
void pressKey(unsigned char key, int xx, int yy) {
    switch(key) {
        case(27): exit(0);
        case('w'): deltaFor=1.0f; break;
        case('s'): deltaFor=-1.0f; break;
        case('a'): deltaHor=-1.0f; break;
        case('d'): deltaHor=1.0f; break;
        case(' '): deltaVert=1.0f; break;
        case('f'): deltaVert=-1.0f; break;
    }
}

//handles when a normal key is released
void releaseKey(unsigned char key, int x, int y) {
    switch(key) {
        case('w'):
        case('s'): deltaFor=0.0f; break;
        case('a'):
        case('d'): deltaHor=0.0f; break;
        case(' '):
        case('f'): deltaVert=0.0f; break;
    }
}


void computePos() {
    (*camPos).x = (*camPos).x+(*camLook).x*speed*deltaFor;
    (*camPos).z = (*camPos).z+(*camLook).z*speed*deltaFor;
    (*camPos).x += -(*camLook).z*speed*deltaHor;
    (*camPos).z += (*camLook).x*speed*deltaHor;
    (*camPos).y += deltaVert*speed;
}

void computeDir() {
    (*camLook).y=-cos(camPhi);
    (*camLook).z=-cos(camTheta);
    (*camLook).x=sin(camTheta);

    camChange = false;
}

void renderScene(void) {

    if(deltaFor or deltaHor or deltaVert) {
        computePos();
    }

    if(camChange) {
        computeDir();
    }

    //clear Color and Depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //reset transformations
    glLoadIdentity();
    //Set the camera
    gluLookAt(  (*camPos).x, (*camPos).y, (*camPos).z,
                (*camPos).x+(*camLook).x, (*camPos).y+(*camLook).y, (*camPos).z+(*camLook).z,
                0.0f, 1.0f, 0.0f);


    auto* g = new Ground(*new Vector3(-1.0f,-1.0f,-1.0f), *new Vector3(0.0f,1.0f,0.0f),2,2);
    (*g).render();

    //glutSolidTeapot(1);

    glutSwapBuffers();
}


void changeSize(int w, int h) {
    //prevent a divide by zero
    if(h==0) {
        h=1;
    }
    float ratio = w*1.0/h;

    //Use the projection matrix
    glMatrixMode(GL_PROJECTION);

    //reset matrix
    glLoadIdentity();

    //set the viewport to be the whole window
    glViewport(0,0,w,h);

    //set perspective
    gluPerspective(45,ratio,1,100);

    //back to model-view
    glMatrixMode(GL_MODELVIEW);
}

//main function to start program
int main(int argc, char **argv) {
    //init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1920,1080);
    glutCreateWindow("Hello Rat");

    //register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);

    //keyboard event handlers
    glutKeyboardFunc(pressKey);
    glutSpecialFunc(processSpecialKeys);
    glutIgnoreKeyRepeat(1);
    glutKeyboardUpFunc(releaseKey);

    //mouse handler
    glutPassiveMotionFunc(mouseMove);

    //OpenGL init
    glEnable(GL_DEPTH_TEST);

    //enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}



