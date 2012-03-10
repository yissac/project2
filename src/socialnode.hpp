#ifndef SOCIALNODE_HPP
#define SOCIALNODE_HPP

#include "node.hpp"

#include "node.hpp"
#include "edge.hpp"
#include <vector>

class SocialNode : public Node
{
public:
    SocialNode(int id_);

    void addFriend(Edge *);


    std::vector<Edge*>* getFriends();

    operator int(){return SOCIAL_NODE;}

private:
    std::vector<Edge*> friends;
};


#endif // SOCIALNODE_HPP
