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

const int MAX = 50001;

int main (int argc, char *argv[]) {
    vector<bool> v(MAX, true);
    vector<int> num(MAX, 0);
    for (int i = 2; i < sqrt(MAX); ++i) {
        if (v[i]) {
            for (int j = 0; i*(j+2) < MAX; ++j) {
                v[i*(j+2)] = false;
            }
        }
    }
    for (int i = 2; i < MAX/2 + 1; ++i) {
        if (v[i]) {
            for (int j = i; j < MAX; ++j) {
                if (v[j] && i+j <= MAX) {
                    num[i+j]++;
                }
            }
        }
    }
    int n;
    while (cin>>n, n) {
        cout<<num[n]<<endl;
    }

    return 0;
}