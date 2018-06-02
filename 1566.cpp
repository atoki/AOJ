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
    int n;
    int ans = 0;
    cin>>n;
    vector<pair<int, int> > p;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        int tmp1, tmp2;
        cin>>tmp1>>tmp2;
        p.push_back(make_pair(tmp1, tmp2));
    }
    sort(p.begin(), p.end(), [](auto lp, auto rp){
        return lp.second < rp.second;
    });
    // for (auto e : p) {
    //     cout<<e.first<<" "<<e.second<<endl;
    // }
    for (int day = 1; day < 32; ++day) {
        int target = 0;
        bool flag1 = false;
        bool flag2 = false;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i].first <= day && day <= p[i].second) {
                flag1 = true;
                if (!visited[i] && target == 0) {
                    target = i;
                    flag2 = true;
                    visited[target] = true;
                    // cout <<i<<endl;
                }
            }
        }
        if (flag1 && flag2) ans += 100;
        if (flag1 && !flag2) ans += 50;
    }
    cout<<ans<<endl;
    return 0;
}