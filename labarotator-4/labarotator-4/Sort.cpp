#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <cstdarg>

Sort::Sort(int numar_elemente, int min_val, int max_val)
{
    this->count = numar_elemente;
    this->elements = new int[this->count];
    for (int i = 0; i < this->count; i++)
    {
        this->elements[i] = min_val + rand() % (max_val - min_val + 1);
    }
}

Sort::Sort(std::initializer_list<int> lista)
{
    this->count = lista.size();
    this->elements = new int[this->count];
    int index = 0;
    for (int valoare : lista)
    {
        this->elements[index] = valoare;
        index++;
    }
}

Sort::Sort(int* vector, int numar_elemente)
{
    this->count = numar_elemente;
    this->elements = new int[this->count];
    for (int i = 0; i < this->count; i++)
    {
        this->elements[i] = vector[i];
    }
}

Sort::Sort(int numar_elemente, ...)
{
    this->count = numar_elemente;
    this->elements = new int[this->count];

    va_list argumente;
    va_start(argumente, numar_elemente);

    for (int i = 0; i < this->count; i++)
    {
        this->elements[i] = va_arg(argumente, int);
    }

    va_end(argumente);
}

Sort::Sort(const char* text)
{
    int virgule = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ',')
        {
            virgule++;
        }
    }

    this->count = virgule + 1;
    this->elements = new int[this->count];

    int numar_curent = 0;
    int index = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ',')
        {
            this->elements[index] = numar_curent;
            index++;
            numar_curent = 0;
        }
        else
        {
            numar_curent = numar_curent * 10 + (text[i] - '0');
        }
    }
    this->elements[index] = numar_curent;
}

Sort::~Sort()
{
    delete[] this->elements;
}

void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < this->count; i++)
    {
        int key = this->elements[i];
        int j = i - 1;

        if (ascendent)
        {
            while (j >= 0 && this->elements[j] > key)
            {
                this->elements[j + 1] = this->elements[j];
                j = j - 1;
            }
        }
        else
        {
            while (j >= 0 && this->elements[j] < key)
            {
                this->elements[j + 1] = this->elements[j];
                j = j - 1;
            }
        }
        this->elements[j + 1] = key;
    }
}

void Sort::BubbleSort(bool ascendent)
{
    bool modificat;
    do
    {
        modificat = false;
        for (int i = 0; i < this->count - 1; i++)
        {
            bool trebuie_schimbat = false;
            if (ascendent)
            {
                if (this->elements[i] > this->elements[i + 1])
                {
                    trebuie_schimbat = true;
                }
            }
            else
            {
                if (this->elements[i] < this->elements[i + 1])
                {
                    trebuie_schimbat = true;
                }
            }

            if (trebuie_schimbat)
            {
                int temp = this->elements[i];
                this->elements[i] = this->elements[i + 1];
                this->elements[i + 1] = temp;
                modificat = true;
            }
        }
    } while (modificat);
}

int Sort::Partition(int low, int high, bool ascendent)
{
    int pivot = this->elements[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        bool conditie = false;
        if (ascendent)
        {
            if (this->elements[j] < pivot)
            {
                conditie = true;
            }
        }
        else
        {
            if (this->elements[j] > pivot)
            {
                conditie = true;
            }
        }

        if (conditie)
        {
            i++;
            int temp = this->elements[i];
            this->elements[i] = this->elements[j];
            this->elements[j] = temp;
        }
    }
    int temp = this->elements[i + 1];
    this->elements[i + 1] = this->elements[high];
    this->elements[high] = temp;

    return i + 1;
}

void Sort::QuickSortHelper(int low, int high, bool ascendent)
{
    if (low < high)
    {
        int pi = Partition(low, high, ascendent);
        QuickSortHelper(low, pi - 1, ascendent);
        QuickSortHelper(pi + 1, high, ascendent);
    }
}

void Sort::QuickSort(bool ascendent)
{
    QuickSortHelper(0, this->count - 1, ascendent);
}

void Sort::Print()
{
    for (int i = 0; i < this->count; i++)
    {
        std::cout << this->elements[i] << " ";
    }
    std::cout << "\n";
}

int Sort::GetElementsCount()
{
    return this->count;
}

int Sort::GetElementFromIndex(int index)
{
    if (index >= 0 && index < this->count)
    {
        return this->elements[index];
    }
    return -1;
}