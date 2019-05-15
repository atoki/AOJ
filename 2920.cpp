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
    int n, ans;
    cin >> n;
    vector<int> v(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    ans = 0;
    bool flag = 0;
    int store = 0;
    for (int i = n; i >= 0; --i) {
        if (v[i] % 2 == 0) {
            ans += v[i];
        }
        else {
            if (flag) {
                ans += v[i] + store;
                flag = false;
            }
            else {
                store = v[i];
                flag = true;
            }
        }
    }

    cout << ans / 2 << endl;

    return 0;
}