#include "function.h"
#include <cassert>

Darray::~Darray() {
    delete [] data;
    capacity = 0;
    size = 0;
}

int& Darray::operator[](int x) {
    if (x < 0 || x >= size) assert(0);
    else return data[x];
}

void Darray::pushback(int x) {
    if (size == capacity) {
        int* new_arr = new int[capacity*2]();
        for (int i = 0; i < size; ++i) {
            new_arr[i] = data[i];
        }
        delete [] data;
        data = new_arr;
        capacity *= 2;
    }
    data[size] = x;
    ++size;
}

void Darray::clear() {
    size = 0;
}

int Darray::length() {
    return size;
}