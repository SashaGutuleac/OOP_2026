#include "Global.h"
#include <cstring>

int comparaNume(Student s1, Student s2)
{
    int rezultat = strcmp(s1.getNume(), s2.getNume());

    if (rezultat == 0)
    {
        return 0;
    }
    if (rezultat > 0)
    {
        return 1;
    }
    return -1;
}

int comparaNotaMate(Student s1, Student s2)
{
    if (s1.getNotaMate() == s2.getNotaMate())
    {
        return 0;
    }
    if (s1.getNotaMate() > s2.getNotaMate())
    {
        return 1;
    }
    return -1;
}

int comparaNotaEngleza(Student s1, Student s2)
{
    if (s1.getNotaEngleza() == s2.getNotaEngleza())
    {
        return 0;
    }
    if (s1.getNotaEngleza() > s2.getNotaEngleza())
    {
        return 1;
    }
    return -1;
}

int comparaNotaIstorie(Student s1, Student s2)
{
    if (s1.getNotaIstorie() == s2.getNotaIstorie())
    {
        return 0;
    }
    if (s1.getNotaIstorie() > s2.getNotaIstorie())
    {
        return 1;
    }
    return -1;
}

int comparaMedie(Student s1, Student s2)
{
    if (s1.getMedie() == s2.getMedie())
    {
        return 0;
    }
    if (s1.getMedie() > s2.getMedie())
    {
        return 1;
    }
    return -1;
}