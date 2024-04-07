#ifndef DA_1_FILEREADER_H
#define DA_1_FILEREADER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <map>
#include <string>
#include "../data_structures/Graph.h"
#include "Reservoir.h"
#include "Station.h"
#include "City.h"
#include "Pipe.h"
using namespace std;

class FileReader {
private:
    unordered_map<string, Reservoir*> reservoirs;
    unordered_map<string, Station*> stations;
    unordered_map<string, City*> cities;
    Graph<string> grafo;
public:
    FileReader();
    void readReservoirs();
    void readStations();
    void readCities();
    void readPipes();
    void read();
    unordered_map<string, Reservoir*> getReservoirs();
    unordered_map<string, Station*> getStations();
    unordered_map<string, City*> getCities();
    Graph<string> getGrafo();
    void Setup();
};

#endif //DA_1_FILEREADER_H
