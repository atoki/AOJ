#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main (int argc, char *argv[]) {
    int pasta[3];
    int juce[2];
    int ans = INT_MAX;
    cin >> pasta[0];
    cin >> pasta[1];
    cin >> pasta[2];
    cin >> juce[0];
    cin >> juce[1];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            ans = min(ans, pasta[i] + juce[j] - 50);
        }
    }

    cout << ans << endl;

    return 0;
}