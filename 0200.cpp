#include <iostream>
using namespace std;

const int INF = 100000000;

int main(int argc, char const *argv[]){
    int n, m, k;
    int cost[100][100];
    int time[100][100];

    while (cin>>n>>m, n||m){
        for (int i = 0; i < 100; i++){
            for (int j = 0; j < 100; j++){
                if (i == j) {
                    cost[i][j] = 0;
                    time[i][j] = 0;
                }
                else{
                    cost[i][j] = INF;
                    time[i][j] = INF;
                }
            }
        }

        for (int i = 0; i < n; i++){
            int a, b, c, t;
            cin>>a>>b>>c>>t;
            a--; b--;

            cost[a][b] = c;
            cost[b][a] = c;
            time[a][b] = t;
            time[b][a] = t;
        }

        for (int s = 0; s < m; s++){
            for (int i = 0; i < m; i++){
                for (int j = 0; j < m; j++){
                    cost[i][j] = min(cost[i][j], cost[i][s] + cost[s][j]);
                    time[i][j] = min(time[i][j], time[i][s] + time[s][j]);
                }
            }
        }

        cin>>k;
        for (int i = 0; i < k; i++)
        {
            int p, q, r;
            cin>>p>>q>>r;
            p--; q--;

            if (r){
                cout<<time[p][q]<<endl;
            }
            else{
                cout<<cost[p][q]<<endl;
            }
        }
    }

    return 0;
}