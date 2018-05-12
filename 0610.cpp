
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
    int H, W;
    cin >> H >> W;
    cin.ignore();
    char grid[H][W];
    int ans[H][W];
    for (int y = 0; y < H; ++y) {
        string str;
        getline(cin, str);
        for (int x = 0; x < W; ++x) {
            grid[y][x] = str[x];
            ans[y][x] = -1;
        }
    }

    for (int t = 0; t < W; ++t) {
        // move
        for (int y = 0; y < H; ++y) {
            for (int x = W - 2; x >= 0; --x) {
                if (t > 0) {
                    grid[y][x+1] = grid[y][x];
                    grid[y][x] = '.';
                }
            }
        }
        // check
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                if (grid[y][x] == 'c' && ans[y][x] == -1) {
                    ans[y][x] = t;
                }
            }
        }
    }

    for (int y = 0; y < H; ++y) {
        bool first = true;
        for (int x = 0; x < W; ++x) {
            if (first) {
                cout << ans[y][x];
                first = false;
            }
            else cout << " " << ans[y][x];
        }
        cout << endl;
    }
    return 0;
}