#ifndef DA_1_CITY_H
#define DA_1_CITY_H

/**
 * @brief Represents a city with various attributes.
 */

#include <iostream>
#include <string>
using namespace std;
class City {
private:
    string city;
    unsigned int id;
    string code;
    unsigned int demand;
    unsigned int population;
    double flow;

public:
    /**
     * @brief Constructor for the City class.
     * @param city Name of the city.
     * @param id Unique identifier of the city.
     * @param code Unique code.
     * @param demand Demand of water by the city.
     * @param population Population of the city.
     */
    City(string city, unsigned int id, string code, unsigned int demand, unsigned int population);

    /**
     * @brief Getter for the city's name.
     * @return String representing the city's name.
     */
    string getCity();

    /**
     * @brief Getter for the city's unique identifier between cities.
     * @return Unsigned integer representing the city's identifier.
     */
    unsigned int getId();

    /**
     * @brief Getter for the city's unique identifier.
     * @return String representing the city's code.
     */
    string getCode();

    /**
     * @brief Getter for the city's demand.
     * @return Unsigned integer representing the city's water demand.
     */
    unsigned int getDemand();

    /**
     * @brief Getter for the city's population.
     * @return Unsigned integer representing the city's population.
     */
    unsigned int getPopulation();

    /**
     * @brief Getter for the city's flow.
     * @return Double representing the city's flow.
     */
    double getMaxFlow() const;

    /**
     * @brief Sets the value of the flow for the city.
     * @param flow Double representing the new city's flow.
     */
    void setMaxFlow(double flow);
};

#endif //DA_1_CITY_H
