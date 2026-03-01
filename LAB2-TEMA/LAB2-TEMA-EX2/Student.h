#pragma once

class Student
{
    char* nume;
    float notaMate;
    float notaEngleza;
    float notaIstorie;

public:
    void setNume(const char* numeInput);
    const char* getNume();

    void setNotaMate(float nota);
    float getNotaMate();

    void setNotaEngleza(float nota);
    float getNotaEngleza();

    void setNotaIstorie(float nota);
    float getNotaIstorie();

    float getMedie();
};