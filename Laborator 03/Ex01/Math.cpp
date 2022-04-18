#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <iostream>
#include <cstring>

int Math::Add(int x, int y) {
    return x+y;
}

int Math::Add(int x, int y, int z) {
    return x+y+z;
}

int Math::Add(double x, double y) {
    return x+y;
}

int Math::Add(double x, double y, double z) {
    return x + y + z;
}

int Math::Mul(int x, int y) {
    return x * y;
}

int Math::Mul(int x, int y, int z) {
    return x * y * z;
}

int Math::Mul(double x, double y) {
    return x * y;
}

int Math::Mul(double x, double y, double z) {
    return x * y * z;
}

int Math::Add(int count, ...) {
    int sum = 0;
    int* p  = &count;
    for (int i=0;i<count;i++) {
        p = p + 2;
        sum += *p;
    }
    return sum;
}

char* Math::Add(const char* x, const char* y) {
    int len = (x == nullptr ? 0 : strlen(x)) + (y == nullptr ? 0 : strlen(y)) + 1;
    char* z = new char[len];
    strcpy(z, "");
    if (x != nullptr) strcat(z, x);
    if (y != nullptr) strcat(z, y);

    z[len] = '\0';
    return z;
}
