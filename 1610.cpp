#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

constexpr int MAX = 7368792;

int main(int argc, char const *argv[]) {
    int m, n;
    bool flag[MAX];

    while (cin>>m>>n, m||n) {
        // init
        for (int i = 0; i < MAX; ++i) {
            flag[i] = false;
        }
        for (int i = 0; i < m; ++i) {
            flag[i] = true;
        }

        // solve
        for (int i = m; i < MAX; ++i) {
            if (n == 0) break;
            if (flag[i]) continue;
            for (int j = i; j < MAX; j += i) {
                flag[j] = true;
            }
            n--;
        }

        // check
        int k;
        for (k = 0; k < MAX; ++k) {
            if (!flag[k]) break;
        }
        cout<<k<<endl;
    }
    return 0;
}