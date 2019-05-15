#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long long N, P, Q;
    cin >> N >> P >> Q;
    long long sum = 0;
    long long C[500005];
    vector<pair<long long, int> > ps;

    for (int i = 0; i < N; i++) {
        cin >> C[i];
        sum += C[i];
        ps.emplace_back(C[i]+P*i, i);
    }

    sort(ps.begin(), ps.end());

    long long ans = sum;

    for (int i = 0; i <= N; i++) {
        ans = max(ans, sum+P*i*(i-1)+P*Q*i);
        if (i < N) {
            sum -= C[ps[i].second] + P*ps[i].second;
        }
    }

    cout << ans << endl;
    
    return 0;
}