#include <iostream>

using namespace std;

int dp[10000];

int rec_dp(int n){
    if (dp[n] > 0){
        cout<<"dp="<<dp[n]<<endl;
        return dp[n];
    }

    if (n == 0){
        return 1;
    }

    if (n < 0){
        return 0;
    }

    return dp[n] = rec_dp(n-1) + rec_dp(n-2) + rec_dp(n-3);
}

int rec(int n){
    if (n == 0){
        return 1;
    }

    if (n < 0){
        return 0;
    }

    return rec(n-1) + rec(n-2) + rec(n-3);
}

int main(int argc, char const *argv[]){
    int n;

    // while (cin>>n, n){
    //     fill(dp, dp+10000, 0);
    //     cout<<rec(n)/10/365 + 1<<endl;
    //     cout<<rec_dp(n)/10/365 + 1<<endl;        
    // }

    int d[31] = {1,1,2};
    for (int i = 3; i <= 30; i++){
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
    while (cin>>n, n){
        cout<<d[n]/10/365 + 1<<endl;
    }

    return 0;
}