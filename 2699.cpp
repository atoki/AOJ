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
    double d, e;
    while (cin>>d>>e, d||e) {
        double ans = 1000000.0;
        for (double x = 0.0; x <= d / 2; ++x) {
            double y = d - x;
            ans = min(ans, abs(sqrt(pow(x, 2)+pow(y, 2)) - e));
        }
        cout<<ans<<endl;
    }
    return 0;
}