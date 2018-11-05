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
    int N, M;
    while (cin >> N >> M, N) {
        vector<int> p(N + 1, 0);
        vector<int> mp((N+1) * (N+1), 0);
        for (int i = 1; i <= N; ++i) {
            cin >> p[i];
        }
        sort(p.begin(), p.end());

        int cnt = 0;
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                mp[cnt] = p[i] + p[j];
                cnt++;
            }
        }
        sort(mp.begin(), mp.end());

        int ans = 0;
        for (int i = 0; i < cnt; ++i) {
            int tmp = M - mp[i];
            if (tmp < 0) continue;
            ans = max(ans, mp[i] + *(upper_bound(mp.begin(), mp.end(), tmp) - 1));
        }
        cout << ans << endl;
    }
    return 0;
}