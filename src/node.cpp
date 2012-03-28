#include "node.hpp"

Node::Node()
{
    parentNode = NULL;
    explored = false;
}

Node::Node(int inNodeID)
{
    nodeID = inNodeID;
    parentNode = NULL;
    explored = false;
}

void Node::addSuccessor(Edge *e)
{
    successors.push_back(e);
}

std::vector<Edge*>* Node::getSuccessors()
{
    return &successors;
}


int Node::getNodeID()
{
    return nodeID;
}

bool Node::isExplored(){

    return explored;
}

void Node::setExplored(bool a){

    explored = a;
}

void Node::setNodeID(int inID)
{
    nodeID = inID;
}

void Node::setNodeType(NodeType inType)
{
    type = inType;
}

void Node::setParent(Node* inParentNode)
{
    parentNode = inParentNode;
}
