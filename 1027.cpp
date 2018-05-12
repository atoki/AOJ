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
    int k;
    while(cin >> k, k) {
        int size = int(k * (k-1) / 2);
        int sum = 0;
        for(int i = 0; i < size; ++i) {
            int tmp;
            cin >> tmp;
            sum += tmp;
        }
        cout << int(sum / max(1, k - 1)) << endl;
    }

    return 0;
}