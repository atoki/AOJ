#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct State {
    int x_;
    int y_;
    int t_;

    State(int x, int y, int t) {
        x_ = x;
        y_ = y;
        t_ = t;
    }
};

int main (int argc, char *argv[]) {
    int n, t;
    int dx[6] = {1, 1, 0, -1, -1, 0};
    int dy[6] = {0, 1, 1, 0, -1, -1};
    while (cin>>t>>n, t||n) {
        int sx, sy;
        bool ob[200][200] = {false};
        bool visited[200][200] = {false};
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin>>x>>y;
            ob[x+100][y+100] = true;
        }
        cin>>sx>>sy;
        queue<State> que;
        que.push(State(sx, sy, 0));
        visited[sx+100][sy+100] = true;
        while (!que.empty()) {
            State s = que.front();
            que.pop();
            for (int i = 0; i < 6; ++i) {
                int nx = s.x_ + dx[i];
                int ny = s.y_ + dy[i];
                if (!visited[nx+100][ny+100] && !ob[nx+100][ny+100] && s.t_ < t) {
                    que.push(State(nx, ny, s.t_ + 1));
                    // printf("(%d, %d)\n", nx, ny);
                    visited[nx+100][ny+100] = true;
                    ans++;
                }
            }
        }
        cout<<ans + 1<<endl;
    }
    return 0;
}