#include "Student.h"
#include <cstring>

void Student::setNume(const char* numeInput)
{
    this->nume = new char[strlen(numeInput) + 1];
    memcpy(this->nume, numeInput, strlen(numeInput) + 1);
}

const char* Student::getNume()
{
    return this->nume;
}

void Student::setNotaMate(float nota)
{
    this->notaMate = nota;
}

float Student::getNotaMate()
{
    return this->notaMate;
}

void Student::setNotaEngleza(float nota)
{
    this->notaEngleza = nota;
}

float Student::getNotaEngleza()
{
    return this->notaEngleza;
}

void Student::setNotaIstorie(float nota)
{
    this->notaIstorie = nota;
}

float Student::getNotaIstorie()
{
    return this->notaIstorie;
}

float Student::getMedie()
{
    float suma = this->notaMate + this->notaEngleza + this->notaIstorie;
    return suma / 3.0f;
}