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
    int r, c;
    while(cin >> r >> c, r||c) {
        if (r % 2 == 0 || c % 2 == 0) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}