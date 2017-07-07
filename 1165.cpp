#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

constexpr int MAX = 200;
bool grid[2 * MAX][2 * MAX];

struct Cor {
    // constructer
    Cor(int x, int y) : x_(x), y_(y) {}

    // field
    int x_;
    int y_;
};

int main (int argc, char *argv[]) {
    int N, n, d;
    vector<Cor> cs;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    // input
    while (cin>>N, N) {
        // init
        for (int i = 0; i < 2 * MAX; ++i) {
            for (int j = 0; j < 2 * MAX; ++j) {
                grid[i][j] = false;
            }
        }

        grid[200][200] = true;
        cs.push_back(Cor(200, 200));
        for (int i = 0; i < N-1; ++i) {
            cin>>n>>d;
            int nx = cs[n].x_ + dx[d];
            int ny = cs[n].y_ + dy[d];
            grid[ny][nx] = true;
            cs.push_back(Cor(nx, ny));
        }

        // ans
        int max_x = 200;
        int min_x = 200;
        int max_y = 200;
        int min_y = 200;
        for (int y = 0; y < 2 * MAX; ++y) {
            for (int x = 0; x < 2 * MAX; ++x) {
                if (grid[y][x] == true) {
                    max_x = max(max_x, x);
                    min_x = min(min_x, x);
                    max_y = max(max_y, y);
                    min_y = min(min_y, y);
                }
            }
        }

        cout<<max_x - min_x + 1<<" "<<max_y - min_y + 1<<endl;

        // clear
        cs.clear();
    }


    return 0;
}