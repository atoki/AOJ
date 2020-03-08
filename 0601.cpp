#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

using PII = pair<long long, long long>;

int main (int argc, char *argv[]) {
    int N, M, X;
    cin >> N >> M >> X;
    int H[N];
    vector<PII> g[N];
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    int a, b, t;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> t;
        a--;
        b--;
        if (H[a] >= t) g[a].push_back(PII(b, t));
        if (H[b] >= t) g[b].push_back(PII(a, t));
    }

    priority_queue<PII, vector<PII>, greater<PII>> que;
    bool visited[N];
    for (int i = 0; i < N; ++i) visited[i] = false;
    long long d[N];
    for (int i = 0; i < N; ++i) d[i] = LLONG_MAX;
    d[0] = 0;
    que.push(PII(0, 0)); // (cost, n)
    while (!que.empty()) {
        PII p = que.top();
        que.pop();
        long long cost = p.first;
        int n = p.second;
        if (visited[n]) continue;
        visited[n] = true;
        for (auto ge : g[n]) {
            int nn = ge.first;
            long long ncost = ge.second;
            int add = 0;
            if (X >= cost + ncost + H[nn]) add = X - (cost + ncost + H[nn]);
            if (d[nn] > cost + ncost + add) {
                d[nn] = cost + ncost + add;
                que.push(PII(d[nn], nn));
            }
        }
    }

    if (d[N-1] < LLONG_MAX) cout << d[N-1] + H[N-1] - (X - d[N-1]) << endl;
    else cout << "-1" << endl;
    
    return 0;
}