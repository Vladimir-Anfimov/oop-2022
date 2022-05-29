#pragma once
#include "CompareIntPointer.h"
#include "ArrayIterator.h"

template <class T>
class Array {
  private:
    T** List; // lista cu pointeri la obiecte de tipul T*

    int Capacity; // dimensiunea listei de pointeri

    int Size; // cate elemente sunt in lista

    void Resize();

  public:
    Array(); // Lista nu e alocata, Capacity si Size = 0

    ~Array(); // destructor

    Array(int capacity); // Lista e alocata cu 'capacity' elemente

    Array(const Array<T>& otherArray); // constructor de copiere

    T& operator[](int index); // arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this

    const Array<T>& Insert(int index, const T& newElem); // adauga un element pe pozitia index, retureaza this. Daca
                                                         // index e invalid arunca o exceptie

    const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, returneaza this.
                                                                  // Daca index e invalid arunca o exceptie

    const Array<T>& Delete(
          int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T>& otherArray);

    void Sort(); // sorteaza folosind comparatia intre elementele din T

    void Sort(int (*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie

    void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array

    int BinarySearch(
          const T& elem,
          int (*compare)(const T&, const T&)); //  cauta un element folosind binary search si o functie de comparatie

    int BinarySearch(const T& elem, Compare* comparator); //  cauta un element folosind binary search si un comparator

    int Find(const T& elem); // cauta un element in Array

    int Find(const T& elem, int (*compare)(const T&, const T&)); //  cauta un element folosind o functie de comparatie

    int Find(const T& elem, Compare* comparator); //  cauta un element folosind un comparator

    int GetSize();

    int GetCapacity();

    ArrayIterator<T> GetBeginIterator();

    ArrayIterator<T> GetEndIterator();
};

template <class T>
inline void Array<T>::Resize() {
    Capacity *= 2;
    T** NewList = new T*[Capacity];
    for (int i = 0; i < Size; i++)
        NewList[i] = List[i];
    delete[] List;
    List = NewList;
}

template <class T>
inline Array<T>::Array() : Capacity(0), Size(0) {
}

template <class T>
inline Array<T>::~Array() {
    for (int i = 0; i < Size; i++)
        delete[] List[i];
    delete[] List;
}

template <class T>
inline Array<T>::Array(int capacity) : Size(0), Capacity(capacity), List(new T*[capacity]) {
}

template <class T>
inline Array<T>::Array(const Array<T>& otherArray) {
    for (int i = 0; i < Size; i++)
        delete[] List[i];
    delete[] List;
    Capacity = otherArray.Capacity;
    Size     = otherArray.Size;
    List     = new T*[Capacity];
    for (int i = 0; i < Size; i++)
        List[i] = otherArray.List[i];
}

template <class T>
inline T& Array<T>::operator[](int index) {
    if (index < 0 || index >= Size)
        throw "Index is out of range!";
    return List[index];
}

template <class T>
inline const Array<T>& Array<T>::operator+=(const T& newElem) {
    if (Size == Capacity) Resize();
    List[Size++] = newElem;
    return *this;
}

template <class T>
inline const Array<T>& Array<T>::Insert(int index, const T& newElem) {
    if (index < 0 || index > Size)
        throw "Index is out of range!";
    if (Size == Capacity) Resize();
    for (int j = Size; j > index; j--)
        List[j] = List[j - 1];
    
    //?????????????????????????
    Size++;
    return *this;
}

template <class T>
inline const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray) {
    if (index < 0 || index > Size)
        throw "Index is out of range!";
    for (int i = 0; i < otherArray.Size; i++)
        this->Insert(index + i, otherArray[i]);
}

template <class T>
inline const Array<T>& Array<T>::Delete(int index) {
    if (index < 0 || index > Size)
        throw "Index is out of range!";
    delete[] List[index];
    for (int k = index; k < Size - 1; k++)
        List[index] = List[index + 1];
    Size--;
}

template <class T>
inline bool Array<T>::operator=(const Array<T>& otherArray) {
    for (int i=0;i<Size;i++) {
        this->Delete(i);
    }
    Size = Capacity = 0;
    for (int i=0;i<otherArray.Size;i++) {
        this->Insert(i, otherArray[i]);
    
    }
}

template <class T>
inline void Array<T>::Sort() {
    for (int i=0;i<Size-1;i++) {
        for (int j=i+1;j<Size;j++)
            if (List[i] > List[j]) {
                std::swap(List[i], List[j]);
            }
    }
}

template <class T>
inline void Array<T>::Sort(int (*compare)(const T&, const T&)) {
    for (int i = 0; i < Size - 1; i++) {
        for (int j = i + 1; j < Size; j++)
            if (compare(List[i], List[j])) {
                std::swap(List[i], List[j]);
            }
    }
}

template <class T>
inline void Array<T>::Sort(Compare* comparator) {
    for (int i = 0; i < Size - 1; i++) {
        for (int j = i + 1; j < Size; j++)
            if (comparator->CompareElements(List[i], List[j])) {
                std::swap(List[i], List[j]);
            }
    }
}

template <class T>
inline int Array<T>::BinarySearch(const T& elem) {
    int start = 0, end = Size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (List[mid] == elem)
            return mid;
        else if (List[mid] < elem)
            start = mid + 1;
        else
            end = mid - 1;
    }
}

template <class T>
inline int Array<T>::BinarySearch(const T& elem, int (*compare)(const T&, const T&)) {
    int start = 0, end = Size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (compare(List[mid],elem) == 0)
            return mid;
        else if (compare(List[mid], elem) == -1)
            start = mid + 1;
        else
            end = mid - 1;
    }
}

template <class T>
inline int Array<T>::BinarySearch(const T& elem, Compare* comparator) {
    int start = 0, end = Size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (comparator->CompareElements(List[mid], elem) == 0)
            return mid;
        else if (comparator->CompareElements(List[mid], elem) == -1)
            start = mid + 1;
        else
            end = mid - 1;
    }
}

template <class T>
inline int Array<T>::Find(const T& elem) {
    for (int i = 0; i < Size; i++)
        if (List[i] == elem)
            return i;
    return -1;
}

template <class T>
inline int Array<T>::Find(const T& elem, int (*compare)(const T&, const T&)) {
    for (int i = 0; i < Size; i++)
        if (compare(List[i], elem))
            return i;
    return -1;
}

template <class T>
inline int Array<T>::Find(const T& elem, Compare* comparator) {
    for (int i = 0; i < Size; i++)
        if (comparator->CompareElements(List[i], elem))
            return i;
    return -1;
}

template <class T>
inline int Array<T>::GetSize() {
    return Size;
}

template <class T>
inline int Array<T>::GetCapacity() {
    return Capacity;
}

template <class T>
inline ArrayIterator<T> Array<T>::GetBeginIterator() {
    ArrayIterator tmp;
    tmp.Item = &List[0];
    return tmp;
}

template <class T>
inline ArrayIterator<T> Array<T>::GetEndIterator() {
    ArrayIterator tmp;
    tmp.Item = &List[Size];
    return tmp;
}



