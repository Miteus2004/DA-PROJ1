#ifndef DA_1_MENU_H
#define DA_1_MENU_H

#include <iostream>
#include <string>
#include <iomanip>
#include "FileReader.h"
#include "../data_structures/Graph.h"

using namespace std;
class Menu {
private:
    FileReader data;
public:
    Menu();
    void run();
    void mainMenu();
    void MaxFlowMenu();
    void All_Cities();
    void SScity(string code);
    void Total();
    void VerifyFlow();
    void Reservoir_Failure(string code);
    void Station_Failure(string code);
    void Pipe_Failture(string code, string code_dest);
};


#endif //DA_1_MENU_H
