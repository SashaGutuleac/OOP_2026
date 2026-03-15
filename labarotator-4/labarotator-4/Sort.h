#pragma once
#include <initializer_list>

class Sort
{
    int* elements;
    int count;

    void QuickSortHelper(int low, int high, bool ascendent);
    int Partition(int low, int high, bool ascendent);

public:
    Sort(int numar_elemente, int min_val, int max_val);
    Sort(std::initializer_list<int> lista);
    Sort(int* vector, int numar_elemente);
    Sort(int numar_elemente, ...);
    Sort(const char* text);

    ~Sort();

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};