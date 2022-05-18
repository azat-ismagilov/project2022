#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int maxA = 1e9;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int type = atoi(argv[1]);
    int n = atoi(argv[2]);
    int m = atoi(argv[3]);
    int sq = sqrt(n);
    int perc1 = atoi(argv[4]);
    int perc2 = atoi(argv[5]);
    int perc3 = atoi(argv[6]);
    cout << n << ' ' << m << endl;
    for (int i = 0; i < n; ++i){
        if (i > 0){
            cout << ' ';
        }
        cout << rnd.next(0, maxA);
    }
    cout << endl;
    for (int i = 0; i < m; ++i){
        if (rnd.next(0, 100) < perc1) {
            int pos = rnd.next(1, n);
            cout << 1 << ' ' << pos << ' ' << rnd.next(0, maxA) << endl;
        } else {
            int d = rnd.next(1, n);
            if (rnd.next(0, 100) < perc3) {
                d = rnd.wnext(n, -n / 3) + 1;
            }
            int pos = rnd.next(1, n);
            if (rnd.next(0, 100) < perc2) {
                pos = rnd.wnext(n, -n / 3) + 1;
            }
            if (type == 3) {
                pos = rnd.next(1, d);
            }
            cout << 2 << ' ' << pos << ' ' << d << endl;
        }
    }
}