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
    while (cin>>str, str != "0") {
        int a = 0;
        int b = 0;
        str.erase(str.begin());
        for (char s : str) {
            if (s == 'A') a++;
            if (s == 'B') b++;
        }
        if (a > b) a++;
        else b++;
        cout << a << " " << b << endl;
    }
    return 0;
}