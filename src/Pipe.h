#ifndef DA_1_PIPE_H
#define DA_1_PIPE_H

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
    Pipe(string spa, string spb, unsigned int capacity, bool direction);
    string getSrc();
    string getDest();
    unsigned int getCapacity();
    bool getDirection();
};

#endif //DA_1_PIPE_H
