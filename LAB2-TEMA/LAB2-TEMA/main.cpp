#include "NumberList.h"
#include <stdio.h>

int main()
{
    NumberList lista;
    lista.Init();

    lista.Add(20);
    lista.Add(5);
    lista.Add(1);
    lista.Add(8);

    lista.Sort();
    lista.Print();

    return 0;
}