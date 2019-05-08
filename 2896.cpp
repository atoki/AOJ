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
    int n, m;
    int count = 0;

    cin >> n >> m;

    vector<bool> v(n, false);

    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        v[tmp - 1] = true;
    }

    int current = 0;
    int absent = 0;
    while (1) {
        if (current == m) break;

        if (!v[current]) {
            int last = 0;
            for (int i = 0; i < n; ++i) {
                if (v[i]) last = i; 
            }
            v[current] = true;
            v[last] = false;
            count++;
            current = 0;
            continue;
        }

        current++;
    }

    cout << count << endl;

    return 0;
}