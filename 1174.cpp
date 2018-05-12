#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int h, w, c;
vector<vector<int>> grid;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<int>> change(const vector<vector<int>>& g, int color) {
    vector<vector<int>> v = g;
    vector<pair<int, int>> vertices;
    bool visited[8][8] = {false}; 
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    int target = v[0][0];
    while (!que.empty()) {
        auto vec = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = vec.first + dx[i];
            int ny = vec.second + dy[i];
            if (0 <= nx && nx < w && 0 <= ny && ny < h 
                && !visited[ny][nx] && v[ny][nx] == target) {
                visited[ny][nx] = true;
                vertices.push_back(make_pair(nx, ny));
                que.push(make_pair(nx, ny));
            }
        }
    }
    v[0][0] = color;
    for (auto ver : vertices) {
        v[ver.second][ver.first] = color;
    }
    return v;
}

int count(const vector<vector<int>>& g) {
    int count = 1;
    bool visited[8][8] = {false}; 
    visited[0][0] = true;
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    int target = g[0][0];
    while (!que.empty()) {
        auto vec = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = vec.first + dx[i];
            int ny = vec.second + dy[i];
            if (0 <= nx && nx < w && 0 <= ny && ny < h 
                && !visited[ny][nx] && g[ny][nx] == target) {
                visited[ny][nx] = true;
                que.push(make_pair(nx, ny));
                count++;
            }
        }
    }
    return count;
}

int solve() {
    int ans = 0;
    queue<pair<vector<vector<int>> , int>> que;
    que.push(make_pair(grid, 0));
    while(!que.empty()) {
        auto front = que.front();
        que.pop();
        auto g = front.first;
        int depth = front.second;
        if (depth < 4) {
            for (int i = 1; i < 7; ++i) {
                auto tmp_grid = change(g, i);
                que.push(make_pair(tmp_grid, depth+1));
            }
        }
        else {
            auto tmp_grid = change(g, c);
            ans = max(ans, count(tmp_grid));
        }
    }
    cout<<ans<<endl;
}

int main (int argc, char *argv[]) {
    while (cin>>h>>w>>c, h||w||c) {
        for (int y = 0; y < h; ++y) {
            vector<int> tmp;
            for (int x = 0; x < w; ++x) {
                int t;
                cin>>t;
                tmp.push_back(t);
            }
            grid.push_back(tmp);
        }
        solve();
        grid.clear();
    }
    return 0;
}