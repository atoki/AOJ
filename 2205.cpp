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
    int n, m;

    while (cin >> n >> m, n||m) {
        vector<pair<string, int>> tk;
        vector<string> lo;
        for (int i = 0; i < n; ++i) {
            string str;
            int num;
            cin >> str >> num;
            tk.push_back(make_pair(str, num));
        }

        for (int i = 0; i < m; ++i) {
            string str;
            cin >> str;
            lo.push_back(str);
        }

        int ans = 0;
        for (string l : lo) {
            for (pair<string, int> t : tk) {
                string ts = t.first;
                int tn = t.second;
                for (int i = 0; i < l.length(); ++i) {
                    if (ts[i] == '*' && i == l.length() - 1) {
                        ans += tn;
                        break;
                    }
                    if (ts[i] == '*' && i < l.length() - 1) continue;
                    if (ts[i] != l[i]) break;
                    if (i == l.length() - 1) {
                        ans += tn;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
        
    }


    return 0;
}