#include "Literals.h"
#include <cstdlib>

float operator"" _Kelvin(const char* k) {
    float kelvin_value = std::atof(k);
    return kelvin_value - 273.15f;
}

float operator"" _Fahrenheit(const char* f) {
    float fahrenheit_value = std::atof(f);
    return (fahrenheit_value - 32.0f) * 5.0f / 9.0f;
}