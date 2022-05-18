#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
const int BLOCK = 400;
const int UNBLOCK = MAXN / BLOCK;

int get_stored_index(int x, int pos) {
    return (pos / x / UNBLOCK) * x + (pos % x);
}

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
        store[x].assign(n / UNBLOCK + x, 0);
        for (int j = 0; j < n; ++j) {
            store[x][get_stored_index(x, j)] += a[j];
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
                store[level][get_stored_index(level, pos)] += d;
            }
        } else {
            long long ans = 0;
            if (x < BLOCK) {
                int where_stored = -1;
                for (int j = pos; j < n; j += x) {
                    if ((j / x) % UNBLOCK == 0) {
                        where_stored = get_stored_index(x, j);
                        break;
                    }
                    ans += a[j];
                }
                if (where_stored != -1) {
                    for (int j = where_stored; j < store[x].size(); j += x) {
                        ans += store[x][j];
                    }
                }
            } else {
                for (int j = pos; j < n; j += x) {
                    ans += a[j];
                }
            }
            cout << ans << '\n';
        }
    }
}