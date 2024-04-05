#include "Point.h"
Point::Point(unsigned int id, string code) : id(id), code(code) {}

string Point::getCode(){
    return this->code;
}

unsigned int Point::getId(){
    return this->id;
}