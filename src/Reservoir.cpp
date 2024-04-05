#include "Reservoir.h"

Reservoir::Reservoir(string reservoir, string municipality, unsigned int id, string code, unsigned int maxDelivery):
    reservoir(reservoir), municipality(municipality), Point(id, code), maxDelivery(maxDelivery) {}
string Reservoir::getReservoir(){
    return this->reservoir;
}

string Reservoir::getMunicipality(){
    return this->municipality;
}

unsigned int Reservoir::getMaxDelivery(){
    return this->maxDelivery;
}
