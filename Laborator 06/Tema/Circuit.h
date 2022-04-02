#pragma once

#include "Weather.h"
#include "Car.h"

class Circuit {
    
    const static int MAX_SIZE = 100;

    double length;
    Weather weather;
    Car* cars[100];
    int size = 0;

  public:
    Circuit();
    void SetLength(double length);
    void SetWeather(Weather weather);
    bool AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};
