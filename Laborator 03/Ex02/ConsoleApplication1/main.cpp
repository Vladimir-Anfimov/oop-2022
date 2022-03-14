#include <iostream>
#include "Canvas.h"

int main()
{
    Canvas C = Canvas(30, 30);
    C.DrawRect(1, 1, 4, 3, '#');
    C.FillRect(5, 5, 7, 20, '*');
    C.DrawCircle(10, 13, 4, '*');
    C.FillCircle(20, 20, 6, '*');
    C.Print();
    //C.Clear();
}
