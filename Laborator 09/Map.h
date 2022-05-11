#ifndef LABORATOR_09_MAP_H
#define LABORATOR_09_MAP_H
#include "Pair.h"
#include "MapIterator.h"


template <class T1, class T2>
class Map {
    const static int DEFAULT_CAPACITY = 2;
    int size;
    int capacity;
    void resize();
    Pair<T1, T2> *pairs;
public:
    Map();
    ~Map();
    void Set(T1 key, T2 value);
    bool Get(const T1& key, T2& value);
    int Count() const;
    void Clear();
    bool Delete(const T1 &key);
    bool Includes(Map<T1,T2>& map);
    Pair<T1,T2> At(int index);
    T2& operator[](const T1 &key);


    MapIterator<T1, T2> begin();
    MapIterator<T1,T2> end();
};

template<class T1, class T2>
Map<T1, T2>::Map(): size(0), capacity(DEFAULT_CAPACITY), pairs(new Pair<T1,T2>[DEFAULT_CAPACITY]) {}

template<class T1, class T2>
Map<T1, T2>::~Map() {
    delete[] pairs;
}

template<class T1, class T2>
void Map<T1, T2>::Set(T1 key, T2 value) {
    for(int i=0;i<size;i++)
        if(pairs[i].key == key)
        {
            pairs[i].value = value;
            return;
        }

    if(size == capacity) resize();
    pairs[size++] = {key, value};
}

template<class T1, class T2>
void Map<T1, T2>::resize() {
    capacity *= 2;
    auto *new_pairs = new Pair<T1,T2>[capacity];
    for(int i=0;i<size;i++)
        new_pairs[i] = pairs[i];
    delete[] pairs;
    pairs = new_pairs;

}

template<class T1, class T2>
bool Map<T1, T2>::Get(const T1 &key, T2 &value) {
    for(int i=0;i<size;i++)
    {
        if(pairs[i].key == key)
        {
            pairs[i].value = value;
            return true;
        }
    }
    return false;
}

template<class T1, class T2>
int Map<T1, T2>::Count() const {
    return size;
}

template<class T1, class T2>
void Map<T1, T2>::Clear() {
    size = 0;
    capacity = DEFAULT_CAPACITY;
    delete []pairs;
}

template<class T1, class T2>
bool Map<T1, T2>::Delete(const T1 &key) {
    for(int i=0;i<size;i++)
    {
        if(pairs[i].key == key)
        {
            for(int k=i;k<size-1;k++)
                pairs[k] = pairs[k+1];
            size--;
            return true;
        }
    }
    return false;
}

template<class T1, class T2>
bool Map<T1, T2>::Includes(Map<T1, T2> &map) {
    int matches = 0;
    for(int i=0;i<map.size;i++)
    {
        for(int j=0;j<this->size;j++)
            if(map.At(i).key == this->pairs[j].key && map.At(i).value == this->pairs[j].value)
                matches++;
    }
    return matches == map.size;
}

template<class T1, class T2>
T2 &Map<T1, T2>::operator[](const T1 &key) {
    for(int i=0;i<size;i++)
        if(pairs[i].key == key) return pairs[i].value;
    if(size == capacity) resize();
    pairs[size++].key = key;
    return pairs[size-1].value;
}

template<class T1, class T2>
MapIterator<T1, T2> Map<T1, T2>::begin() {
    MapIterator<T1,T2> tmp;
    tmp.pairs = &pairs[0];
    return tmp;
}

template<class T1, class T2>
MapIterator<T1, T2> Map<T1, T2>::end() {
    MapIterator<T1,T2> tmp;
    tmp.pairs = &pairs[this->size];
    return tmp;
}

template<class T1, class T2>
Pair<T1, T2> Map<T1, T2>::At(int index) {
    return pairs[index];
}

#endif
