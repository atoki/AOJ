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
    int n, total;
    while (cin>>n, n) {
        total = 0;
        for (int i = 0; i < 9; ++i) {
            int tmp;
            cin>>tmp;
            total += tmp;
        }
        cout<<n - total<<endl;
    }
    return 0;
}