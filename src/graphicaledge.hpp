#ifndef GRAPHICALEDGE_HPP
#define GRAPHICALEDGE_HPP

#include <QtOpenGL/QGLWidget>
#include <geometricobject.hpp>

class GraphicalEdge : public GeometricObject
{
public:
    GraphicalEdge();

    void create();
    void draw();

    void setPosition(double*);
    void setOrientation(double*);
    void setDimension(double,double);
    void getDimension(double&,double&);
    void getIDs(int&,int&);
    void setID1(int);
    void setID2(int);

private:
    int ID1,ID2;
    double radius;
    double length;
    double xRot,yRot,zRot;
};

#endif // GRAPHICALEDGE_HPP
