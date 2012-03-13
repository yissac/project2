#ifndef RRTSEARCH_H
#define RRTSEARCH_H
#include "searchnode.h"
#include "environment.h"
#include <list>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <ctime>


#include <cstdio>
using namespace std;

class RRTSearch
{
public:
    RRTSearch(float startX,float startY,float startTheta,
              float endX,float endY,float endTheta);
    SearchNode *findNearestNeighbor(SearchNode *other);

    //returns null if no point is added
    SearchNode* expandTreeTowards(SearchNode *other);

    //always adds one new node
    //returns true if new node finds goal
    bool expandTree();
    int numNodes();
    QGraphicsScene* getScene();
    QGraphicsScene* getTreeScene();
    int solve();
    SearchNode *showPredicessor();
    int getNumRandNodes(){return start->getNumRandNodes();}
private:
    SearchNode *start,*end;
    list<SearchNode*> searchTree;
    Environment env;
    QGraphicsScene searchTreeVisual;

};

#endif // RRTSEARCH_H
