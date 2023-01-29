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
    printf("1\n");
    int n = rand(1, 5), r = rand(5, 10), c = rand(5, 10), sr = rand(2, r-2), sc = rand(2, c-2);
    printf("%d %d %d %d %d\n", n, r, c, sr, sc);
    for (int i = 0; i < n; ++i) {
        int x = rand(1, 4);
        if (x == 1) {
            printf("N");
        }
        else if (x == 2) {
            printf("E");
        }
        else if (x == 3) {
            printf("S");
        }
        else {
            printf("W");
        }
    }
    printf("\n");
    return 0;
}

