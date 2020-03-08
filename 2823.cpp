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
    int n, m, d, v;
    while (cin>>n>>m, n||m) {
        int dl[n], vl[n];
        for (int i = 0; i < n; ++i) {
            cin>>d>>v;
            dl[i] = d;
            vl[i] = v;
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            int re = 0;
            for (int j = 0; j < n; ++j) {
                if (i == dl[j]) re = max(re, vl[j]);
            }
            ans += re;
        }
        cout << ans << endl;
    }
    return 0;
}