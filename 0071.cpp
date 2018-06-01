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
    int n;
    cin>>n;
    cin.ignore();
    for (int k = 0; k < n; ++k) {
        int grid[8][8];
        int x, y;
        for (int i = 0; i < 8; ++i) {
            string str;
            cin>>str;
            for (int j = 0; j < 8; ++j) {
                grid[i][j] = str[j] - '0';
            }
        }
        cin>>x;
        cin>>y;
        cin.ignore();

        int dx[12] = {1, 2, 3, 0, 0, 0, -1, -2, -3, 0, 0, 0};
        int dy[12] = {0, 0, 0, 1, 2, 3, 0, 0, 0, -1, -2, -3};
        vector<pair<int, int> > p;
        p.push_back(make_pair(x-1, y-1));
        while (!p.empty()) {
            auto pos = p.back();
            grid[pos.second][pos.first] = 0;
            p.pop_back();
            for (int i = 0; i < 12; ++i) {
                int nx = pos.first + dx[i];
                int ny = pos.second + dy[i];
                if (0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
                    if (grid[ny][nx] == 1) p.push_back(make_pair(nx, ny));
                }
            }
        }

        printf("Data %d:\n", k+1);
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cout<<grid[i][j];   
            }
            cout<<endl;
        } 
    }
    return 0;
}