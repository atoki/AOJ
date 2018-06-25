#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

bool check(string str) {
    int sum = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (i % 2 == 1) {
            int n = (str[i] - '0') * 2;
            if (n > 10) n = 1 + n % 10;
            sum += n;
        }
        else {
            sum += (str[i] - '0');
        }
    }
    return sum % 10 == 0;
}

int main (int argc, char *argv[]) {
    int n, m;
    string id;
    int a[10];
    cin>>n;
    cin>>id;
    cin>>m;
    for (int i = 0; i < m; ++i) {
        cin>>a[m];
    }
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '*') cnt++:
    }
    
    for (int i = 0; i < cnt; ++i) {
        
    }

    check(id);

    return 0;
}