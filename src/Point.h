#ifndef DA_1_POINT_H
#define DA_1_POINT_H


#include <iostream>
#include <string>
using namespace std;

class Point {
private:
    unsigned int id;
    string code;
public:
    Point(unsigned int id, string code);
    string getCode();
    unsigned int getId();
};

#endif //DA_1_POINT_H
