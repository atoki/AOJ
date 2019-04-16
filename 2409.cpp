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
    cin >> N >> M;
    vector<pair<int, int>> ab;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        ab.push_back(make_pair(a, b));
    }
    sort(ab.begin(), ab.end());
    
    int left = 0;
    int cnt = 0;
    for (int i = 0; i < M; ++i) {
        if (left == N) break;
        cnt++;
        left++;
        pair<int, int> tmp = make_pair(-1, -1);
        for (int j = 0; j < M; ++j) {
            if (ab[j].first <= left && ab[j].second >= left) {
                if (tmp.second < ab[j].second) tmp = ab[j];
            }
        }
        if (tmp.first == -1 && tmp.second == -1) {
            cout << "Impossible" << endl;
            return 0;
        }
        if (tmp.second > 0) left = tmp.second;
        //cout << "left:" << left << endl;
    }
    if (left == N) cout << cnt << endl;
    else cout << "Impossible" << endl;


    return 0;
}