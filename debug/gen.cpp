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
    int n = rand(2, 5);
    int q = rand(2, 4);
    printf("%d %d\n", n, q);
    set<int> used;
    for (int i = 0; i < n; i++) {
        printf("%d ", rand(1, 10)*(-1));
    }
    printf("\n");
    for (int i = 0; i < q; i++) {
        int opt = rand(1, 10);
        int a, b;
        if (opt <= 5) {
            printf("1 %d %d\n", rand(1, n), rand(1, 10)-6);
        }
        else {
            do {
                a = rand(1, n), b = rand(1, n);
            }while (a > b);
            printf("2 %d %d\n", a, b);
        }
    }
    return 0;
}

