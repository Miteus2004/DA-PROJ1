#include "Pipe.h"

Pipe::Pipe(string spa, string spb, unsigned int capacity, bool direction):
    spa(spa), spb(spb), capacity(capacity), direction(direction) {}

string Pipe::getSrc() {
    return this->spa;
}

string Pipe::getDest()  {
    return this->spb;
}

unsigned int Pipe::getCapacity() {
    return this->capacity;
}

bool Pipe::getDirection() {
    return this->direction;
}
