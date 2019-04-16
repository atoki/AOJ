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
    int w, h, n;
    int ans = 0;
    cin >> w >> h;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    pair<int, int> uzu = make_pair(1, h);   // out
    pair<int, int> rin = make_pair(1, h-1); // in
    for (int i = 0; i < n; ++i) {
        if (p[i] == 0) {
            if (uzu.first < w && uzu.second == h) uzu.first++;
            else if (uzu.first == w && uzu.second > 1) uzu.second--;
            else uzu.first--;
        }
        else {
            if (rin.first < w - 1 && rin.second == h - 1) rin.first++;
            else if (rin.first == w - 1 && rin.second > 2) rin.second--;
            else rin.first--;
        }
        if ((abs(uzu.first - rin.first) + abs(uzu.second - rin.second)) == 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}