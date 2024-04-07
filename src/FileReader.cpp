#include "FileReader.h"
#include "Edmondskarp.h"
FileReader::FileReader() {};

void FileReader::readReservoirs() {
    std::ifstream file("../Project1DataSetSmall/Reservoirs_Madeira.csv");

    if(!file.is_open())
    {
        cout << "Error opening file Reservoir" << endl;
    }
    else
    {
        string line;
        getline(file,line);

        while(getline(file,line))
        {
            string name, municipality, id, code, maxDelivery;
            stringstream ss(line);

            getline(ss, name, ',');
            getline(ss, municipality, ',');
            getline(ss, id, ',');
            getline(ss, code, ',');
            getline(ss, maxDelivery, '\r');

            auto reservoir = new Reservoir(name, municipality, stoi(id), code, stoi(maxDelivery));

            reservoirs[code] = reservoir;
            grafo.addVertex(reservoir->getCode());
        }
    }
}

void FileReader::readStations()
{
    std::ifstream file("../Project1DataSetSmall/Stations_Madeira.csv");

    if(!file.is_open())
    {
        cout << "Error opening file Stations" << endl;
    }
    else
    {
        string line;
        getline(file,line);

        while(getline(file,line))
        {
            string id, code;
            stringstream ss(line);

            getline(ss, id, ',');
            getline(ss, code, '\r');

            auto station = new Station(stoi(id),code);

            stations[code] = station;
            grafo.addVertex(station->getCode());
        }
    }
}

void FileReader::readCities() {
    std::ifstream file("../Project1DataSetSmall/Cities_Madeira.csv");

    if(!file.is_open())
    {
        cout << "Error opening file Cities" << endl;
    }
    else
    {
        string line;
        getline(file,line);

        while(getline(file,line))
        {
            string name, id, code, demand, population;
            stringstream ss(line);

            getline(ss, name, ',');
            getline(ss, id, ',');
            getline(ss, code, ',');
            getline(ss, demand, ',');
            getline(ss, population, '\r');

            auto city = new City(name, stoi(id), code, stoi(demand), stoi(population));

            cities[code] = city;
            grafo.addVertex(city->getCode());
        }
    }
}


void FileReader::readPipes() {
    std::ifstream file("../Project1DataSetSmall/Pipes_Madeira.csv");

    if(!file.is_open())
    {
        cout << "Error opening file Pipes" << endl;
    }
    else
    {
        string line;
        getline(file, line);

        while(getline(file, line))
        {
            string source, destination, capacity, direction;
            stringstream ss(line);

            getline(ss, source, ',');
            getline(ss, destination, ',');
            getline(ss, capacity, ',');
            getline(ss, direction, '\r');

            grafo.addEdge(source, destination, stoi(capacity));
            if (direction == "0")
                grafo.addEdge(destination, source, stoi(capacity));
        }
    }
}

void FileReader::read() {
    readStations();
    readCities();
    readReservoirs();
    readPipes();
}

unordered_map<string, Reservoir*> FileReader::getReservoirs() {
    return reservoirs;
}

unordered_map<string, Station*> FileReader::getStations() {
    return stations;
}

unordered_map<string, City*> FileReader::getCities() {
    return cities;
}

Graph<string> FileReader::getGrafo() {
    return grafo;
}

void FileReader::Setup() {
    Reservoir mainSourceCode("mainSource", "", 0, "mainSrc", 0);
    City mainTargetCode ("mainTarget",0,"mainTarg",0,0);
    grafo.addVertex(mainSourceCode.getCode());
    grafo.addVertex(mainTargetCode.getCode());

    for (auto& wr : reservoirs) {
        auto it = grafo.findVertex(wr.first);
        grafo.addEdge(mainSourceCode.getCode(), wr.first, wr.second->getMaxDelivery());
    }
    for (auto& c : cities) {
        auto it = grafo.findVertex(c.first);
        grafo.addEdge(c.first, mainTargetCode.getCode(), c.second->getDemand());
    }
    edmondsKarp(grafo, mainSourceCode.getCode(), mainTargetCode.getCode());

    std::ofstream file("../DA-PROJ1/max_flow_output.csv", std::ios::trunc);
    std::ofstream file2("../DA-PROJ1/max_flow_output.csv", std::ios::app);
    file2 << setw(12) << "CityCode" << "," << "Max Flow" << std::endl;

    for (auto v : grafo.getVertexSet()){
        if (v->getInfo()[0] == 'm'){
            for (auto e : v->getIncoming()){
                cities.at(e->getOrig()->getInfo())->setMaxFlow(e->getFlow());
                file2 << e->getOrig()->getInfo() << "," << cities.at(e->getOrig()->getInfo())->getMaxFlow() << std::endl;
            }
        }
    }
}
