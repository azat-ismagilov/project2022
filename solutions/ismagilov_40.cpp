#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
const int BLOCK = 400;
const int UNBLOCK = MAXN / BLOCK;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &v : a) {
        cin >> v;
    }
    vector<vector<long long>> store(BLOCK);
    for (int x = 1; x < BLOCK; ++x) {
        store[x].assign(x, 0);
        for (int y = 0; y < x; ++y) {
            for (int j = y; j < n; j += x) {
                store[x][y] += a[j];
            }
        }
    }
    for (int op = 0; op < q; ++op) {
        int t, pos, x;
        cin >> t >> pos >> x;
        --pos;
        if (t == 1) {
            int d = x - a[pos];
            a[pos] += d;
            for (int level = 1; level < BLOCK; ++level) {
                store[level][pos % level] += d;
            }
        } else {
            long long ans = 0;
            if (x < BLOCK) {
                ans += store[x][pos];
            } else {
                for (int j = pos; j < n; j += x) {
                    ans += a[j];
                }
            }
            cout << ans << '\n';
        }
    }
}