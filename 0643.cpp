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
    vector<vector<int>> grid(H, vector<int>(W, 0));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    int ans = 1e8;
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            int tmp = 0;
            for (int ha = 0; ha < H; ++ha) {
                for (int wa = 0; wa < W; ++wa) {
                    tmp += min((grid[ha][wa] * abs(h - ha)), (grid[ha][wa] * abs(w - wa)));
                }
            }
            ans = min(ans, tmp);    
        }
    }

    cout << ans << endl;

    return 0;
}