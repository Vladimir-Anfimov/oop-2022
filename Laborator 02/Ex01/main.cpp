#define _CRT_SECURE_NO_WARNINGS
#include "NumberList.h"

int main()
{
    NumberList list = NumberList();
    list.Init();
    list.Add(5);
    list.Add(7);
    list.Add(2);
    list.Add(3);
    list.Add(1);
    list.Print();

    list.Sort();
    list.Print();

}