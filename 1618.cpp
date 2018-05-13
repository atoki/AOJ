#include <iostream>
using namespace std;

int d, w;
int cap = 0;
int e[10][10];

int hight_of_ike(int sx, int sy, int col, int row) {
    int suii = e[sy][sx];
    for (int y = sy; y <= sy + col; ++y) {
        for (int x = sx; x <= sx + row; ++x) {
            suii = max(suii, e[y][x]);
        }
    }
    return suii;
}

int hight_of_sto(int sx, int sy, int col, int row) {
    int hight = e[sy][sx];
    for (int y = sy; y <= sy + col; ++y) {
        for (int x = sx; x <= sx + row; ++x) {
            if (y > sy && y < sy + col && x > sx && x < sx + row) continue;
            hight = min(hight, e[y][x]);
        }
    }
    return hight;
}

int get_cap(int sto, int sx, int sy, int col, int row) {
    int tmp = 0;
    for (int y = sy; y <= sy + col; ++y) {
        for (int x = sx; x <= sx + row; ++x) {
            tmp += sto - e[y][x];
        }
    }
    return tmp;
}

int main() {
    while(cin >> d >> w, d||w) {
        cap = 0;
        for (int y = 0; y < d; ++y) {
            for (int x = 0; x < w; ++x) {
                cin >> e[y][x];
            }
        }
        for (int sy = 1; sy < d - 1; ++sy) {
            for (int sx = 1; sx < w - 1; ++sx) {
                for (int col = 0; sy + col < d - 1; ++col) {
                    for (int row = 0; sx + row < w - 1; ++row) {
                        int ike = hight_of_ike(sx, sy, col, row);
                        int sto = hight_of_sto(sx-1, sy-1, col+2, row+2);
                        if (sto - ike > 0) {
                            cap = max(cap, get_cap(sto, sx, sy, col, row));
                        }
                    }
                }
            }
        }
        cout << cap << endl;
    }
    return 0;
}