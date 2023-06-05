#include <iostream>
#include "function.h"
using namespace std;

int main() {
    Darray arr;
    for (int i = 0; i <= 101; ++i) {
        arr.pushback(i);
    }
    arr[0] = 100;
    for (int i = 0; i < arr.length(); ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}