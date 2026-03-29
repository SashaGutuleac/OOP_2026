#pragma once
#include "Car.h"

class Volvo : public Car
{
public:
    int GetFuelCapacity() override;
    int GetFuelConsumption() override;
    int GetAverageSpeed(Weather weather) override;
    const char* GetName() override;
};