#include "City.h"

City::City(string city, unsigned int id, string code, unsigned int demand, unsigned int population):
    city(city), Point(id, code), demand(demand), population(population){}

string City::getCity(){
    return this->city;
}

unsigned int City::getDemand(){
    return this->demand;
}

unsigned int City::getPopulation(){
    return this->population;
}