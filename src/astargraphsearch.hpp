#ifndef ASTARGRAPHSEARCH_HPP
#define ASTARGRAPHSEARCH_HPP

#include <vector>
#include <map>
#include "search.hpp"
#include "feeder.hpp"

#include <iostream>
#include <stdlib.h>

class AStarGraphSearch : public Search
{
public:
    AStarGraphSearch();
    AStarGraphSearch(Feeder*);

    Node* runSearch();

protected:
};

#endif // ASTARGRAPHSEARCH_HPP
