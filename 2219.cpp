#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
 
int main(){
    int n,m;
    int d[300][4];
    int dp[3][301];
    string tmp;
 
    while(cin >> n >> m) {
        // input
        for(int i = 0; i < n; i++) {
            cin.ignore();
            getline(cin, tmp);
            for(int j = 0; j < 4; j++) cin >> d[i][j];
        }
        // init
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j <= m; j++) dp[i][j] = 0;
        }
    
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                dp[j][d[i][0]] = max(dp[j][d[i][0]], d[i][j+1]);
            }
        }
        // dp
        for(int i = 0; i < 3; i++) {
            for(int j = 1; j <= m; j++) {
                for(int k = 0; k <= j/2; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[i][j-k]);
                }
            }
        }
    
        int ans = 0;
        for(int i = 0; i < 3; i++) {
            ans = max(ans, dp[i][m]);
        }
        cout << ans << endl;
    }
}

// #include <iostream>
// #include <cstdio>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <map>
// #include <string>
// #include <algorithm>

// using namespace std;

// int main (int argc, char *argv[]) {
//     int n, m;
//     int c, v, d, l, total; 
//     cin>>n>>m;
//     int cost[300] = {};
//     int value[300] = {};
//     for (int i = 0; i < n; ++i) {
//         cin>>c>>v>>d>>l;
//         total = v + d + l;
//         cost[i] = c;
//         value[i] = total;
//     }
//     int dp[100000][100000] = {0};
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             if (j > cost[i]) {
//                 dp[i+1][j] = max(dp[i][m-cost[i]] + value[i], dp[i][m]);
//             }
//             else dp[i+1][m] = dp[i][j];
//         }
//     }
//     cout<<dp[n][m]<<endl;
//     return 0;
// }