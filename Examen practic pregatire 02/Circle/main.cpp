#include <iostream>
#include "Circle.h"

using namespace std;

int main() {
	// Circle c; // ACEST COD NU VA COMPILA
    Circle c1 = { 10, 10, 10 };
    Circle c2 = { 15, 15, 2 };
    cout << "Puncte pe C1 = ";
    for (Punct p : c1)
        cout << "Punct(" << p.x << ", " << p.y << ") ";
    cout << endl;
    cout << "Puncte pe C2 = ";
    for (Punct p : c2)
        cout << "Punct(" << p.x << ", " << p.y << ") ";
    cout << endl;
    cout << "Punctul cu coordonatele (17,15) se gaseste pe c2: ";
    cout << boolalpha << (c2 == Punct{ 17, 15 }) << endl;

    cout << "Punctul cu coordonatele (16,15) se gaseste pe c2: ";
    cout << boolalpha << (c2 > Punct{ 16, 15 }) << endl;

    cout << "Punctul cu coordonatele (30,30) se gaseste pe c2: ";
    cout << boolalpha << (c2 > Punct{ 30, 30 }) << endl;

    cout << "Diametrul lui c1 = " << (int) c1 << endl;
    cout << "Diametrul lui c2 = " << (int) c2 << endl;

    Circle c3 = ((c2("add_to_x", 10))("add_to_y", -10))("add_to_ray", 3);
    cout << "si are raza: " << c3["ray"] << endl;
    return 0;



}
