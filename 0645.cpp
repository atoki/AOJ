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
    int H = 0;
    int W = 0;
    cin >> H >> W;
    int A[H][W];
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    priority_queue<pair<int, pair<int, int> > > que; // (cost, pos(x,y))
    que.push(make_pair(0, make_pair(0, 0)));
    while (!que.empty()) {
        pair<int, pair<int, int> > p = que.top();
        int cost = p.first;
        pair<int, int> pos = p.second;
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];
            if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
                if (A[ny][nx] > 0) {
                    int tmp = 2 * (pos.first + pos.second) + A[ny][nx] + 1;
                    que.push(make_pair(cost + tmp, make_pair(nx, ny)));
                }
                else {
                    que.push(make_pair(cost + 1, make_pair(nx, ny)));
                }
            }
        }
    }

    return 0;
}