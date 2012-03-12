#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "searchnode.h"
#define MAX_CHECK_DISTANCE 10

class Environment
{
public:
    explicit Environment();
    bool pathIsValid(SearchNode* start, SearchNode* finish);
    bool pointIsValid(SearchNode* other);
    
    void initPosition(qreal,qreal,qreal);
    void goalPosition(qreal,qreal,qreal);

    QGraphicsScene *getScene();
signals:
    
public slots:

private:

    QGraphicsScene scene;
    QGraphicsRectItem *start;
    QGraphicsRectItem *end;
    QGraphicsRectItem *current;
    
};

#endif // ENVIRONMENT_H
