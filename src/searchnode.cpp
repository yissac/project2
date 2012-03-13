#include "searchnode.h"

bool SearchNode::seedSet = false;
int SearchNode::numberRandNodes = 0;

SearchNode::SearchNode(float x, float y, float theta, SearchNode* parent)
{
    this->xVal = x;
    this->yVal = y;
    this->thetaVal = theta;
    while(thetaVal >= 360)thetaVal -=360;
    while(thetaVal < 0) thetaVal += 360;
    this->parent = parent;
    if(parent != NULL) stepSize = parent->stepSize;
    else               stepSize = 10;

}

SearchNode::SearchNode(unsigned int randSeed)
{
    if(!seedSet)
    {
        seedSet = true;
        srand(randSeed);
    }
    numberRandNodes++;
    this->xVal = X_BASE + (X_RANGE* rand()/RAND_MAX);
    this->yVal = Y_BASE + (Y_RANGE* rand()/RAND_MAX);
    this->thetaVal = 360*rand()/RAND_MAX;
    while(thetaVal >= 360)thetaVal -=360;
    while(thetaVal < 0) thetaVal += 360;
    this->parent = NULL;
}


SearchNode* SearchNode::expandTowards(SearchNode* dest)
{

    float dx,dy,dtheta,mag;
    dx = dest->x() - this->xVal;
    dy = dest->y() - this->yVal;
    dtheta = dest->theta() - this->thetaVal;
    mag = distanceTo(dest);
    if(mag < stepSize)
    {
        return new SearchNode(dest->x(),dest->y(),dest->theta(),this);
    }
    else
    {
        return new SearchNode(this->xVal + (stepSize*dx/mag),
                        this->yVal + (stepSize*dy/mag),
                        this->thetaVal + (stepSize*dtheta/mag), this);
    }
}

float SearchNode::distanceTo(SearchNode* other)
{
    float dx,dy,dtheta;
    dx = other->x() - this->xVal;
    dy = other->y() - this->yVal;
    dtheta = other->theta() - this->thetaVal;
    return sqrt(dx*dx + dy*dy + dtheta*dtheta);
}

void SearchNode::cutStepSize()
{
    stepSize/=2;
}

void SearchNode::increaseStepSize()
{
    stepSize+=10;
}

SearchNode* SearchNode::getParent(void)
{
    return this->parent;
}
