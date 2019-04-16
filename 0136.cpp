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
    double h;
    vector<int> v(6, 0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> h;
        if (h >= 185.0) v[5]++;
        else if (185.0 > h && h >= 180.0) v[4]++;
        else if (180.0 > h && h >= 175.0) v[3]++;
        else if (175.0 > h && h >= 170.0) v[2]++;
        else if (170.0 > h && h >= 165.0) v[1]++;
        else v[0]++;
    }

    for (int i = 0; i < 6; ++i) {
        cout << i + 1 << ":";
        for (int j = 0; j < v[i]; ++j) {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}