#include "FileReader.h"

void FileReader::readReservoirs()
{
    std::ifstream file("../dataset/Reservoir.csv");

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
            Points[code] = reservoir;
            flow.addVertex(reservoir);
        }
    }
}

void FileReader::readStations()
{
    std::ifstream file("../dataset/Stations.csv");

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
            Points[code] = station;
            flow.addVertex(station);
        }
    }
}

void FileReader::readCities()
{
    std::ifstream file("../dataset/Cities.csv");

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

            auto city = new City(name, stoi(id),code, stoi(demand), stoi(population));

            cities[code] = city;
            Points[code] = city;
            flow.addVertex(city);
        }
    }
}


void FileReader::readPipes()
{
    std::ifstream file("../dataset/Pipes.csv");

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

            if (direction == "0")
                flow.addBidirectionalEdge(Points[source], Points[destination], stoi(capacity));
            else
                flow.addEdge(Points[source], Points[destination], stoi(capacity));
        }
    }
}
