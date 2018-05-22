#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

string str;

void put(char turn) {
    char target = (turn == 'o') ? 'x' : 'o';
    int left = 0, right = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == target) left++;
        else break;
    }
    for (int i = str.length() - 1; i >= 0; --i) {
        if (str[i] == target) right++;
        else break;
    }

    if (left == 0 && right == 0) return;
    if (left >= right) {
        for (int i = 0; i < left; ++i) str[i] = turn;
        str = turn + str;
    }
    if (left < right) {
        for (int i = str.length() - 1; i >= str.length() - right; --i) str[i] = turn;
        str = str + turn;
    }
}

bool finish() {
    char c = str[0];
    bool finish = true;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != c) finish = false;
    }
    return finish;
}

int main (int argc, char *argv[]) {
    getline(cin, str);
    char turn = 'o';
    while(!finish()) {
        put(turn);
        turn = (turn == 'o') ? 'x' : 'o';
    }
    cout<<str[0]<<endl;
    return 0;
}