#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[]) {
    for (int i = 0; i < 3; ++i) {
        int T[6], h, m, s;
        for (int i = 0; i < 6; ++i) {
            cin >> T[i];
        }

        s = T[5] - T[2];
        bool flag1 = false;
        if (T[5] - T[2] < 0) {
            s = 60 + T[5] - T[2];
            flag1 = true;
        }

        m = T[4] - T[1];
        if (flag1) m--;
        bool flag2 = false;
        if (m < 0) {
            m += 60;
            flag2 = true;
        }

        h = T[3] - T[0];
        if (flag2) h--;
        
        printf("%d %d %d\n", h, m, s);
    }
    return 0;
}