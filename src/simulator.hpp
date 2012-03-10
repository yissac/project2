#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <QGLWidget>
#include <QtGui/QKeyEvent>
#include <QTimerEvent>
#include <map>
#include <cmath>
#include "geometricobject.hpp"
#include "graphicalnode.hpp"
#include "graphicaledge.hpp"
#include "observer.hpp"
#include "mechanicalnode.hpp"
#include "node.hpp"
#include "edge.hpp"

#include <iostream>
#include <cstdio>

class Simulator : public QGLWidget, public Observer
{
    Q_OBJECT
public:
    explicit Simulator(QWidget *parent = 0);
    ~Simulator();

    void initializeNetwork(std::map <int,MechanicalNode*>*);
    void drawSolutionPath(Node*);
    void notify();
    void notify(int,NotificationType);

private:

    void createNetwork();

    void initializeGL();
    void resizeGL(int,int);
    void paintGL();

    void timerEvent(QTimerEvent*);
    void keyPressEvent(QKeyEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);

    void homeView();

    void normalizeAngle(int&);
    void setXRotation(int);
    void setYRotation(int);
    void setZRotation(int);
    int  getXRotation();
    int  getYRotation();
    int  getZRotation();

    int xRot;
    int yRot;
    int zRot;
    QPoint lastPos;
    double zHomeView;

    std::vector <GeometricObject*> graphicalObjects;
    int timerID;

    std::map <int,GraphicalNode*> nodeMap;
//    std::map <int,GraphicalEdge*> edgeMap;
    std::vector <GraphicalEdge*> edgeVec;
    std::map <int,MechanicalNode*>* network;

signals:
public slots:
};

#endif // SIMULATOR_HPP
