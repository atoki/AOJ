#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main (int argc, char *argv[]) {
    int n,m;	
    cin >> n >> m;
    vector<int> w(n),b(n),r(n);
    for(int i = 0; i < n; i++) {
        string s; 
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j]=='W') w[i]++;
            else if(s[j]=='R') r[i]++;
            else if(s[j]=='B') b[i]++;
        }
    }

    int ans = INT_MAX;
    for(int i = 0; i < n - 2; i++) {
        int tmp1 = 0;
        for(int j = 0; j <= i; j++) tmp1 += b[j] + r[j];
        for(int j = i + 1; j < n - 1; j++) {
            int tmp2 = 0;
            for(int k = i + 1; k <= j; k++ ) tmp2 += w[k] + r[k];
            for(int k = j + 1; k < n; k++) tmp2 += w[k] + b[k];
            ans = min(ans, tmp1 + tmp2);
        }
    }
    cout << ans << endl;

    return 0;
}