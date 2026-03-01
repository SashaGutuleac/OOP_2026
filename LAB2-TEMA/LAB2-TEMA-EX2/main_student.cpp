#include <stdio.h>
#include "Student.h"
#include "Global.h"

int main()
{
    Student student1;
    student1.setNume("Andrei");
    student1.setNotaMate(9.5);
    student1.setNotaEngleza(8);
    student1.setNotaIstorie(10);

    Student student2;
    student2.setNume("Alex");
    student2.setNotaMate(7);
    student2.setNotaEngleza(9);
    student2.setNotaIstorie(8.5);

    printf("nume student 1: %s\n", student1.getNume());
    printf("medie student 1: %f\n", student1.getMedie());

    printf("nume student 2: %s\n", student2.getNume());
    printf("medie student 2: %f\n", student2.getMedie());

    int rez = comparaNume(student1, student2);
    printf("comparatie nume: %d\n", rez);

    rez = comparaNotaMate(student1, student2);
    printf("comparatie mate: %d\n", rez);

    rez = comparaMedie(student1, student2);
    printf("comparatie medie: %d\n", rez);

    return 0;
}