#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <string>

class Edge;

enum NodeType
{
    GENERIC,
    SOCIAL_NODE,
    MECHANICAL_NODE,
    ELECTRICAL_NODE
};

class Node
{
public:
    Node();
    Node(int id_);

    int  getNodeID();
    void setNodeID(int);
    void setNodeType(NodeType);
    void setParent(Node*);

    bool isExplored();
    void setExplored(bool a);

    void addSuccessor(Edge *);
    std::vector<Edge*>* getSuccessors();

    // change this shit
    Node* parentNode;
    int   nodeID;

protected:

    std::vector<Edge*> successors;// This is to be used with Offline nodes or to store succesors of online nodes

    bool explored;
    NodeType type;
};

#endif // NODE_HPP
