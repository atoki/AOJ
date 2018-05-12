#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAX = 1000001;

int main() {
    bool h[MAX] = {};
    for(int i = 1;i < MAX; i *= 2){
        for(int j = i; j < MAX; j *= 3){
            for(int k = j; k < MAX; k *= 5 ) h[k]=1;
        }
    }
    int m;
    while(cin >> m, m) {
        int n, count = 0;
        cin >> n;
        for(int i = m;i <= n; i++) if(h[i]) count++;
        cout << count << endl;
    }
}