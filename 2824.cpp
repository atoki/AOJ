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
    int t, d, l;
    while (cin >> t >> d >> l, t) {
        int x[t];
        int ans = 0;
        for (int i = 0; i < t; ++i) {
            cin >> x[i];
        }
        int last = -1;
        for (int i = 0; i < t; ++i) {
            if (i - d  <= last && last >= 0) ans++;
            if (x[i] >= l) last = i;
            printf("i:%d, ans:%d\n", i, ans);
        }
        cout << ans << endl;
    }
    return 0;
}