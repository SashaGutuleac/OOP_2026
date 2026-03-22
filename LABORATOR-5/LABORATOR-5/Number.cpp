#include "Number.h"
#include <cstring>
#include <cstdio>

int CharToInt(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return 0;
}

char IntToChar(int n)
{
    if (n >= 0 && n <= 9) return n + '0';
    if (n >= 10 && n <= 15) return n - 10 + 'A';
    return '0';
}

int GetBase10(const char* val, int b)
{
    int rez = 0;
    for (int i = 0; val[i] != '\0'; i++)
    {
        rez = rez * b + CharToInt(val[i]);
    }
    return rez;
}

void ConvertToString(int val, int b, char* buffer)
{
    if (val == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }
    int index = 0;
    while (val > 0)
    {
        buffer[index] = IntToChar(val % b);
        val = val / b;
        index++;
    }
    buffer[index] = '\0';

    for (int i = 0; i < index / 2; i++)
    {
        char temp = buffer[i];
        buffer[i] = buffer[index - 1 - i];
        buffer[index - 1 - i] = temp;
    }
}

Number::Number(const char* val, int b)
{
    this->base = b;
    this->value = new char[strlen(val) + 1];
    memcpy(this->value, val, strlen(val) + 1);
}

Number::Number(int val)
{
    this->base = 10;
    char buffer[100];
    ConvertToString(val, 10, buffer);
    this->value = new char[strlen(buffer) + 1];
    memcpy(this->value, buffer, strlen(buffer) + 1);
}

Number::~Number()
{
    delete[] this->value;
}

Number::Number(const Number& other)
{
    this->base = other.base;
    this->value = new char[strlen(other.value) + 1];
    memcpy(this->value, other.value, strlen(other.value) + 1);
}

Number::Number(Number&& other)
{
    this->base = other.base;
    this->value = other.value;
    other.value = nullptr;
}

Number& Number::operator=(const Number& other)
{
    if (this == &other) return *this;
    delete[] this->value;
    this->base = other.base;
    this->value = new char[strlen(other.value) + 1];
    memcpy(this->value, other.value, strlen(other.value) + 1);
    return *this;
}

Number& Number::operator=(Number&& other)
{
    if (this == &other) return *this;
    delete[] this->value;
    this->base = other.base;
    this->value = other.value;
    other.value = nullptr;
    return *this;
}

Number& Number::operator=(int val)
{
    char buffer[100];
    ConvertToString(val, this->base, buffer);
    delete[] this->value;
    this->value = new char[strlen(buffer) + 1];
    memcpy(this->value, buffer, strlen(buffer) + 1);
    return *this;
}

Number& Number::operator=(const char* val)
{
    delete[] this->value;
    this->value = new char[strlen(val) + 1];
    memcpy(this->value, val, strlen(val) + 1);
    return *this;
}

Number operator+(const Number& n1, const Number& n2)
{
    int val1 = GetBase10(n1.value, n1.base);
    int val2 = GetBase10(n2.value, n2.base);
    int suma = val1 + val2;
    int maxBase = n1.base > n2.base ? n1.base : n2.base;

    char buffer[100];
    ConvertToString(suma, maxBase, buffer);
    return Number(buffer, maxBase);
}

Number operator-(const Number& n1, const Number& n2)
{
    int val1 = GetBase10(n1.value, n1.base);
    int val2 = GetBase10(n2.value, n2.base);
    int dif = val1 - val2;
    if (dif < 0) dif = 0;
    int maxBase = n1.base > n2.base ? n1.base : n2.base;

    char buffer[100];
    ConvertToString(dif, maxBase, buffer);
    return Number(buffer, maxBase);
}

Number& Number::operator+=(const Number& other)
{
    int val1 = GetBase10(this->value, this->base);
    int val2 = GetBase10(other.value, other.base);
    int suma = val1 + val2;

    int maxBase = this->base > other.base ? this->base : other.base;
    this->base = maxBase;

    char buffer[100];
    ConvertToString(suma, this->base, buffer);
    delete[] this->value;
    this->value = new char[strlen(buffer) + 1];
    memcpy(this->value, buffer, strlen(buffer) + 1);

    return *this;
}

Number& Number::operator--()
{
    int len = strlen(this->value);
    if (len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            this->value[i] = this->value[i + 1];
        }
    }
    return *this;
}

Number Number::operator--(int)
{
    Number copie(*this);
    int len = strlen(this->value);
    if (len > 0)
    {
        this->value[len - 1] = '\0';
    }
    return copie;
}

char Number::operator[](int index)
{
    if (index >= 0 && index < strlen(this->value))
    {
        return this->value[index];
    }
    return '\0';
}

bool Number::operator>(const Number& other)
{
    return GetBase10(this->value, this->base) > GetBase10(other.value, other.base);
}

bool Number::operator<(const Number& other)
{
    return GetBase10(this->value, this->base) < GetBase10(other.value, other.base);
}

bool Number::operator>=(const Number& other)
{
    return GetBase10(this->value, this->base) >= GetBase10(other.value, other.base);
}

bool Number::operator<=(const Number& other)
{
    return GetBase10(this->value, this->base) <= GetBase10(other.value, other.base);
}

bool Number::operator==(const Number& other)
{
    return GetBase10(this->value, this->base) == GetBase10(other.value, other.base);
}

bool Number::operator!=(const Number& other)
{
    return GetBase10(this->value, this->base) != GetBase10(other.value, other.base);
}

void Number::SwitchBase(int newBase)
{
    int val10 = GetBase10(this->value, this->base);
    char buffer[100];
    ConvertToString(val10, newBase, buffer);

    delete[] this->value;
    this->value = new char[strlen(buffer) + 1];
    memcpy(this->value, buffer, strlen(buffer) + 1);
    this->base = newBase;
}

void Number::Print()
{
    printf("%s\n", this->value);
}

int Number::GetDigitsCount()
{
    return strlen(this->value);
}

int Number::GetBase()
{
    return this->base;
}