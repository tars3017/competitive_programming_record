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
#else 
#define debug(...)
#endif
#define F first
#define S second
#define pii pair<int, int>
#define ll long long
int rand(int a, int b) {
    return a + rand() % (b-a+1);
}
int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(atoi(argv[1]));
    int n = rand(1, 3), t = rand(3, 15), l = rand(2, 4);
    printf("%d %d %d\n", n, t, l);
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", rand(1, 10), rand(1, 10));
    }
    return 0;
}

