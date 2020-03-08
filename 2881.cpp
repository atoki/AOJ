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
    string str;
    int y, m, d;
    while (cin >> str, str != "#") {
        cin >> y >> m >> d;
        if (y > 31 || (y == 31 && m >= 5)) {
            printf("? %d %d %d\n", y - 30, m, d);
        }
        else {
            printf("HEISEI %d %d %d\n", y, m, d);
        }
    }
    return 0;
}