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
    scene.addEllipse(   0-100,   0-100,300,300);
    scene.addEllipse(   0-100,-300-100,300,300);
    scene.addEllipse(   0-100, 300-100,300,300);

    current = scene.addRect(-5,-50,10,100);
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
