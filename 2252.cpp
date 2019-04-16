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
    string right = "yuiophjklnm";
    string left = "qwertasdfgzxcvb";
    string str;
    while (cin>>str, str != "#") {
        int ans = 0;
        int side = 0; // left:0, right:1
        auto iter = find(left.begi(), left.end(), str[0]);
        if (iter == left.end()) side = 1;
        for (int i = 0; i < str.length(); ++i) {
            if (side == 0) {
                auto iter = find(left.begin(), left.end(), str[i]);
                if (iter == left.end()) {
                    ans++;
                    side = 1;
                }
            }
            else {
                auto iter = find(right.begin(), right.end(), str[i]);
                if (iter == right.end()) {
                    ans++;
                    side = 0;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}