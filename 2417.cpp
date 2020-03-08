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
    char cl[11] = "wakstnhmyr";
    map<char, char> flick{{'T','a'}, {'L','i'}, {'U','u'}, {'R','e'}, {'D','o'}};
    string str, result;
    cin >> str;
    result = "";
    for (int i = 0; i < str.size(); i+=2) {
        int no = str[i] - '0';
        if (no == 0 && str[i+1] == 'U') {
            result += "nn";
            continue;
        }
        if (0 <= no && no <= 9 && no != 1) result.push_back(cl[no]);
        result.push_back(flick[str[i+1]]);
    }
    cout << result << endl;
    return 0;
}