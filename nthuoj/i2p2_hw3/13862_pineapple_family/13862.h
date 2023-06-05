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
    // cout << "here\n" << endl;
    Person *cur = this->getRelative(arr, 0, len-2);
    // cout << "ready to modify " << cur->info();
    if (arr[len-2] == "Gender") {
        cur->gender = (arr[len-1] == "MALE" ? MALE : FEMALE);
    }
    else if (arr[len-2] == "Age") {
        cur->age = stoi(arr[len-1]);
    }
    else if (arr[len-2] == "Name") {
        cur->name = arr[len-1];
    }
    else if (arr[len-2] == "Personality") {
        if (!(cur->personality.empty())) cur->personality += " ";
        cur->personality += arr[len-1];
    }
    else {
        assert(0);
    }
}

Person* Person::getRelative (string* arr, int now, int len) {
    Person *cur = this;
    // cout << "getRelative " << this->info();
    int i;
    for (i = 0; i < len; ++i) {
        // cout << "i=" << i << " " << (cur == nullptr) << endl;
        if (arr[i] == "ParentA") {
            if (cur->parentA == nullptr) {
                // cout << "create parentA" << endl;
                cur->parentA = new Person();
                if (cur->parentB) {
                    cur->parentA->mate = cur->parentB;
                    cur->parentA->child = cur;
                    cur->parentB->mate = cur->parentA;
                } 
                else {
                    cur->parentA->child = cur;
                }
            }
            cur = cur->parentA;
        }
        else if (arr[i] == "ParentB") {
            if (cur->parentB == nullptr) {
                // cout << "create parentB" << endl;
                cur->parentB = new Person();
                if (cur->parentA) {
                    cur->parentB->mate = cur->parentA;
                    cur->parentA->mate = cur->parentB;
                    cur->parentB->child = cur;
                }
                else {
                    cur->parentB->child = cur;
                }
            }
            cur = cur->parentB;
        }
        else if (arr[i] == "Mate") {
            if (cur->mate == nullptr) {
                // cout << "Create mate" << endl;
                cur->mate = new Person();
                cur->mate->mate = cur;
                if (cur->child) {
                    cur->mate->child = cur->child;
                    if (cur->child->parentB == nullptr) cur->child->parentB = cur->mate;
                    else if (cur->child->parentA == nullptr) cur->child->parentA = cur->mate;
                }
            }
            cur = cur->mate;
        }
        else if (arr[i] == "Child") {
            if (cur->child == nullptr) {
                // cout << "child" << endl;
                cur->child = new Person();
                cur->child->parentA = cur;
                if (cur->mate) {
                    cur->child->parentB = cur->mate;
                    cur->mate->child = cur->child;
                }
            }
            cur = cur->child;
        }
        else {
            assert(0);
            break;
        }
    }
    return cur;
}