#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

constexpr int MAX = 300;

int main (int argc, char *argv[]) {
    int n;
    vector<int> w(MAX);

    while (cin>>n, n) {
        // input
        for (int i = 0; i < n; ++i) {
            cin>>w[i];
        }

        // solve
        vector<int> diff(MAX);
        for (int i = 0; i < n-1; ++i) {
            diff[i] = abs(w[i+1] - w[i]); 
        }
        
        
        // clear
        w.clear();
        diff.clear();
    }

    return 0;
}