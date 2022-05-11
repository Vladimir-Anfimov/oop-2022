#include <iostream>
#include "Map.h"

int main() {
    Map<int, const char *> m;

    m[10] = "C++";

    m[20] = "test";

    m[30] = "Poo";

    Map<int, const char *> t;
    t[10] = "C++";

    std::cout<<std::boolalpha<<m.Includes(t)<<"\n";

    for (auto[key, value, index] : m)

    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }

    m[20] = "result";

    for (auto[key, value, index] : m)

    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }

    return 0;

}
