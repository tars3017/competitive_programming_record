#include <bits/stdc++.h>
using namespace std;
#ifdef tars3017
#define debug(...) do{\
    fprintf(stderr, "Line: %d -(%s) = ", __LINE__, #__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0)
template<typename I>void _DO(I&&x){cerr<<x<<endl;}
template<typename I, typename...T>void _DO(I&&x, T&&...tail) {
    cerr<<x<<", ";
    _DO(tail...);
}
#define Time() cerr << "Time elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " s.\n";
#else 
#define debug(...)
#define Time()
#endif
#define F first
#define S second
#define pii pair<int, int>
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int arr[10] = {0, 10, 100, 10000, 1000000, 100000000};
    while (cin >> n) {
        /* int now_len = arr[n]; */
        /* int cnt = 0; */
        /* for (int len = 3; cnt < now_len; ++len) { */
        /*     for (int i = 1; i <= 9 && cnt < now_len; ++i) { */
        /*         for (int j = 0; j <= 9 && cnt < now_len; ++j) { */
        /*             int num1 = i; */
        /*             int num2 = j; */
        /*             if (num1 == num2) continue; */
        /*             int now = num1; */
        /*             string v; */
        /*             for (int k = 1; k <= len; ++k) { */
        /*                 v.push_back(now+'0'); */
        /*                 if (now == num1) now = num2; */
        /*                 else now = num1; */
        /*             } */
        /*             cnt++; */
        /*             if (cnt == now_len) { */
        /*                 cout << v << ' '; */
        /*             } */
        /*         } */
        /*     } */
        /* } */
        /* cout << endl; */
    }
    cout << 20 << endl;
    cout << 2020 << endl;
    int num1 = 2, num2 = 0;
    int now = num1;
    for (int i = 1; i <= 114; ++i) {
        cout << now;
        if (now == num1) now = num2;
        else now = num1;
    }
    cout << endl;

    now = num1;
    for (int i = 1; i <= 11114; ++i) {
        cout << now;
        if (now == num1) now = num2;
        else now = num1;
    }
    cout << endl;

    now = num1;
    for (int i = 1; i <= 1111114; ++i) {
        cout << now;
        if (now == num1) now = num2;
        else now = num1;
    }
    cout << endl;
    Time();
    return 0;
}

