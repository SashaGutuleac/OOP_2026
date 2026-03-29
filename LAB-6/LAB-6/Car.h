#pragma once
#include "Weather.h"

class Car
{
public:
    virtual ~Car() = default;

    virtual int GetFuelCapacity() = 0;
    virtual int GetFuelConsumption() = 0;
    virtual int GetAverageSpeed(Weather weather) = 0;
    virtual const char* GetName() = 0;
};