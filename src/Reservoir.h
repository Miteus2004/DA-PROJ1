#ifndef DA_1_RESERVOIR_H
#define DA_1_RESERVOIR_H

#include <iostream>
#include <string>

using namespace std;
class Reservoir {
private:
    string reservoir;
    string municipality;
    unsigned int id;
    string code;
    unsigned int maxDelivery;

public:
    Reservoir(string reservoir, string municipality, unsigned int id, string code, unsigned int maxDelivery);
    string getReservoir();
    string getMunicipality();
    unsigned int getId();
    string getCode();
    unsigned int getMaxDelivery();
};


#endif //DA_1_RESERVOIR_H
