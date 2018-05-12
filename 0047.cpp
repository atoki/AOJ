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
    string str;
    bool l, c, r;
    l = true;
    c = false;
    r = false;
    while (cin>>str) {
        char left = str[0];
        char right = str[2];
        if ((left == 'A' && right == 'B') || (left == 'B' && right == 'A')) {
            swap(l, c);
        }
        else if ((left == 'A' && right == 'C') || (left == 'C' && right == 'A')) {
            swap(l, r);
        }
        else {
            swap(c, r);
        }
    }
    if (l) cout<<'A'<<endl;
    if (c) cout<<'B'<<endl;
    if (r) cout<<'C'<<endl;
    return 0;
}