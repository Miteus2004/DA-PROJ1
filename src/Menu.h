#ifndef DA_1_MENU_H
#define DA_1_MENU_H

#include <iostream>
#include "FileReader.h"
#include "../data_structures/Graph.h"

using namespace std;
class Menu {
private:
    unordered_map<string, Reservoir*> reservoirs;
    unordered_map<string, Station*> stations;
    unordered_map<string, City*> cities;
    unordered_map<string, Point*> Points;
    Graph<Point> grafo;
public:
    Menu();
    void run();
    void mainMenu();
    void MaxFlowMenu();
    void All_Cities();
    void SScity();


};


#endif //DA_1_MENU_H
