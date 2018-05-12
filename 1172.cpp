#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAX = 123456 * 2 + 1;

int main (int argc, char *argv[]) {
    int n;
    vector<bool> v(MAX, true);
    for (int i = 2; i < sqrt(MAX); ++i) {
        if (v[i]) {
            for (int j = 0; i*(j+2) < MAX; ++j) {
                v[i*(j+2)] = false;
            }
        }
    }
    while (cin>>n, n) {
        int ans = 0;
        for (int i = n+1; i <= 2*n; ++i) {
            if (v[i]) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}