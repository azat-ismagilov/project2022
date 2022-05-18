#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

void run() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    while (q --> 0) {
        int t;
        cin >> t;

        if (t == 1) {
            int i; int64_t x;
            cin >> i >> x;
            --i;
            arr[i] = (int) x;
        } else {
            int l, d;
            cin >> l >> d;
            --l;

            int64_t ans = 0;
            for (int i = l; i < n; i += d) {
                ans += arr[i];
            }
            cout << ans << endl;
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