#ifndef DA_1_RESERVOIR_H
#define DA_1_RESERVOIR_H

#include <iostream>
#include <string>

/**
 * @brief Represents a reservoir with various attributes.
 */

using namespace std;
class Reservoir {
private:
    string reservoir;
    string municipality;
    unsigned int id;
    string code;
    unsigned int maxDelivery;

public:
    /**
     * @brief Constructor for the Reservoir class.
     * @param reservoir Name of the reservoir.
     * @param municipality Municipality where the reservoir is located.
     * @param id Unique identifier of the reservoir.
     * @param code Unique ode of the reservoir.
     * @param maxDelivery Maximum delivery capacity of the reservoir.
     */
    Reservoir(string reservoir, string municipality, unsigned int id, string code, unsigned int maxDelivery);

    /**
     * @brief Getter for the reservoir's name.
     * @return String representing the reservoir's name.
     */
    string getReservoir();

    /**
     * @brief Getter for the municipality where the reservoir is located.
     * @return String representing the municipality.
     */
    string getMunicipality();

    /**
     * @brief Getter for the reservoir's unique identifier between reservoirs.
     * @return Unsigned integer representing the reservoir's unique identifier.
     */
    unsigned int getId();

    /**
     * @brief Getter for the reservoir's unique code.
     * @return String representing the reservoir's code.
     */
    string getCode();

    /**
     * @brief Getter for the maximum delivery capacity of the reservoir.
     * @return Unsigned integer representing the maximum delivery capacity.
     */
    unsigned int getMaxDelivery();
};


#endif //DA_1_RESERVOIR_H
