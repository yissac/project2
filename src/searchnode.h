#ifndef SEARCHNODE_H
#define SEARCHNODE_H

#define X_RANGE 1000
#define X_BASE -500
#define Y_RANGE 1000
#define Y_BASE -500
#define CONST_STEPSIZE
#include <stdlib.h>
#include <list>
#include <math.h>

class SearchNode
{
public:
    SearchNode(float x, float y, float theta, SearchNode *parent = NULL);
    SearchNode(unsigned int randSeed = 0);
    SearchNode* expandTowards(SearchNode* dest);
    float distanceTo(SearchNode* other);
    SearchNode* getParent(void);
    float x(void){return xVal;}
    float y(void){return yVal;}
    float theta(void){return thetaVal;}


    void cutStepSize();
    void increaseStepSize();

    SearchNode* parent;
    int getNumRandNodes(){return numberRandNodes;}
private:
    static int numberRandNodes;
    float xVal,yVal,thetaVal;
    float stepSize;
    static bool seedSet;


};

#endif // SEARCHNODE_H
