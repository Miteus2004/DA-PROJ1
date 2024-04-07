#ifndef DA_1_PIPE_H
#define DA_1_PIPE_H

/**
 * @brief Represents a pipe with various attributes.
 */

#include <iostream>
#include <string>
using namespace std;
class Pipe {
private:
    string spa;
    string spb;
    unsigned int capacity;
    bool direction;

public:
    /**
     * @brief Constructor for the Pipe class.
     * @param spa Starting point A of the pipe.
     * @param spb Ending point B of the pipe.
     * @param capacity Capacity of the pipe.
     * @param direction If the flow that goes through the pipe only go one direction or both ways.
     */
    Pipe(string spa, string spb, unsigned int capacity, bool direction);

    /**
     * @brief Getter for the starting point A of the pipe.
     * @return String representing the starting point A.
     */
    string getSrc();

    /**
     * @brief Getter for the ending point B of the pipe.
     * @return String representing the ending point B.
     */
    string getDest();

    /**
     * @brief Getter for the capacity of the pipe.
     * @return Unsigned integer representing the capacity of the pipe.
     */
    unsigned int getCapacity();

    /**
     * @brief Getter for the direction of the flow through the pipe.
     * @return Boolean indicating the direction of the flow (true for only going A to B, false for also going B to A).
     */
    bool getDirection();
};

#endif //DA_1_PIPE_H
