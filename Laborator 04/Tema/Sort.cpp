#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstdarg>
#include <string.h>
#include <iostream>

int Sort::partition(int low, int high, bool ascending) {
    int pivot = low + rand() % (high - low);
    std::swap(vector[low], vector[pivot]);
    int i = low + 1, j = high;

    while (i <= j) 
    {
        if (ascending && vector[i] <= vector[low] || !ascending && vector[i] >= vector[low]) 
        {
            i++;
        }
        if (ascending && vector[j] >= vector[low] || !ascending && vector[j] <= vector[low]) 
        {
            j--;
        }

        if (i < j && (ascending && vector[i] > vector[low] && vector[j] < vector[low] ||
            !ascending && vector[i] < vector[low] && vector[j] > vector[low])) 
        {
            std::swap(vector[i], vector[j]);
            i++;
            j--;
        } 
    }
    std::swap(vector[i - 1], vector[low]);
    return i - 1;
}

void Sort::quick_sort(int low, int high, bool ascending) {
    if (low < high) {
        int k = this->partition(low, high, ascending);
        this->quick_sort(low, k - 1, ascending);
        this->quick_sort(k + 1, high, ascending);
    }
}

Sort::Sort(int size, int min, int max) : size(size) {
    this->vector = new int[size];
    for (int i = 0; i < size; i++)
        this->vector[i] = min + 1 + rand() % (max - min - 1);
}

Sort::Sort(std::initializer_list<int> list) {
    this->size = list.size();
    this->vector = new int[list.size()];
    std::initializer_list<int>::iterator it = list.begin();
    for (int i = 0; i < list.size();i++) {
        this->vector[i] = *it;
        it++;
    }
}

Sort::Sort(const int* vector, int size) : size(size) {
    this->vector = new int[size];
    for (int i = 0; i < size; i++)
        this->vector[i] = vector[i];
}

// ACEST CONSTRUCTOR ESTE COMENTAT PENTRU CA EXISTA ALT CONSTRUCTOR MAI SUS 
// CE PRIMESTE CA PARAMETRU std::initializer_list<int> SI ESTE MEREU APELAT 

//Sort::Sort(int size, ...) : size(size) {
//    this->vector = new int[size];
//    va_list args;
//    va_start(args, size);
//    for (int i = 0; i < size; i++)
//        this->vector[i] = va_arg(args, int);
//    va_end(args);
//}

Sort::Sort(const char* string) : size(0) {
    
    for (int i = 0; i < strlen(string);i++) {
        if (string[i] == ',')
            this->size++;
    }

    if (strlen(string) > 0) {
        this->size++;
    }

    this->vector = new int[this->size];
    char* buffer = new char[strlen(string) + 1];
    strcpy(buffer, string);

    int index = 0;
    const char* number = strtok(buffer, ",");

    while (number != nullptr) {
        this->vector[index++] = atoi(number);
        number = strtok(nullptr, ",");
    }

    delete[] buffer;
}

void Sort::InsertSort(bool ascendent) {
    for (int i=1;i<this->size;i++) {
        int j = i - 1;
        int temp = vector[i];
        while (ascendent && j >= 0 && vector[j] > temp) {
            vector[j + 1] = vector[j];
            j--;
        }
        while (!ascendent && j >= 0 && vector[j] < temp) {
            vector[j + 1] = vector[j];
            j--;
        }
        if (temp != vector[j + 1])
            vector[j + 1] = temp;
    }
}

void Sort::QuickSort(bool ascendent) {
    this->quick_sort(0, this->size - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent) {
    int last = this->size - 1;
    while (last > 0) {
        int n = last;
        last  = 0;
        for (int i=0; i<n; i++) {
            if (ascendent && vector[i] > vector[i + 1] || !ascendent && vector[i] < vector[i + 1]) {
                std::swap(vector[i], vector[i + 1]);
                last = i;
            }
        }
    }
}

void Sort::Print() {
    for (int i = 0;i < this->size; i++)
        printf("%d ", this->vector[i]);
    printf("\n");
}

int Sort::GetElementsCount() {
    return this->size;
}

int Sort::GetElementFromIndex(int index) {
    if (0 <= index && index < this->size)
        return this->vector[index];
}
