#ifndef DA_1_STATION_H
#define DA_1_STATION_H

#include <iostream>
#include <string>
using namespace std;
class Station {
    unsigned int id;
    string code;
public:
    Station(unsigned int id, string code);
    unsigned int getId();
    string getCode();
};

#endif //DA_1_STATION_H
