#include "City.h"

City::City(string city, unsigned int id, string code, unsigned int demand, unsigned int population):
    city(city), id(id), code(code), demand(demand), population(population), flow(0){}

string City::getCity(){
    return this->city;
}

unsigned int City::getId(){
    return this->id;
}
string City::getCode(){
    return this->code;
}

unsigned int City::getDemand(){
    return this->demand;
}

unsigned int City::getPopulation(){
    return this->population;
}

double  City::getMaxFlow() const {
    return this->flow;
}

void  City::setMaxFlow(double flow) {
    this->flow = flow;
}