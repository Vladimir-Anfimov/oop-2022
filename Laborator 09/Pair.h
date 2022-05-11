#ifndef LABORATOR_09_PAIR_H
#define LABORATOR_09_PAIR_H

template <class T1, class T2>
class Pair {
public:
    T1 key;
    T2 value;
    Pair(){}
    Pair(T1 key, T2 value): key(key), value(value){}
};

#endif