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
    int n;
    string str;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        vector<char> m(52, '1');
        int p = 26;

        cin >> str;
        for (int i = 0; i < str.length(); ++i) {
            if (i == 0) m[p] = str[i];
            if (i % 3 == 0 && i > 0) m[p] = str[i];
            if (i % 3 == 2) {
                if (str[i] == '>') p++;
                else p--;
            }
        }
        string ans = "";
        for(int i = 0; i < 52; i++) {
            if (m[i] != '1') {
                ans += m[i];
            }
        }
        cout << ans << endl;
    }

    return 0;
}