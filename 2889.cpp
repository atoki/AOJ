#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

bool check(string str, int s, int e) {
    if (s == e) return false;
    if (e - s == 1 && str[s] == '0') {
        return true;
    }
    if (str[s] == '0') return false;

    int num = 0;
    for (int i = s; i < e; ++i) {
        num *= 10;
        num += str[i] - '0';
    }

    if (num < 0 || num > 255) return false;

    return true;
}

int main (int argc, char *argv[]) {
    string str;
    cin >> str;

    int ans = 0;
    int len = str.length();
    for (int i = 1; i < len; ++i) {
        for (int j =  i + 1; j < len; ++j) {
            for (int k = j + 1; k < len; ++k) {
                if (check(str, 0, i) && check(str, i, j) 
                 && check(str, j, k) && check(str, k, len)) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}