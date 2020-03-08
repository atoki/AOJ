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
    while(cin>>n>>m, n||m){
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = i + 1;
        }

        int cnt = 0;
        for(int i = 1; i < m + 1; i++) {
            string str;
            cin >> str;

            if (ans.size() == 1) continue;

            string current_str = "";
            if (i % 5 == 0 && i % 3 == 0) current_str = "FizzBuzz";
            else if (i % 3 == 0) current_str = "Fizz";
            else if (i % 5 == 0) current_str = "Buzz";
            else current_str = to_string(i);

            // printf("%d: %s (%s)\n", cnt, str.c_str(), current_str.c_str());

            if (str != current_str) {
                ans.erase(ans.begin() + cnt);
            }
            else {
                cnt++;
            }

            cnt = cnt % ans.size();
        }
        
        bool first = true;
        for (int e : ans) {
            if (!first) cout << " ";
            cout << e;
            if (first ) first = false;
        }
        cout << endl;
    }
    return 0;
}