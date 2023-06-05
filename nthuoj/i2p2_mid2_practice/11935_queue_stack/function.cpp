#include "function.h"
#include <iostream>

using namespace std;
void _stack::push(const _node N) {
    // cout << "data " << N.data << endl;
    End->data = N.data;
    End->next = new _node(0);
    End->next->prev = End;
    End = End->next;
}

void _stack::pop() {
    if (!this->Empty()) {
        _node* tmp = End->prev;
        End->prev->next = nullptr;
        End->prev = nullptr;
        delete End;
        End = tmp;
    }
    else {
        End->data = 0;
        Begin->data = 0;
    }
}

_node* _stack::get_data() {
    if (!this->Empty()) {
        return End->prev;
    }
    else {
        return nullptr;
    }
    
}

void _queue::push(const _node N) {
    End->data = N.data;
    End->next = new _node(0);
    End->next->prev = End;
    End = End->next;
}

void _queue::pop() {
    if (!this->Empty()) {
        _node* tmp = Begin->next;
        Begin->next = tmp->next;
        tmp->next->prev = Begin;
        delete tmp;
    }
    else {
        End->data = 0;
        Begin->data = 0;
    }
}

_node* _queue::get_data() {
    if (!this->Empty()) {
        return Begin->next;
    }
    else {
        return nullptr;
    }
}