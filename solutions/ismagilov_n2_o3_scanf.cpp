#pragma GCC optimize("O3,unroll-loops")
#include <iostream>

using namespace std;

const int MAXN = 2e5;
int a[MAXN];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < q; ++i){
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        --x;
        if (t == 1) {
            a[x] = y;
        } else {
            long long ans = 0;
            for (int j = x; j < n; j += y) {
                ans += a[j];
            }
            printf("%lld\n", ans);
        }
    }
}