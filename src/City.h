#ifndef DA_1_CITY_H
#define DA_1_CITY_H

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
    City(string city, unsigned int id, string code, unsigned int demand, unsigned int population);
    string getCity();
    unsigned int getId();
    string getCode();
    unsigned int getDemand();
    unsigned int getPopulation();

    /*!
    * @brief Getter for the city's flow.
    * @returns Double with the city's flow.
    */
    double getMaxFlow() const;


    /*!
     * @brief Sets the value of the flow.
     * @param flow Double with the new city's flow.
     */
    void setMaxFlow(double flow);
};

#endif //DA_1_CITY_H
