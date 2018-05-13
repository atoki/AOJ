#include <iostream>
#include <vector>
#include <queue>
#include "stdio.h"
using namespace std;

const int INF = 10000000;

struct Edge{
    Edge(int t, int c)
        : to(t), cost(c) {}

    int to;
    int cost;
};

bool visited[100];
typedef pair<int, int> PII;
vector<Edge> G[100];

int prim(int start){
    int ans = 0;
    fill(visited, visited+100, false);

    priority_queue<PII, vector<PII>, greater<PII> > que;

    que.push(PII(0, start));
    while (!que.empty()){
        PII p = que.top();
        int v = p.second;
        int cst = p.first;
        que.pop();
        if (visited[v]) continue;
        visited[v] = true;
        ans += cst;
        for (int i = 0; i < G[v].size(); i++){
            Edge e = G[v][i];
            if (!visited[e.to]){
                que.push(PII(e.cost, e.to));
            }
        }
    }

    for (int i = 0; i < 100; i++){
        G[i].clear();
    }
    
    return ans;
} 

int main(int argc, char const *argv[]){
    int n, m;

    while (cin>>n, n){
        cin>>m;
        for (int i = 0; i < m; i++){
            int a, b, d;
            scanf("%d,%d,%d", &a, &b, &d);
            d = (d-100) / 100;
            G[a].push_back(Edge(b, d));
            G[b].push_back(Edge(a, d));
        }

        cout<<prim(0)<<endl;
    }

    return 0;
}