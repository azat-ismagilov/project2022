#include <iostream>

using namespace std;

const int MAXN = 2e5;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for (int i = 0; i < q; ++i){
        int t, x, y;
        cin >> t >> x >> y;
        --x;
        if (t == 1) {
            a[x] = y;
        } else {
            long long ans = 0;
            for (int j = x; j < n; j += y) {
                ans += a[j];
            }
            cout << ans << '\n';
        }
    }
}