#include "search.hpp"

Search::Search()
{
    numberOfNodesInFrontier    = 0;
    numberOfNodesInExploredSet = 0;
}

Search::Search(Feeder* inFeeder)
{
    numberOfNodesInFrontier    = 0;
    numberOfNodesInExploredSet = 0;
    feeder = inFeeder;
}

void Search::initializeSearchWithFeeder(Feeder* inFeeder)
{
    newSearch();
    feeder = inFeeder;
}

void Search::newSearch()
{
    g_score.clear();
    h_score.clear();
    f_score.clear();
    openSet.clear();
    closedSet.clear();
    numberOfNodesInFrontier = 0;
    numberOfNodesInExploredSet = 0;
}

void Search::initInitNode(int inInitNodeID)
{
    initNodeID = inInitNodeID;
}

void Search::initGoalNode(int inGoalNodeID)
{
    goalNodeID = inGoalNodeID;
}

void Search::initHeuristic(Heuristic* inHeuristic)
{
    heuristic = inHeuristic;
}

void Search::addNodeToFrontier(Node* inNode)
{
    // If frontier is empty
    if (numberOfNodesInFrontier == 0)
    {
        numberOfNodesInFrontier++;
        openSet.push_back(inNode);
        return;
    }

    // If frontier is not empty and inNode is the least f_score
    double inCost = f_score[inNode->getNodeID()];
    if (inCost < f_score[openSet[numberOfNodesInFrontier-1]->getNodeID()])
    {
        openSet.push_back(inNode);
        numberOfNodesInFrontier++;
        return;
    }

    // If frontier is not empty and inNode is not the least f_score
    for (int i=numberOfNodesInFrontier-2;i>-1;i--)
    {
        if (inCost < f_score[openSet[i]->getNodeID()])
        {
            openSet.insert(openSet.begin() + i + 1,inNode);
            numberOfNodesInFrontier++;
            return;
        }
    }
}

void Search::addNodeToExploredSet(Node* inNode)
{
    closedSet.push_back(inNode);
    numberOfNodesInExploredSet++;
}

bool Search::goalTest(Node* nodeToBeTested)
{
    if (goalNodeID == nodeToBeTested->getNodeID())
        return 1;
    else
        return 0;
}

std::vector <Node*> Search::getFrontier()
{
    return openSet;
}

std::vector <Node*> Search::getExploredSet()
{
    return closedSet;
}

Node* Search::popFrontier()
{
    if (numberOfNodesInFrontier == 0)
        return NULL;

    Node* nodeToReturn = openSet[numberOfNodesInFrontier-1];
    numberOfNodesInFrontier--;

    openSet.erase(openSet.end()-1);

    return nodeToReturn;
}

bool Search::isNodeInExploredSet (Node* inNode)
{
    for (int i=numberOfNodesInExploredSet-1; i>-1; i--)
    {
        if (inNode == closedSet[i])
        {
            return true;
        }
    }

    return false;
}

bool Search::isNodeInFrontier(Node* inNode)
{
    for (int i=0;i<numberOfNodesInFrontier;i++)
    {
        if (inNode == openSet[i])
        {
            return true;
        }
    }

    return false;
}
