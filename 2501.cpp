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
    int n, a, b, c, d, ans;
    pair<int, int> ap, bp, cp, dp;
    cin >> n;
    cin >> a >> b;
    cin >> c >> d;
    ans = 10000000;
    for (int i = 1; i < n; ++i) {
        int grid[100][100] = {0};
        int count = 1;
        // cout << "-------" <<endl;
        for (int y = 0; y < i; ++y) {
            for (int x = 0; x < n - i + 1; ++x) {
                if (count > n) break;
                grid[x][y] = count;
                // cout << count << " ";
                if (a == count) ap = make_pair(x, y);
                if (b == count) bp = make_pair(x, y);
                if (c == count) cp = make_pair(x, y);
                if (d == count) dp = make_pair(x, y);
                count++;
            }
            // cout << endl;
        }
        // printf("a:(%d, %d) b:(%d, %d)\n", ap.first, ap.second, bp.first, bp.second);
        // printf("tmp: %d\n", abs(ap.first - bp.first) + abs(ap.second - bp.second) 
        //         + abs(cp.first - dp.first) + abs(cp.second - dp.second));
        ans = min(ans, abs(ap.first - bp.first) + abs(ap.second - bp.second) 
                + abs(cp.first - dp.first) + abs(cp.second - dp.second));
    }
    cout << ans << endl;
    return 0;
}