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

/**
 * @brief A class responsible for reading data from files and setting up a graph for the Edmonds-Karp algorithm.
 *
 * FileReader reads data from CSV files containing information about reservoirs, stations, cities, and pipes.
 * It constructs a graph representing the network and sets it up for finding the maximum flow using the Edmonds-Karp algorithm.
 */

class FileReader {
private:
    unordered_map<string, Reservoir*> reservoirs;
    unordered_map<string, Station*> stations;
    unordered_map<string, City*> cities;
    Graph<string> grafo;
public:
    /**
     * @brief Default constructor for FileReader.
     */
    FileReader();

    /**
     * @brief Read reservoir data from a CSV file.
     * @details Reads reservoir data from a CSV file and constructs Reservoir objects.
     * @complexity O(n).
     */
    void readReservoirs();

    /**
     * @brief Read station data from a CSV file.
     * @details Reads station data from a CSV file and constructs Station objects.
     * @complexity O(n).
     */
    void readStations();

    /**
     * @brief Read city data from a CSV file.
     * @details Reads city data from a CSV file and constructs City objects.
     * @complexity O(n).
     */
    void readCities();

    /**
     * @brief Read pipe data from a CSV file.
     * @details Reads pipe data from a CSV file and constructs edges in the graph.
     * @complexity O(n).
     */
    void readPipes();

    /**
    * @brief Read all data from CSV files.
    * @details Calls all read functions to read data from respective files.
    * @complexity O(n).
    */
    void read();

    /**
     * @brief Get the map of reservoirs.
     * @return An unordered_map containing reservoir objects.
     */
    unordered_map<string, Reservoir*> getReservoirs();

    /**
     * @brief Get the map of stations.
     * @return An unordered_map containing station objects.
     */
    unordered_map<string, Station*> getStations();

    /**
     * @brief Get the map of cities.
     * @return An unordered_map containing city objects.
     */
    unordered_map<string, City*> getCities();

    /**
     * @brief Get the graph representing the network.
     * @return A Graph object representing the network.
     */
    Graph<string> getGrafo();

    /**
    * @brief Set up the graph for the Edmonds-Karp algorithm.
    * @details Sets up the graph for finding the maximum flow using the Edmonds-Karp algorithm.
    * Constructs main source and main target vertices, adds edges, calculates maximum flow,
    * and writes the output to a CSV file.
    * @complexity O(V * E^2) where V equals the number of vertexes and E the number of edges in the graph.
    */
    void Setup();
};

#endif //DA_1_FILEREADER_H
