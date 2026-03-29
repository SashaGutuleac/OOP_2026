#include "Circuit.h"
#include <iostream>

Circuit::Circuit()
{
    this->carsCount = 0;
    this->finishedCount = 0;
    this->notFinishedCount = 0;
    this->length = 100;
    this->weather = Weather::Sunny;
}

Circuit::~Circuit()
{
    for (int i = 0; i < this->carsCount; i++)
    {
        delete this->cars[i];
    }
}

void Circuit::SetLength(int length) { this->length = length; }
void Circuit::SetWeather(Weather weather) { this->weather = weather; }

void Circuit::AddCar(Car* car)
{
    if (this->carsCount < 20)
    {
        this->cars[this->carsCount] = car;
        this->carsCount++;
    }
}

void Circuit::Race()
{
    this->finishedCount = 0;
    this->notFinishedCount = 0;

    for (int i = 0; i < this->carsCount; i++)
    {
        int speed = this->cars[i]->GetAverageSpeed(this->weather);
        int capacity = this->cars[i]->GetFuelCapacity();
        int consumption = this->cars[i]->GetFuelConsumption();

        float fuelNeeded = ((float)this->length / 100.0f) * consumption;

        if (fuelNeeded <= capacity)
        {
            this->finishedCars[this->finishedCount] = this->cars[i];
            this->finishedTimes[this->finishedCount] = (float)this->length / speed;
            this->finishedCount++;
        }
        else
        {
            this->notFinishedCars[this->notFinishedCount] = this->cars[i];
            this->notFinishedCount++;
        }
    }

    for (int i = 0; i < this->finishedCount - 1; i++)
    {
        for (int j = i + 1; j < this->finishedCount; j++)
        {
            if (this->finishedTimes[i] > this->finishedTimes[j])
            {
                float tempTime = this->finishedTimes[i];
                this->finishedTimes[i] = this->finishedTimes[j];
                this->finishedTimes[j] = tempTime;

                Car* tempCar = this->finishedCars[i];
                this->finishedCars[i] = this->finishedCars[j];
                this->finishedCars[j] = tempCar;
            }
        }
    }
}

void Circuit::ShowFinalRanks()
{
    std::cout << "--- FINAL RANKS ---\n";
    for (int i = 0; i < this->finishedCount; i++)
    {
        std::cout << this->finishedCars[i]->GetName() << " - Time: " << this->finishedTimes[i] << " hours\n";
    }
}

void Circuit::ShowWhoDidNotFinish()
{
    std::cout << "--- DID NOT FINISH (Out of fuel) ---\n";
    for (int i = 0; i < this->notFinishedCount; i++)
    {
        std::cout << this->notFinishedCars[i]->GetName() << "\n";
    }
}