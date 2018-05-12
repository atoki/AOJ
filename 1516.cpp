#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

bool check(char s1, char s2) {
    if (s1 == 'A') {
        if (s2 == 'B') return true;
        if (s2 == 'D') return true;
    }
    if (s1 == 'B') {
        if (s2 == 'A') return true;
        if (s2 == 'C') return true;
        if (s2 == 'E') return true;
    }
    if (s1 == 'C') {
        if (s2 == 'B') return true;
        if (s2 == 'F') return true;
    }
    if (s1 == 'D') {
        if (s2 == 'A') return true;
        if (s2 == 'E') return true;
        if (s2 == 'G') return true;
    }
    if (s1 == 'E') {
        if (s2 == 'B') return true;
        if (s2 == 'D') return true;
        if (s2 == 'F') return true;
        if (s2 == 'H') return true;
    }
    if (s1 == 'F') {
        if (s2 == 'C') return true;
        if (s2 == 'E') return true;
        if (s2 == 'I') return true;
    }
    if (s1 == 'G') {
        if (s2 == 'D') return true;
        if (s2 == 'H') return true;
    }
    if (s1 == 'H') {
        if (s2 == 'E') return true;
        if (s2 == 'G') return true;
        if (s2 == 'I') return true;
    }
    if (s1 == 'I') {
        if (s2 == 'F') return true;
        if (s2 == 'H') return true;
    }
    return false;
}

int main (int argc, char *argv[]) {
    for (int i = 0; i < 1000; ++i) {
        string str;
        bool valid = true;
        cin >> str;
        for (int n = 0; n < str.length() - 1; ++n) {
            char s1 = str[n];
            char s2 = str[n+1];
            if (!check(s1, s2) || s1 == s2) {
                valid = false;
                break;
            }
        }
        if (valid) cout << str << endl;
    }
    return 0;
}