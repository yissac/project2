#include "environment.h"
#include <cstdio>

Environment::Environment()
{
    scene.setSceneRect(X_BASE,Y_BASE,X_RANGE,Y_RANGE);

    //bounding box
    scene.addLine(X_BASE        ,Y_BASE        ,X_BASE+X_RANGE,Y_BASE        );
    scene.addLine(X_BASE        ,Y_BASE+Y_RANGE,X_BASE+X_RANGE,Y_BASE+Y_RANGE);
    scene.addLine(X_BASE        ,Y_BASE        ,X_BASE        ,Y_BASE+Y_RANGE);
    scene.addLine(X_BASE+X_RANGE,Y_BASE        ,X_BASE+X_RANGE,Y_BASE+Y_RANGE);

    //Obstacle 1
    scene.addEllipse(-500,-500,300,300,QPen(Qt::green),QBrush(Qt::green,Qt::SolidPattern));
    //Obstacle 2
    QPolygon triangle1;
    triangle1 << QPoint(0,150) << QPoint(-150,-150) << QPoint(150,-150);
    scene.addPolygon(triangle1,QPen(Qt::green),QBrush(Qt::green,Qt::SolidPattern));
    //Obstacle 3
    scene.addRect(250,250,250,250,QPen(Qt::green),QBrush(Qt::green,Qt::SolidPattern));
    //Obstacle 4
    scene.addRect(-250,-250,250,250,QPen(Qt::green),QBrush(Qt::green,Qt::SolidPattern));
    //Obstacle 5
    QPolygon triangle2;
    triangle2 << QPoint(250,250) << QPoint(100,100) << QPoint(350,300);
    scene.addPolygon(triangle2,QPen(Qt::green),QBrush(Qt::green,Qt::SolidPattern));

    current = scene.addRect(-5,-50,10,100,QPen(Qt::blue),QBrush(Qt::blue,Qt::SolidPattern));
}

void Environment::initPosition(qreal x, qreal y, qreal theta)
{
    current->setPos(x,y);
    current->setRotation(theta);
}

void Environment::goalPosition(qreal x, qreal y, qreal theta)
{
}

bool Environment::pathIsValid(SearchNode* start, SearchNode* finish)
{
    float dx,dy,dtheta,mag;
    dx = finish->x()-start->x();
    dy = finish->y()-start->y();
    dtheta = finish->theta()-start->theta();
    mag = sqrt(dx*dx + dy*dy + dtheta+dtheta);

    //if you are already close enough to make the jump...
    if (mag < MAX_CHECK_DISTANCE)
    {
        return pointIsValid(finish);
    }
    else
    {
        if(!pointIsValid(finish)) return false;
    }
    //normalize
    dx *= MAX_CHECK_DISTANCE/mag;
    dy *= MAX_CHECK_DISTANCE/mag;
    dtheta *= MAX_CHECK_DISTANCE/mag;
    SearchNode* temp = new SearchNode(start->x(),
                          start->y(),
                          start->theta());
    do
    {
        temp = new SearchNode(temp->x()+dx,
                        temp->y()+dy,
                        temp->theta()+dtheta);
        if(!pointIsValid(temp)) return false;
    }while(temp->distanceTo(finish)> MAX_CHECK_DISTANCE);

    //already checked the finish, so it doesn't need to be checked
    pointIsValid(finish);//check again so you can see it on pic

    return true;
}

QGraphicsScene* Environment::getScene()
{
    return &scene;
}

bool Environment::pointIsValid(SearchNode *other)
{
    if(other==NULL) return false;
    current->setPos(other->x(),other->y());
    current->setRotation(other->theta());
    return scene.collidingItems(current).size() == 0;
}
