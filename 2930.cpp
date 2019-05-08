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

    cin >> n >> m;
    vector<int> v1(n), v2(m);

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> v1[i];
    }
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> v2[i];
    }

    vector<int> seki, wa;
    set_intersection(v1.begin(), v1.end(),
                     v2.begin(), v2.end(),
                     std::inserter(seki, seki.end()));
    set_union(v1.begin(), v1.end(),
              v2.begin(), v2.end(),
              std::inserter(wa, wa.end()));

    cout << seki.size() << " " << wa.size() << endl;
    for (int e : seki) {
        cout << e << endl;
    }
    for (int e : wa) {
        cout << e << endl;
    }

    return 0;
}