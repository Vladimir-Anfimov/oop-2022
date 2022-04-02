#include "Toyota.h"

Toyota::Toyota() : Car(56.3, 8.3) {
    this->average_speed[(int) Weather::Rain]  = 48;
    this->average_speed[(int) Weather::Snow]  = 87;
    this->average_speed[(int) Weather::Sunny] = 134;
}

const char* Toyota::getName() {
    return "Toyota";
}

double Toyota::getFuelCapacity() {
    return this->fuel_capacity;
}

double Toyota::getFuelConsumption() {
    return this->fuel_consumption;
}

double Toyota::getAverageSpeed(Weather weather) {
    return this->average_speed[(int)weather];
}
