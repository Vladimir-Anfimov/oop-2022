#pragma once
#include <corecrt_memory.h>
#include "Weather.h"
class Car
{
  protected:
    double fuel_capacity;
    double fuel_consumption;
    double* average_speed = new double[3];

  public:
    Car(double fuel_capacity, double fuel_consumption) : 
        fuel_capacity(fuel_capacity), fuel_consumption(fuel_consumption) {};

    virtual const char* getName()  = 0;
    virtual double getFuelCapacity() = 0;
    virtual double getFuelConsumption() = 0; // per 100 kilometers
    virtual double getAverageSpeed(Weather weather) = 0;
};