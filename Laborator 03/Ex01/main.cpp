#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Math.h"

int main() {
    printf("%d \n", Math::Add(1, 2));
    printf("%d \n", Math::Add(1, 2, 3));
    printf("%d \n", Math::Add(1.5, 2.5));
    printf("%d \n", Math::Add(1.5, 2.5, 1.5));
    
    printf("%d \n\n", Math::Mul(2, 3));
    printf("%d \n", Math::Mul(2, 3, 4));
    printf("%d \n", Math::Mul(2.5, 10.2));
    printf("%d \n", Math::Mul(2.5, 10.2, 9.5));

    printf("%d \n\n", Math::Add(4, 1, 2, 3, 4));

    printf("%s\n", Math::Add("hello", "test"));

    printf("%s\n", Math::Add(nullptr, "a"));

    printf("%s\n", Math::Add("b", nullptr));

    if(Math::Add(nullptr, nullptr) != nullptr)
        printf("%s\n", Math::Add(nullptr, nullptr));
}