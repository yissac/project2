#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <vector>
#include <map>
#include "feeder.hpp"
#include "heuristic.hpp"
#include "node.hpp"
#include "edge.hpp"
#include "observable.hpp"

class Search : public Observable
{
public:

    Search();
    Search(Feeder*);

    virtual Node* runSearch() = 0;

    void newSearch();
    void initializeSearchWithFeeder(Feeder*);
    void initInitNode(int);
    void initGoalNode(int);
    void initHeuristic(Heuristic*);
    std::vector<Node*> getFrontier();
    std::vector<Node*> getExploredSet();

protected:

    Node* popFrontier();
    void  addNodeToFrontier(Node*);
    void  addNodeToExploredSet(Node*);
    bool  goalTest(Node*);
    bool  isNodeInExploredSet(Node*);
    int   isNodeInFrontier(Node*);

    int numberOfNodesInFrontier;
    int numberOfNodesInExploredSet;
    int initNodeID;
    int goalNodeID;
    Feeder* feeder;
    Heuristic* heuristic;
    std::vector <Node*> openSet;
    std::vector <Node*> closedSet;
    std::map <int,double> g_score;
    std::map <int,double> h_score;
    std::map <int,double> f_score;
};

#endif // SEARCH_HPP
