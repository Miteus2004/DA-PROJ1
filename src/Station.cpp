#include "Station.h"

Station::Station(unsigned int id, string code) : id(id), code(code) {}

unsigned int Station::getId(){
    return this->id;
}
string Station::getCode(){
    return this->code;
}