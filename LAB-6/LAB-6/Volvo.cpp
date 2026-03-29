#include "Volvo.h"

int Volvo::GetFuelCapacity() { return 60; }
int Volvo::GetFuelConsumption() { return 6; }
int Volvo::GetAverageSpeed(Weather weather)
{
    if (weather == Weather::Rain) return 70;
    if (weather == Weather::Sunny) return 100;
    if (weather == Weather::Snow) return 50;
    return 80;
}
const char* Volvo::GetName() { return "Volvo"; }