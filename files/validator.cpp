#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int maxN = 500000;
int maxA = 1e9;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, maxN, "n");
    inf.readSpace();
    int m = inf.readInt(1, maxN, "q");
    inf.readEoln();

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            inf.readSpace();
        }
        inf.readInt(1, maxA, "a");
    }
    inf.readEoln();

    for (int op = 0; op < m; ++op) {
        int t = inf.readInt(1, 2, "t");
        inf.readSpace();
        if (t == 1) {
            inf.readInt(1, n, "i");
            inf.readSpace();
            inf.readInt(1, maxA, "x");
        } else {
            inf.readInt(1, n, "l");
            inf.readSpace();
            inf.readInt(1, n, "d");
        }
        inf.readEoln();
    }

    inf.readEof();
}