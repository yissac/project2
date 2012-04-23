#include "heuristic.hpp"

Heuristic::Heuristic()
{
}

void Heuristic::initGoal(Node* inNode)
{
    goalNode = inNode;
}

double Heuristic::evaluateHeuristic(Node* inNodePrime)
{
    double h;

    double* pos      = ((MechanicalNode*)goalNode)->getPos();
    double* posPrime = ((MechanicalNode*)inNodePrime)->getPos();

    double deltaX = pos[0]-posPrime[0];
    double deltaY = pos[1]-posPrime[1];
    double deltaZ = pos[2]-posPrime[2];
    h = sqrt(deltaX*deltaX + deltaY*deltaY + deltaZ*deltaZ);

//    h = 0;
    return h;
}
