#include "rrtsearch.h"
RRTSearch::RRTSearch(float startX, float startY, float startTheta,
                     float endX,   float endY,   float endTheta)
{
    start = new SearchNode(startX,startY, startTheta);
    end = new SearchNode(endX, endY, endTheta);
    searchTree.push_back(start);
    searchTreeVisual.addEllipse(startX-2,startY-2,4,4,QPen(Qt::green));
    searchTreeVisual.addEllipse(endX-2,endY-2,4,4,QPen(Qt::red));
    searchTreeVisual.addLine(X_BASE        ,Y_BASE        ,X_BASE+X_RANGE,Y_BASE        );
    searchTreeVisual.addLine(X_BASE        ,Y_BASE+Y_RANGE,X_BASE+X_RANGE,Y_BASE+Y_RANGE);
    searchTreeVisual.addLine(X_BASE        ,Y_BASE        ,X_BASE        ,Y_BASE+Y_RANGE);
    searchTreeVisual.addLine(X_BASE+X_RANGE,Y_BASE        ,X_BASE+X_RANGE,Y_BASE+Y_RANGE);

    env.initPosition(startX,startY,startTheta);
}

SearchNode* RRTSearch::findNearestNeighbor(SearchNode* other)
{
    SearchNode* nearestNeighbor = start;
    float minDist = 1000000,newDist;

    //linear search for nearest neighbor
    for(list<SearchNode*>::iterator itr = searchTree.begin();
        itr != searchTree.end();
        itr++)
    {
        newDist = (*itr)->distanceTo(other);
        if(newDist < minDist)
        {
            nearestNeighbor = *itr;
            minDist = newDist;
        }
    }
    return nearestNeighbor;
}

QGraphicsScene* RRTSearch::getScene()
{
    return env.getScene();
}
QGraphicsScene* RRTSearch::getTreeScene()
{
    return &searchTreeVisual;
}

SearchNode *RRTSearch::expandTreeTowards(SearchNode* other)
{
    SearchNode* nearestNeighbor = findNearestNeighbor(other);
    SearchNode* newPoint = nearestNeighbor->expandTowards(other);
    if(env.pathIsValid(nearestNeighbor,newPoint))
    {
        nearestNeighbor->increaseStepSize();
        newPoint->increaseStepSize();
        searchTree.push_back(newPoint);
        return newPoint;
    }
    else
    {
        nearestNeighbor->cutStepSize();
        return NULL;
    }
}

int RRTSearch::numNodes()
{
    return searchTree.size();
}

bool RRTSearch::expandTree()
{
    static unsigned int numNodesTried = 0;
    SearchNode* newPoint = NULL;
    while(newPoint ==  NULL)
    {
        if(numNodesTried++ %20 == 0)
        {
            newPoint  = expandTreeTowards(end);
        }
        else
            newPoint = expandTreeTowards(new SearchNode());
    }

    searchTreeVisual.addEllipse(newPoint->x()-2,newPoint->y()-2,4,4,QPen(Qt::blue));
    searchTreeVisual.addLine(newPoint->x(),newPoint->y(),newPoint->parent->x(),newPoint->parent->y(),QPen(Qt::blue));

    return newPoint->distanceTo(end) < 30;
}

void RRTSearch::solve()
{
    while(!expandTree());
}
