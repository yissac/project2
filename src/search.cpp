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
    openSet.push_back(inNode);
    numberOfNodesInFrontier++;
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

    int index = 0;
    double min_f_score = f_score[index];
    for (int i=0;i<numberOfNodesInFrontier;i++)
    {
        double current_f_score = f_score[openSet[i]->getNodeID()];
        if (current_f_score < min_f_score)
        {
            min_f_score = current_f_score;
            index = i;
        }
    }
    Node* nodeToReturn = openSet[index];

    openSet.erase(openSet.begin() + index);
    numberOfNodesInFrontier--;

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

int Search::isNodeInFrontier(Node* inNode)
{
    // return -1 if node is not in frontier
    // return position in openSet if node is in frontier

    for (int i=0;i<numberOfNodesInFrontier;i++)
    {
        if (inNode == openSet[i])
        {
            return i;
        }
    }

    return -1;
}
