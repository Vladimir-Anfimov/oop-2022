#pragma once
template <class T>
class ArrayIterator

{
  private:
    int Current; // mai adaugati si alte date si functii necesare pentru iterator

  public:
    T* Item;
    ArrayIterator();

    ArrayIterator& operator++();

    ArrayIterator& operator--();

    bool operator=(ArrayIterator<T>& it);

    bool operator!=(ArrayIterator<T>& it);

    T* operator*();

    T* GetElement();
};

template <class T>
inline ArrayIterator<T>::ArrayIterator() {
    Current = 0;
}

template <class T>
inline ArrayIterator<T>& ArrayIterator<T>::operator++() {
    Current++;
    return *this;
}

template <class T>
inline ArrayIterator<T>& ArrayIterator<T>::operator--() {
    Current--;
    return *this;
}

template <class T>
inline bool ArrayIterator<T>::operator=(ArrayIterator<T>& it) {
    return it.Item == this->Item;
}

template <class T>
inline bool ArrayIterator<T>::operator!=(ArrayIterator<T>& it) {
    return it.Item != this->Item;
}

template <class T>
inline T* ArrayIterator<T>::operator*() {
    return *Item;
}

template <class T>
inline T* ArrayIterator<T>::GetElement() {
    return Item;
}
