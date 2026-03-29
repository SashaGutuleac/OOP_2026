#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit
{
    Car* cars[20];
    int carsCount;
    int length;
    Weather weather;

    Car* finishedCars[20];
    float finishedTimes[20];
    int finishedCount;

    Car* notFinishedCars[20];
    int notFinishedCount;

public:
    Circuit();
    ~Circuit();

    void SetLength(int length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};