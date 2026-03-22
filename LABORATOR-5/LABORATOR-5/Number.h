#pragma once

class Number
{
    char* value;
    int base;

public:
    Number(const char* value, int base);
    Number(int value);
    ~Number();

    Number(const Number& other);
    Number(Number&& other);

    Number& operator=(const Number& other);
    Number& operator=(Number&& other);
    Number& operator=(int val);
    Number& operator=(const char* val);

    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);
    Number& operator+=(const Number& other);

    Number& operator--();
    Number operator--(int);

    char operator[](int index);

    bool operator>(const Number& other);
    bool operator<(const Number& other);
    bool operator>=(const Number& other);
    bool operator<=(const Number& other);
    bool operator==(const Number& other);
    bool operator!=(const Number& other);

    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount();
    int GetBase();
};