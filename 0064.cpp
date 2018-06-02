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
    int ans;
    while (cin>>str) {
        for (int i = 0; i < str.length(); ++i) {
            if ('0' <= str[i] && str[i] <= '9') {
                int tmp = 0;
                int cnt = 0;
                for (int j = i; j < str.length(); ++j) {
                    if ('0' <= str[j] && str[j] <= '9') {
                        tmp = 10 * tmp + (str[j] - '0');
                        cnt++;
                    }
                    else break;
                }
                i += cnt;
                ans += tmp;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}