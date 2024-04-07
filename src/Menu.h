#ifndef DA_1_MENU_H
#define DA_1_MENU_H

#include <iostream>
#include <string>
#include <iomanip>
#include "FileReader.h"
#include "../data_structures/Graph.h"

/**
 * @brief A class representing a menu for interacting with the system.
 *
 * Menu class provides options to perform various tasks related to the system,
 * such as finding maximum water flow, verifying water supply, handling network failures, etc.
 */
using namespace std;
class Menu {
private:
    FileReader data;
public:
    /**
    * @brief Default constructor for Menu.
    */
    Menu();

    /**
     * @brief Run the menu.
     * @details Reads data, sets up the system, and displays the main menu.
     */
    void run();

    /**
     * @brief Display the main menu.
     * @details Provides options for different operations such as finding maximum flow, verifying water supply, etc.
     */
    void mainMenu();

    /**
     * @brief Display the menu for finding maximum water flow.
     * @details Provides options to select specific cities, view all cities, or view total flow.
     */
    void MaxFlowMenu();

    /**
     * @brief Display information about the flow of all cities.
     * @param code The code of the city to display information about.
     * @complexity O(n) where n equals the number of cities.
     */
    void All_Cities();

    /**
     * @brief Display information about the flow of the city selected.
     * @complexity O(1).
     */
    void SScity(string code);

    /**
     * @brief Display the total flow of all cities.
     * @complexity O(n) where n equals the number of cities.
     */
    void Total();

    /**
     * @brief Verify water supply to each city and the deficit with the demand.
     * @complexity O(n) where n equals the number of cities.
     */
    void VerifyFlow();

    /**
     * @brief Simulate reservoir failure and display its impact.
     * @param code The code of the reservoir that failed.
     * @complexity  O(V * E^2) where V equals the number of vertexes and E the number of edges in the graph.
     */
    void Reservoir_Failure(string code);

    /**
     * @brief Simulate station failure and display its impact.
     * @param code The code of the station that failed.
     * @complexity  O(V * E^2) where V equals the number of vertexes and E the number of edges in the graph.
     */
    void Station_Failure(string code);

    /**
     * @brief Simulate pipe failure and display its impact.
     * @param code The source code of the pipe that failed.
     * @param code_dest The destination code of the pipe that failed.
     * @complexity  O(V * E^2) where V equals the number of vertexes and E the number of edges in the graph.
     */
    void Pipe_Failture(string code, string code_dest);
};


#endif //DA_1_MENU_H
