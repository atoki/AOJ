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
    int m, n;
    while (cin >>m, m) {
        vector<pair<int, int>> target;
        vector<pair<int, int>> picture;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            target.push_back(make_pair(a, b));
        }

        cin >> n;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            picture.push_back(make_pair(a, b));
        }

        for (int i = 0; i < n; ++i) {
            int dx = picture[i].first - target[0].first;
            int dy = picture[i].second - target[0].second;

            int match_count = 0;
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < m; ++k) {
                    if ((picture[j].first == target[k].first + dx) 
                    && (picture[j].second == target[k].second + dy)) {
                        match_count++;
                    }
                }
            }
            
            if (match_count == m) {
                cout << dx << ' ' << dy << endl;
                break;
            }
        }
    }

    return 0;
}