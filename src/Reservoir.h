#ifndef DA_1_RESERVOIR_H
#define DA_1_RESERVOIR_H

#include <iostream>
#include <string>
#include "Point.h"

using namespace std;
class Reservoir : public Point{
private:
    string reservoir;
    string municipality;
    unsigned int maxDelivery;

public:
    Reservoir(string reservoir, string municipality, unsigned int id, string code, unsigned int maxDelivery);
    string getReservoir();
    string getMunicipality();
    unsigned int getMaxDelivery();
};


#endif //DA_1_RESERVOIR_H
