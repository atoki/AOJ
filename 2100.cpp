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
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        int up = 0;
        int down = 0;
        
        cin >> n;
        vector<int> v(n, 0);

        for (int j = 0; j < n; ++j) {
            cin >> v[j];
        }

        for (int j = 0; j < n; ++j) {
            if (j < n - 1) {
                up = max(up, v[j + 1] - v[j]);
            }
            if (j > 0) {
                down = max(down, v[j - 1] - v[j]);
            }
        }

        cout << up << " " << down << endl;
    }
    return 0;
}