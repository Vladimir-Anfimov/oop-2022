#include "Dacia.h"

Dacia::Dacia() : Car(56.3, 8.3) {
    this->average_speed[(int)Weather::Rain] = 78;
    this->average_speed[(int) Weather::Snow] = 45;
    this->average_speed[(int) Weather::Sunny] = 103;
}

const char* Dacia::getName() {
    return "Dacia";
}

double Dacia::getFuelCapacity() {
    return this->fuel_capacity;
}

double Dacia::getFuelConsumption() {
    return this->fuel_consumption;
}

double Dacia::getAverageSpeed(Weather weather) {
    return this->average_speed[(int)weather];
}
