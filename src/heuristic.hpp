#ifndef HEURISTIC_HPP
#define HEURISTIC_HPP

#include "node.hpp"
#include "edge.hpp"

#include <cmath>
#include "mechanicalnode.hpp"

class Heuristic
{
public:
    Heuristic();

    void initGoal(Node*);
    double evaluateHeuristic(Node*);

private:
    Node* goalNode;
};

#endif // HEURISTIC_HPP
