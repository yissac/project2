#include <QtGui/QApplication>
#include "mainwindow.h"
#include "astargraphsearch.hpp"
#include "offlinefeeder.hpp"
#include "socialnode.hpp"
#include "simulator.hpp"

#include <iostream>
#include <map>

#define GUI_DISPLAY 1

int main(int argc, char *argv[])
{
//    int k = 4;
//    std::vector <int> test;
//    test.push_back(5);

//    if (k < test[0])
//    {
//        test.insert(test.begin() + 0 + 1, k);
//    }

//    std::cout << test[0] << "\t" << test[1] << std::endl;



#if GUI_DISPLAY == 1

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();

#else

//    RRTSearch search(-400,0,45,
//                      400,0,90);
//    search.solve();



    // Declare Variables
//    Heuristic heur;
//    OfflineFeeder<MechanicalNode> feeder("../resources/mechgraph2.xml");
//    AStarGraphSearch search(&feeder);

//    // Initialize Uninitialized Variables
//    search.initInitNode(12);
//    search.initGoalNode(16);
//    search.initHeuristic(&heur);

//    // Run the algorithm
//    Node* solution = search.runSearch();

//    if (solution == NULL)
//        std::cout << "No path from start to goal node exists" << std::endl;
//    else
//    {
//        for (Node* i=solution; i!=NULL; i=i->parentNode)
//            std::cout << i->nodeID << " : " << i->getCurrentCost() <<  std::endl;
//    }

//    // Cleanup and preperation to exit program
//    return 0;

#endif
}
