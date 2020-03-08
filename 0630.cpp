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
    int A, B, C, D, E;
    int ans = 0;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;
    cin >> E;

    int flag = true;
    while (A != B) {
        if (A < 0) {
            A += 1;
            ans += C;
        }
        else if (A == 0 && flag) {
            ans += D;
            flag = false;
        }
        else {
            A += 1;
            ans += E;
        }
    }
    cout << ans << endl;

    return 0;
}