#ifndef LABORATOR_09_MAPITERATOR_H
#define LABORATOR_09_MAPITERATOR_H
#include "Pair.h"

template <class T1, class T2>
class ExtendedPair {
public:
    T1 key;
    T2 value;
    int index;
};


template <class T1, class T2>
class MapIterator {
public:
    Pair<T1, T2> *pairs;
    int index;
    MapIterator();
    MapIterator<T1, T2>& operator++();
    bool operator!=(MapIterator<T1,T2> &it);
    ExtendedPair<T1,T2> operator*();
};

template<class T1, class T2>
MapIterator<T1, T2>& MapIterator<T1, T2>::operator++() {
    pairs++;
    index++;
    return *this;
}

template<class T1, class T2>
MapIterator<T1, T2>::MapIterator() {
    index = 0;
}

template<class T1, class T2>
bool MapIterator<T1, T2>::operator!=(MapIterator<T1,T2> &it) {
    return it.pairs != this->pairs;
}

template<class T1, class T2>
ExtendedPair<T1,T2> MapIterator<T1, T2>::operator*() {
    return ExtendedPair{pairs->key, pairs->value, index};
}

#endif