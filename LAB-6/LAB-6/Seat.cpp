#include "Seat.h"

int Seat::GetFuelCapacity() { return 45; }
int Seat::GetFuelConsumption() { return 5; }
int Seat::GetAverageSpeed(Weather weather)
{
    if (weather == Weather::Rain) return 80;
    if (weather == Weather::Sunny) return 110;
    if (weather == Weather::Snow) return 55;
    return 90;
}
const char* Seat::GetName() { return "Seat"; }