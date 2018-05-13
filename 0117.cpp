#include <iostream>
#include <queue>
#include "stdio.h"

using namespace std;

int s, g, V, P;

struct Road{
    Road(int t, int c)
        : to(t), cost(c) {};

    int to;
    int cost;
};

int d[20];
vector<Road> roads[100];
typedef pair<int, int> PII;


int dijkstra(int start, int goal);

int main(int argc, char const *argv[]){
    int n, m, a, b, c, d;
    cin>>n;
    cin>>m;

    for (int i = 0; i < m; i++){
        scanf("%d,%d,%d,%d", &a, &b, &c, &d);  
            roads[a].push_back(Road(b, c));
            roads[b].push_back(Road(a, d));
    }

    scanf("%d,%d,%d,%d", &s, &g, &V, &P);  

    V -= dijkstra(s, g);
    V -= dijkstra(g, s);

    cout<<V-P<<endl;
    
    return 0;
}


int dijkstra(int start, int goal){
    fill(d, d+20, 1000000);
    priority_queue<PII, vector<PII>, greater<PII> > que;
    d[start] = 0;
    que.push(PII(0, start));

    while (!que.empty()){
        PII p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < roads[v].size(); i++)
        {
            Road r = roads[v][i];
            if (d[r.to] > d[v] + r.cost)
            {
                d[r.to] = d[v] + r.cost;
                que.push(PII(d[r.to], r.to));
            }
        }
    }

    return d[goal];
}