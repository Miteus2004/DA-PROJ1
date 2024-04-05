#ifndef DA_1_CITY_H
#define DA_1_CITY_H

#include <iostream>
#include <string>
#include "Point.h"
using namespace std;
class City : public Point {
private:
    string city;
    unsigned int demand;
    unsigned int population;

public:
    City(string city, unsigned int id, string code, unsigned int demand, unsigned int population);
    string getCity();
    unsigned int getDemand();
    unsigned int getPopulation();
};

#endif //DA_1_CITY_H
