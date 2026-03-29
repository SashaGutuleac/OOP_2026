#include "BMW.h"

int BMW::GetFuelCapacity() { return 70; }
int BMW::GetFuelConsumption() { return 8; }
int BMW::GetAverageSpeed(Weather weather)
{
    if (weather == Weather::Rain) return 90;
    if (weather == Weather::Sunny) return 130;
    if (weather == Weather::Snow) return 60;
    return 100;
}
const char* BMW::GetName() { return "BMW"; }