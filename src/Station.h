#ifndef DA_1_STATION_H
#define DA_1_STATION_H

#include <iostream>
#include <string>
#include "Point.h"
using namespace std;
class Station : public Point {
public:
    Station(unsigned int id, string code);
};

#endif //DA_1_STATION_H
