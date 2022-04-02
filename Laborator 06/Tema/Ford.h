#pragma once
#include "Car.h"
#include "Weather.h"

class Ford : public Car {
  public:
    Ford();
    double getAverageSpeed(Weather) override;
    const char* getName() override;
    double getFuelCapacity() override;
    double getFuelConsumption() override;
};
