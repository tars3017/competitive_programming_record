#include <iostream>
#include <algorithm>
#include "function.h"

using namespace std;

Food::Food() {}
Food::Food(string& str) {
    name = str;
    fly = 0;
    pos = FLOOR;
}

Food::Food(const Food& foo) {
    name = foo.name;
    fly = foo.fly;
    pos = foo.pos;
}

void Food::eaten() {
    pos = STOMACH;
}

void Food::thrown() {
    pos = TRASHCAN;
}

bool Food::on_floor() {
    return (pos == FLOOR);
}

string Food::get_name() {
    return name;
}

int Food::get_fly() {
    return fly;
}

bool Food::operator < (const Food & foo2) {
    if (pos != FLOOR && foo2.pos == FLOOR) {
        return 0;
    }
    else if (pos == FLOOR && foo2.pos != FLOOR) {
        return 1;
    }
    else {
        return name < foo2.name;
    }
}

bool Food::operator == (const string & str) {
    return (name == str);
}

ostream& operator << (ostream& output, Food foo2) {
    output << foo2.name;
    return output;
}

Fruit::Fruit() :Food() {}

Fruit::Fruit(string& str) :Food(str) {}
void Fruit::five_min_pass() {
    if (pos == FLOOR)
        fly += 4;
}
bool Fruit::sickness() {
    return (pos == STOMACH && fly >= 10);
}

void Fruit::operator += (Fruit& fru) {
    name = fru.name + name;
    fly += fru.fly;
}
void Fruit::operator += (Meat& mea) {
    name = mea.get_name() + name;
    fly += mea.get_fly();
}


Meat::Meat() {}
Meat::Meat(string& str) :Food(str) {
    // cout << "add meat " << str << endl;
}

void Meat::five_min_pass() {
    if (pos == FLOOR)
        fly += 5;
}

bool Meat::sickness() {
    return (pos == STOMACH && fly >= 20);
}

void Meat::operator += (Fruit& fru) {
    name = fru.get_name() + name;
    fly = fru.get_fly() + fly;
}

void Meat::operator += (Meat& mea) {
    name = mea.get_name() + name;
    fly = mea.get_fly() + fly;
}