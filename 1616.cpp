#include <iostream>
using namespace std;

int main() {
    int n, m, a;
    int item[1000];
    while (cin >> n >> m, n||m) {
        int sum  = -1;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            item[i] = a;
        }

        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                int tmp = item[i] + item[j];
                if (tmp <= m && tmp > sum) {
                    sum = tmp;
                }
            }
        }

        if (sum < 0) cout << "NONE" << endl;
        else cout << sum << endl;
    }
    return 0;
}