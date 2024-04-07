#include "Reservoir.h"

Reservoir::Reservoir(string reservoir, string municipality, unsigned int id, string code, unsigned int maxDelivery):
    reservoir(reservoir), municipality(municipality), id(id), code(code), maxDelivery(maxDelivery) {}
string Reservoir::getReservoir(){
    return this->reservoir;
}

string Reservoir::getMunicipality(){
    return this->municipality;
}

unsigned int Reservoir::getId(){
    return this->id;
}
string Reservoir::getCode(){
    return this->code;
}

unsigned int Reservoir::getMaxDelivery(){
    return this->maxDelivery;
}
