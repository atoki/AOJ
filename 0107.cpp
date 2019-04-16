#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main (int argc, char *argv[]) {
    int d, w, h, n;
    int r[10000];
    while (cin >> d >> w >> h, d) {
        cin >> n;
        double d1, d2, d3;
        d1 = d*d + w*w;
        d2 = d*d + h*h;
        d3 = w*w + h*h;
        for (int i = 0; i < n; ++i) {
            double r = 0.0;
            cin >> r;
            double result = min({d1, d2, d3});
            if (4 * r * r > result) cout << "OK" << endl;
            else cout << "NA" << endl;
        }
    }
    return 0;
}