#pragma once
#include <iostream>
#include <cstring>

template <class T>
class Vector
{
  private:
    static const int INITIAL_ALLOCATED_SIZE = 1;
  
    T* arr;
    int size;
    int allocated_size;

    void resize(int new_allocated_size) {
        T* old_arr = arr;
        arr        = new T[new_allocated_size];

        for (int i = 0; i < allocated_size; i++)
            arr[i] = old_arr[i];
        
        delete[] old_arr;
        allocated_size = new_allocated_size;
    }

  public:
    Vector() : size(0), allocated_size(INITIAL_ALLOCATED_SIZE), arr(new T[INITIAL_ALLOCATED_SIZE]) {}

    ~Vector() {
        delete[] arr;
    }

    void push(const T& item) {
        if (size == allocated_size)
            resize(allocated_size * 2);
        arr[size++] = item;
    }

    T pop() {
        if (size > 0) {
            T temporary = arr[size - 1];
            size--;

           /* if (size <= allocated_size / 2)
                resize(allocated_size / 2);*/

            return temporary;
        } 
    }

    bool remove(int index) {
        if (index < 0 || size <= index)
            return false;
        for (; index < size - 1; index++)
            arr[index] = arr[index + 1];
        size--;

        /*if (size <= allocated_size / 2)
            resize(allocated_size/2);*/

        return true;

    }

    bool insert(int index, T value) {
        if (index < 0 || size < index)
            return false;

        if (size == allocated_size)
            resize(allocated_size * 2);

        for (int k=size; k > index; k--)
            arr[k] = arr[k - 1];
        arr[index] = value;
        size++;


        return true;
    }

    const T& get(int index) {
        if (0 <= index && index < size) {
            return arr[index];
        }
    }

    bool set(int index, T obj) {
        if (index < 0 || size < index)
            return false;
        arr[index] = obj;
        return true;
    }

    // default crescator
    void sort(bool (*callback)(T, T) = nullptr) {
        for (int i=0;i<size-1;i++) {
            for (int j=i+1;j<size;j++) {
                if (callback == nullptr && arr[i] > arr[j] || callback != nullptr && callback(arr[i], arr[j])) {
                    std::swap(arr[i], arr[j]);
                }
            }
        }
    }

    int firstIndexOf(const T& obj, bool (*callback)(T, T) = nullptr) {
        for (int i=0;i<size;i++) {
            if (callback == nullptr && arr[i] == obj || callback != nullptr && callback(obj, arr[i]))
                return i;
        }
        return -1;
    }


    void print() {
        if (size == 0)
            return;
        std::cout<<"Vector = (";
        for (int i=0;i<size;i++) {
            std::cout << arr[i];
            if (i != size-1) {
                std::cout<< ", ";
            }
        }
        std::cout << ")\n";
    }

    int count() {
        return size;
    }


    // pentru testare
    int getAllocatedSize() {
        return allocated_size;
    }

};


