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
    int a, b, c;
    cin >> a >> b >> c;

    if  (c > a && a + b == 60) {
        cout << "-1" << endl;
        return 0;
    }

    int t = 0;
    int count = 0;
    int ans = -1;
    int last_diff = 0;
    int d = 0;
    while (1) {
        int lower = count * (a + b);
        int upper = lower + a;
        if (d < lower) t++;
        d = 60 * t + c;
        if (count > 0 && lower % 60 == 0) break;
        if (lower <= d && d <= upper) {
            ans = d;
            break;
        }
        count++;
    }

    cout << ans << endl;

    return 0;
}