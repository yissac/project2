#include "graphicalnode.hpp"
#include <GL/glu.h>

GraphicalNode::GraphicalNode()
{
}

void GraphicalNode::create()
{
    GLUquadricObj* sphere;
    mListIndex = glGenLists(1);

    if (mListIndex != 0)
    {
        glNewList(mListIndex,GL_COMPILE);
            sphere = gluNewQuadric();
            gluQuadricDrawStyle(sphere,GLU_TRUE);
            gluQuadricNormals(sphere,GLU_SMOOTH);
            gluSphere(sphere,radius,16,16);
        glEndList();
        // Delete the pointer
        gluDeleteQuadric(sphere);
    }
}

void GraphicalNode::draw()
{
    glPushMatrix();
        glColor3dv(clr);
        glTranslated(pos[0],pos[1],pos[2]);
//        glRotated(0.0,0.0,0.0,0.0);
        glCallList(mListIndex);
    glPopMatrix();
}

void GraphicalNode::setRadius(double inRadius)
{
    radius = inRadius;
}

double GraphicalNode::getRadius()
{
      return radius;
}
