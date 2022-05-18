#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
private:
    vector<int64_t> tree_;

public:
    FenwickTree() = default;
    explicit FenwickTree(int n) : tree_(vector<int64_t>(n, 0)) {}
    explicit FenwickTree(const vector<int>& arr) {
        tree_.resize(arr.size(), 0);
        for (size_t i = 0; i < arr.size(); ++i) {
            add(i, arr[i]);
        }
    }

    [[nodiscard]] inline int64_t query(int r) const noexcept {
        int64_t res = 0;
        for (; r >= 0; r = (r & (r+1)) - 1)
            res += tree_[r];
        return res;
    }

    [[nodiscard]] inline int64_t query(int l, int r) const noexcept {
        return l == 0 ? query(r) : query(r) - query(l - 1);
    }

    [[nodiscard]] inline size_t size() const noexcept {
        return tree_.size();
    }

    inline void add(size_t pos, int64_t change) {
        for (; pos < tree_.size(); pos = pos | (pos + 1)) {
            tree_[pos] += change;
        }
    }
};


vector<int> Range(const vector<int>& arr, int l, int step) {
    vector<int> res;
    for (size_t i = l; i < arr.size(); i += step) {
        res.push_back(arr[i]);
    }
    return res;
}

void run() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int D = 0;
    while (D * D * D < n) ++D;

    vector<vector<FenwickTree>> fens(D + 1);
    vector<vector<int>> mapping(D + 1);
    for (int d = 1; d <= D; ++d) {
        fens[d].resize(d);
        for (int modulo = 0; modulo < d; ++modulo) {
            fens[d][modulo] = FenwickTree(Range(arr, modulo, d));
        }
    }

    while (q --> 0) {
        int t;
        cin >> t;

        if (t == 1) {
            int i; int64_t x;
            cin >> i >> x;
            --i;
            arr[i] = (int) x;
            for (int d = 1; d <= D; ++d) {
                int fen_pos = i / d;
                int64_t val = fens[d][i % d].query(fen_pos, fen_pos);
                fens[d][i % d].add(fen_pos, x - val);
            }
        } else {
            int l, d;
            cin >> l >> d;
            --l;
            int fen_pos = l / d;
            if (d <= D) {
                cout << fens[d][l % d].query(fen_pos, (int) fens[d][l % d].size() - 1) << endl;
            } else {
                int64_t ans = 0;
                for (int i = l; i < n; i += d) {
                    ans += arr[i];
                }
                cout << ans << endl;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout << fixed << setprecision(13);

    int t = 1;
    //cin >> t;
    for (int test = 1; test <= t; ++test) {
        run();
    }

    return 0;
}