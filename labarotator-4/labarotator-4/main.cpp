#include "Sort.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(NULL));

    Sort lista1(5, 10, 50);
    std::cout << "Constructor random: \n";
    lista1.Print();
    lista1.BubbleSort(true);
    lista1.Print();
    std::cout << "\n";

    Sort lista2({ 8, 3, 15, 2, 9 });
    std::cout << "Constructor initializer_list: \n";
    lista2.Print();
    lista2.InsertSort(false);
    lista2.Print();
    std::cout << "\n";

    int vec[4] = { 100, 20, 50, 10 };
    Sort lista3(vec, 4);
    std::cout << "Constructor din vector existent: \n";
    lista3.Print();
    lista3.QuickSort(true);
    lista3.Print();
    std::cout << "\n";

    Sort lista4(6, 11, 22, 33, 44, 55, 66);
    std::cout << "Constructor cu parametri variadici: \n";
    lista4.Print();
    lista4.BubbleSort(false);
    lista4.Print();
    std::cout << "\n";

    Sort lista5("10,40,100,5,70");
    std::cout << "Constructor din string: \n";
    lista5.Print();
    lista5.QuickSort(false);
    lista5.Print();

    return 0;
}