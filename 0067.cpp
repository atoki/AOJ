#include <iostream>
using namespace std;

string map[12];

void dfs(int x, int y){
    map[y][x] = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < 12 && 0 <= ny && ny < 12 && map[ny][nx] == '1'){
            dfs(nx, ny);
        }
    }
}

int main(int argc, char const *argv[]){
    int ans;q

    while(1){
        ans = 0;
        for (int i = 0; i < 12; i++){
            cin>>map[i];
        }

        if (cin.eof()) break;

        for (int i = 0; i < 12; i++){
            for (int j = 0; j < 12; j++){
                if (map[i][j] == '1'){
                    dfs(j, i);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}