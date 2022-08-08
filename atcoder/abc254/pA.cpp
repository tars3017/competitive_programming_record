#include <bits/stdc++.h>
using namespace std;
#ifdef tars3017
#define debug(...) do {\
    fprintf(stderr, "Line: %d -(%s) = ", __LINE__, #__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0);
#define Time() cerr << "Time elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " s.\n"; 
template<typename I>void _DO(I&&x){cerr<<x<<endl;}
template<typename I, typename...T>void _DO(I&&x, T&&...tail) {
    cerr<<x<<", ";
    _DO(tail...);
}
#else
#define debug(...)
#define Time(...)
#endif

int main() {
    string str; cin >> str;
    cout << str[1] << str[2] << endl;
    Time();
    return 0;
}
