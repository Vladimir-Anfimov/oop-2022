#include "Mercedes.h"

Mercedes::Mercedes() : Car(56.3, 8.3) {
    this->average_speed[(int) Weather::Rain]  = 34;
    this->average_speed[(int) Weather::Snow]  = 19;
    this->average_speed[(int) Weather::Sunny] = 47;
}

const char* Mercedes::getName() {
    return "Mercedes";
}

double Mercedes::getFuelCapacity() {
    return this->fuel_capacity;
}

double Mercedes::getFuelConsumption() {
    return this->fuel_consumption;
}

double Mercedes::getAverageSpeed(Weather weather) {
    return this->average_speed[(int)weather];
}
