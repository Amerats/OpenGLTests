//
// Created by Amerats on 7/4/2022.
//

#include "Ground.h"
#include <GL/glut.h>

Ground::Ground() = default;
Ground::Ground(Vector3& position, Vector3& normal, float width, float length) {
    pos=position;
    norm=normal;
    w=width;
    l=length;
}

void Ground::render() const {
    glColor3f(255,0,0);
    glBegin(GL_QUADS);
    glVertex3f(pos.x,pos.y,pos.z);
    glVertex3f(pos.x,pos.y,pos.z+l);
    glVertex3f(pos.x+w,pos.y,pos.z+l);
    glVertex3f(pos.x+w,pos.y,pos.z);
    glEnd();
    glColor3f(255,255,255);
}

