#pragma once

#include <initializer_list>

class Sort {
    int* vector;
    int size;

    int partition(int low, int high, bool ascending);
    void quick_sort(int low, int high, bool ascending);

  public:
    Sort(int size, int min, int max);

    Sort(std::initializer_list<int> list);

    Sort(const int* vector, int size);

    Sort(int size, ...);

    Sort(const char* string);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int GetElementsCount();

    int GetElementFromIndex(int index);
};
