#ifndef DA_1_FILEREADER_H
#define DA_1_FILEREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <string>
#include "../data_structures/Graph.h"
#include "Reservoir.h"
#include "Station.h"
#include "City.h"
#include "Pipe.h"
#include "Point.h"
using namespace std;

class FileReader {
private:
    unordered_map<string, Reservoir*> reservoirs;
    unordered_map<string, Station*> stations;
    unordered_map<string, City*> cities;
    unordered_map<string, Point*> Points;
    Graph<Point*> flow;

public:
    void readReservoirs();
    void readStations();
    void readCities();
    void readPipes();

};

#endif //DA_1_FILEREADER_H