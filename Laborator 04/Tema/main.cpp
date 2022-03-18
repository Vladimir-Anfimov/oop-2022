#include <iostream>
#include <ctime>
#include "Sort.h"

int main()
{   
    srand((unsigned) time(nullptr));
    
    Sort S1("10,40,100,5,70");
    S1.InsertSort(); // default descrescator
    S1.Print();

    int v[5] = { 1, 2, 3, 4, 5 };
    Sort S2(v, 5);
    S2.BubbleSort(true); // crescator
    S2.Print();

    Sort S3({ 9, 200, 100, 300, 600, 500, 400, 700, 800, 900 });
    S3.QuickSort(); // default descrescator
    S3.Print();

    Sort S4(7, -50, 100);
    S4.QuickSort(true); // crescator
    S4.Print();

    std::cout << S4.GetElementsCount() << "\n";
    std::cout << S4.GetElementFromIndex(3) << "\n";
    

}