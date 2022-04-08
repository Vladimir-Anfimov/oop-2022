#include <iostream>
#include "Vector.h"
#include <cstring>

template <typename T>
inline bool callbackSortFunc(T obj1, T obj2) {
    return obj1 < obj2;
}

inline bool INT_callbackFirstIndexOf(int obj1, int obj2) {
    return obj1 % 10 == obj2 % 10;
}

inline bool STR_callbackFirstIndexOf(std::string obj1, std::string obj2) {
    return obj1[1] == obj2[1] && obj1 != obj2;
}

int main()
{
    Vector<int> vecInt;
    Vector<char> vecChar;

    for (int i = 0; i < 10; i++) {
        vecChar.push(char('A' + i));
        vecInt.push(i);
    }

    vecChar.print();

    std::cout << vecInt.pop() << "\n";

    vecInt.remove(3);

    for (int i=0;i<4;i++)
        vecInt.pop();


    vecInt.insert(3, -1);

    vecInt.print();

    int X = vecInt.get(2);
    std::cout << "Ref vector: " << X << std::endl;
    
    vecInt.set(1, 20);

    vecInt.sort(callbackSortFunc);
    
    vecInt.insert(5, 303);


    vecInt.print();

    std::cout<<vecInt.count()<<std::endl;


    std::cout << vecInt.firstIndexOf(13, INT_callbackFirstIndexOf) << std::endl;


    Vector<std::string> vecStr;
    vecStr.push("Vladimir");
    vecStr.push("George");
    vecStr.push("Alina");
    
    vecStr.sort();

    std::cout << vecStr.firstIndexOf(vecStr.get(0), STR_callbackFirstIndexOf) << "\n";

    vecStr.print();

    std::cout << "\n";


    Vector<bool> vecResize;

    int actual_size = vecResize.getAllocatedSize();
    for (int i=1;i<=50; i++) {
        vecResize.push(true);
        if (actual_size != vecResize.getAllocatedSize()) {
            printf("Pentru a introduce al %i-lea element am crescut spatiul alocat de la %d la %d.\n", 
                i, actual_size, vecResize.getAllocatedSize() );
            actual_size = vecResize.getAllocatedSize();
        }
    }


    return 0;
}