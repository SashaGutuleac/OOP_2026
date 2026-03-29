#include "Fiat.h"

int Fiat::GetFuelCapacity() { return 10; } 
int Fiat::GetFuelConsumption() { return 12; } 
int Fiat::GetAverageSpeed(Weather weather)
{
    if (weather == Weather::Rain) return 60;
    if (weather == Weather::Sunny) return 90;
    if (weather == Weather::Snow) return 45;
    return 70;
}
const char* Fiat::GetName() { return "Fiat"; }