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
    while (cin>>N>>M, N||M) {
        vector<int> h(N), w(M);
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            cin >> h[i];
        }
        for (int j = 0; j < M; ++j) {
            cin >> w[j];
        }

        map<int, int> mp;
        for (int i = 0; i < N; ++i) {
            int sum = 0;
            for (int j = i; j < N; ++j) {
                sum += h[j];
                mp[sum]++;
            }
        }

        for (int i = 0; i < M; ++i) {
            int sum = 0;
            for (int j = i; j < M; ++j) {
                sum += w[j];
                ans += mp[sum];
            }
        }

        cout << ans << endl;
    }

    return 0;
}