#include "astargraphsearch.hpp"

AStarGraphSearch::AStarGraphSearch() : Search()
{
}

AStarGraphSearch::AStarGraphSearch(Feeder* inFeeder) : Search(inFeeder)
{
}

Node* AStarGraphSearch::runSearch()
{
    // Declare Variables
    bool  goalFound;
    Node* current;
    Node* start = feeder->getNode(initNodeID);

    g_score[initNodeID] = 0;
    h_score[initNodeID] = heuristic->evaluateHeuristic(start);
    f_score[initNodeID] = g_score[initNodeID] + h_score[initNodeID];

    addNodeToFrontier(start);

    while (numberOfNodesInFrontier > 0)
    {
        current = popFrontier(); /*---- GUI UPDATE ----*/ notifyObservers(current->getNodeID(),NODE_UPDATE);

        goalFound = goalTest(current);
        if (goalFound)
            break;

        addNodeToExploredSet(current);

        std::vector <Node*> nodeSuccessors;
        std::vector <Edge*> edgeSuccessors;
        feeder->getSuccessors(current,&edgeSuccessors);
        int numberOfSuccessors = edgeSuccessors.size();
        nodeSuccessors.resize(numberOfSuccessors);
        for (int i=0; i<numberOfSuccessors; i++)
        {
            nodeSuccessors[i] = edgeSuccessors[i]->getTarget(); /*---- GUI UPDATE ----*/ notifyObservers(edgeSuccessors[i]->getEdgeID(),EDGE_UPDATE);

            if (isNodeInExploredSet(nodeSuccessors[i]))
                continue;

            int currentID = current->getNodeID();
            bool tentative_is_better;
            double tentative_g_score = g_score[currentID] + edgeSuccessors[i]->getCost();
            int neigbourID = nodeSuccessors[i]->getNodeID();

            if (!isNodeInFrontier(nodeSuccessors[i]))
            {
                h_score[neigbourID] = heuristic->evaluateHeuristic(nodeSuccessors[i]);
                addNodeToFrontier(nodeSuccessors[i]);
                tentative_is_better = true;
            }
            else if (tentative_g_score < g_score[neigbourID])
                tentative_is_better = true;
            else
                tentative_is_better = false;

            if (tentative_is_better)
            {
                nodeSuccessors[i]->setParent(current);
                g_score[neigbourID] = tentative_g_score;
                f_score[neigbourID] = g_score[neigbourID] + h_score[neigbourID];
            }
        }
    }

    if (goalFound)
        return current;
    else
        return NULL;
}
