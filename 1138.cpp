#include <iostream>

using namespace std;

class State{
public:
    int city_;
    double cost_
    int used_;

    State(int city, double cost, int used) 
        : city_(city), cost_(cost), used_(used) {}

    bool operator<(const State& state) const {
        return cost_ > state.cost_;
    } 
};

class Edge{
public:
    int to_;
    int cost_;

    Edge(int to, int cost) : to_(to), cost_(cost) {}
};

vector<Edge> path[31];
int ticket[8];

int main(int argc, char const *argv[]){
    int n, m, p, a, b;

    while (cin>>n>>m>>p>>a>>b, n||m||p||a||b){
        for (int i = 0; i < p; i++){
            int from, to, cost;
            cin>>from>>to>>cost;
            path[from].push_back(Edge(to, cost));
            path[to].push_back(Edge(from, cost))
        }

        for (int i = 0; i < n; i++){
            cin>>t[i];
        }

        priority_queue<State> que;
        que.push(State(a, 0, 0));

        while(!que.empty()){

        }
    }
    return 0;
}