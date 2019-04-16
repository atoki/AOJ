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
    int w, h;
    while(cin >> w >> h, w||h) {
        int ans = 0;
        int grid[h][w]; // @:1, #:2, *:3
        bool trace[h][w] = {false};

        for (int y = 0; y < h; ++y) {
            char tmp[w];
            scanf("%s\n", tmp);
            for (int x = 0; x < w; ++x) {
                if (tmp[x] == '@') grid[y][x] = 1;
                if (tmp[x] == '#') grid[y][x] = 2;
                if (tmp[x] == '*') grid[y][x] = 3;
            }
        }

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (!trace[y][x]) {
                    ans++;
                    int fg = grid[y][x];
                    stack<pair<int, int> > st;
                    st.push(make_pair(x, y));
                    while(!st.empty()) {
                        pair<int, int> top = st.top();
                        st.pop();
                        trace[top.second][top.first] = true;
                        for (int i = 0; i < 4; ++i) {
                            int nx = top.first + dx[i];
                            int ny = top.second + dy[i];
                            if (grid[ny][nx] == fg && !trace[ny][nx]
                            && nx >=0 && nx < w && ny >=0 && ny < h) {
                                st.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}