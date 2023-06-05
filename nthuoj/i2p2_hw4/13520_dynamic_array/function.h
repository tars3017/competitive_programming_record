#ifndef FUNCTION_H
#define FUNCTION_H

#include <cassert>
class Darray {
    public:
        Darray() {
            capacity = 100;
            size = 0;
            data = new int[capacity];
        };
        ~Darray();
        int& operator[](int);
        void pushback(int x);
        void clear(void);
        int length(void);
    private:
        void resize(void); // double the capacity
        int *data;
        int capacity;
        int size;
};

int& Darray::operator[](int idx) {
    if (idx >= size) {
        assert(0);
    }
    return data[idx];
}

void Darray::pushback(int x) {
    if (size == capacity) {
        int* new_arr = new int[size*2]();
        for (int i = 0; i < size; ++i) {
            new_arr[i] = data[i];
        }
        delete [] data;
        data = new_arr;
        capacity = size * 2;
    }
    data[size] = x;
    ++size;
}
void Darray::clear(void) {
    delete [] data;
    size = 0;
    capacity = 100;
    data = new int[100]();
}

int Darray::length(void) {
    return size;
}

Darray::~Darray() {
    this->clear();
}
#endif
