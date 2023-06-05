#include<bits/stdc++.h>
using namespace std;

enum Gender {
    MALE,
    FEMALE
};

const string table[2] = {"MALE", "FEMALE"};

class Person {
    public:
        string name;
        int age;
        Gender gender;
        string personality;
        Person *parentA, *parentB, *mate, *child;

        Person() {
            this->name = "";
            this->age = 0;
            this->gender = MALE;
            this->personality = "";
            this->parentA = nullptr;
            this->parentB= nullptr;
            this->mate = nullptr;
            this->child = nullptr;
        }
        void describe(string* arr, int now, int len);
        Person* getRelative (string* arr, int now, int len);
        string info() {
            return 
                "Name:" + this->name + ",\n" + 
                "Age:" + to_string(this->age) + ",\n" +
                "Gender:" + table[this->gender] + ",\n" +
                "Personality:" + this->personality + "\n\n";
        };
};

void Person::describe(string* arr, int now, int len) {
    Person *ptr = getRelative(arr, now, len-2);
    if (arr[len-2] == "Gender") {
        ptr->gender = (arr[len-1] == "MALE" ? MALE : FEMALE);
    }
    else if (arr[len-2] == "Age") {
        ptr->age = stoi(arr[len-1]);
    }
    else if (arr[len-2] == "Name") {
        ptr->name = arr[len-1];
    }
    else if (arr[len-2] == "Personality") {
        if (!ptr->personality.empty()) ptr->personality += " ";
        ptr->personality += arr[len-1];
    }
}

Person* Person::getRelative(string* arr, int now, int len) {
    Person *cur = this;
    for (int i = 0; i < len; ++i) {
        if (arr[i] == "ParentA") {
            if (cur->parentA == nullptr) {
                cur->parentA = new Person();
                cur->parentA->child = cur;
                if (cur->parentB) {
                    cur->parentA->mate = cur->parentB;
                    cur->parentB->mate = cur->parentA;
                }
            }
            cur = cur->parentA;
        }
        else if (arr[i] == "ParentB") {
            if (cur->parentB == nullptr) {
                cur->parentB = new Person();
                cur->parentB->child = cur;
                if (cur->parentA) {
                    cur->parentA->mate = cur->parentB;
                    cur->parentB->mate = cur->parentA;
                }
            }
            cur = cur->parentB;
        }
        else if (arr[i] == "Child") {
            if (cur->child == nullptr) {
                cur->child = new Person();
                cur->child->parentA = cur;
                if (cur->mate) {
                    cur->child->parentB = cur->mate;
                    cur->mate->child = cur->child;
                }
            }
            cur = cur->child;
        }
        else if (arr[i] == "Mate") {
            if (cur->mate == nullptr) {
                cur->mate = new Person();
                cur->mate->mate = cur;
                if (cur->child) {
                    // notice here!!!
                    if (cur->child->parentB == nullptr)
                        cur->child->parentB = cur->mate;
                    else if (cur->child->parentA == nullptr)
                        cur->child->parentA = cur->mate;
                    cur->mate->child = cur->child;
                }
            }
            cur = cur->mate;
        }
    }
    return cur;
}