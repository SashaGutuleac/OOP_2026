#include "RangeRover.h"

int RangeRover::GetFuelCapacity() { return 80; }
int RangeRover::GetFuelConsumption() { return 15; }
int RangeRover::GetAverageSpeed(Weather weather)
{
    if (weather == Weather::Rain) return 80;
    if (weather == Weather::Sunny) return 120;
    if (weather == Weather::Snow) return 70;
    return 90;
}
const char* RangeRover::GetName() { return "RangeRover"; }