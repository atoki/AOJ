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
    int n, m, a;
    while (cin>>n>>m>>a, n || m || a) {
        vector<tuple<int, int, int>> bars;
        for (int i = 0; i < m; ++i) {
            int h, p, q;
            cin>>h>>p>>q;
            tuple<int, int, int> bar = make_tuple(h, p, q);
            bars.push_back(bar);
        }
        // for(auto b : bars) {
        //         cout << get<0>(b) << endl;
        // }
        int hh = ;
        int ans = a;
        sort(bars.begin(), bars.end(), [](auto lb, auto rb) {
            return get<0>(lb) > get<0>(rb);
        });
        while(hh == 1) {
            for(auto b : bars) {
                if (get<0>(b)  hh && (get<1>(b) == ans || get<2>(b) == ans)) {
                    hh = get<0>(b);
                    if (get<1>(b) == ans) {
                        ans = get<2>(b);
                        cout << ans <<endl;
                    }
                    else {
                        ans = get<1>(b);
                        cout << ans <<endl;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}