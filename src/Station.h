#ifndef DA_1_STATION_H
#define DA_1_STATION_H

/**
 * @brief Represents a station with various attributes.
 */

#include <iostream>
#include <string>
using namespace std;
class Station {
    unsigned int id;
    string code;
public:
public:
    /**
     * @brief Constructor for the Station class.
     * @param id identifier of the station.
     * @param code Unique code of the station.
     */
    Station(unsigned int id, string code);

    /**
     * @brief Getter for the station's unique identifier between stations.
     * @return Unsigned integer representing the station's identifier.
     */
    unsigned int getId();

    /**
     * @brief Getter for the station's unique code.
     * @return String representing the station's code.
     */
    string getCode();
};

#endif //DA_1_STATION_H
