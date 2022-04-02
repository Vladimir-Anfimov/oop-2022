#include "Circuit.h"
#include <iostream>


Circuit::Circuit() : length(100), weather(Weather::Sunny) {
}

void Circuit::SetLength(double length) {
    this->length = length;
}

void Circuit::SetWeather(Weather weather) {
    this->weather = weather;
}

bool Circuit::AddCar(Car* car) {
    if (size == this->MAX_SIZE) {
        return false;
    }
    this->cars[size++] = car;
}

void Circuit::Race() {
    for (int i=0;i<size-1;i++) {
        for (int j=i+1;j<size;j++) {
            if (cars[i]->getAverageSpeed(weather) > cars[j]->getAverageSpeed(weather)) {
                std::swap(cars[i], cars[j]);
            }
        }
    }
}

void Circuit::ShowFinalRanks() {
    for (int i=0;i<size;i++) {
        if (cars[i]->getFuelCapacity() >= (cars[i]->getFuelConsumption() * length) / 100)
            std::cout << cars[i]->getName() << "\n";
    }
    std::cout << '\n';
}

void Circuit::ShowWhoDidNotFinish() {
    for (int i = 0; i < size; i++) {
        if (cars[i]->getFuelCapacity() < (cars[i]->getFuelConsumption() * length) / 100)
            std::cout << cars[i]->getName() << "\n";
    }
    std::cout << '\n';
}
