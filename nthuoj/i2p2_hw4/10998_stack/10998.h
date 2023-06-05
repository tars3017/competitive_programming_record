#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>

class ListNode
{
    friend class List_stack; //make List_stack a friend
    public:
        ListNode( const int &info ) //constructor
        : data( info ), nextPtr( NULL ), prevPtr( NULL )
        {
        } //end ListNode constructor

    private:
        int data; //data
        ListNode *nextPtr; // next node in list
        ListNode *prevPtr;
}; //end class ListNode

class List_stack {
    public:
        List_stack();
        ~List_stack();
        void push(const int &);
        void pop();
        void print();
    private:
        ListNode *head;
        ListNode *tail;
};

List_stack::List_stack() :head(nullptr), tail(nullptr) {}
List_stack::~List_stack() {
    ListNode *i = head;
    while (i != nullptr) {
        ListNode *tmp = i->nextPtr;
        delete i;
        i = tmp;
    }
}
void List_stack::push(const int &num) {
    if (head == nullptr) {
        head = new ListNode(0);
        tail = new ListNode(num);
        head->nextPtr = tail;
        tail->prevPtr = head;
    }
    else if (tail == head) {
        tail = new ListNode(num);
        head->nextPtr = tail;
        tail->prevPtr = head;
    }
    else {
        ListNode *now = new ListNode(num);
        now->prevPtr = tail;
        tail->nextPtr = now;
        tail = now;
    }
    
}

void List_stack::pop() {
    if (tail == head) return ;
    else {
        ListNode *now = tail;
        tail = now->prevPtr;
        tail->nextPtr = nullptr;
        // std::cout << "now tail " << tail->data << std::endl;
        delete now;
    }
}

void List_stack::print() {
    // if (head == nullptr) std::cout << "empty\n";
    ListNode* now = tail;
    if (now != nullptr && now != head) {
        std::cout << now->data;
        now = now->prevPtr;
        while (now != nullptr && now != head) {
            std::cout << " " << now->data;
            now = now->prevPtr;
        }
    }
     
}
#endif // FUNCTION_H
