#pragma once
#include "Car.h"
#include "Weather.h"

class Mercedes : public Car {
  public:
    Mercedes();
    double getAverageSpeed(Weather) override;
    const char* getName() override;
    double getFuelCapacity() override;
    double getFuelConsumption() override;
};
