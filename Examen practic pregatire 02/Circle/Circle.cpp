#include "Circle.h"
#include <math.h>

Circle::Circle(int x, int y, int raza) : raza(raza), centru(x, y) {
}

CercInterator Circle::begin() {
    patrat[0] = { centru.x, centru.y - raza };
    patrat[1] = { centru.x + raza, centru.y };
    patrat[2] = { centru.x, centru.y + raza };
    patrat[3] = { centru.x - raza, centru.y };
    CercInterator tmp;
    tmp.it = &patrat[0];
    return tmp;
}

CercInterator Circle::end() {
    CercInterator tmp;
    tmp.it = &patrat[4];
    return tmp;
}

bool Circle::operator==(const Punct& punct) {
    return pow((centru.x - punct.x), 2) + pow((centru.y - punct.y), 2) <= pow(raza, 2);
}

bool Circle::operator>(const Punct& punct) {
    return this->operator==(punct);
}

Circle::operator int() {
    return raza * 2;
}

Circle Circle::operator()(const std::string add, int val) {
    if (add == "add_to_x") return { centru.x + val, centru.y, raza };
    if (add == "add_to_y") return { centru.x, centru.y + val, raza };
    if (add == "add_to_ray") return { centru.x, centru.y, raza + val };
    throw "Invalid add";
}

int Circle::operator[](const std::string str) {
    if (str == "x")
        return centru.x;
    if (str == "y")
        return centru.y;
    if (str == "ray")
        return raza;
    throw "Invalid information";
}
