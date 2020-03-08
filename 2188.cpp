#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> split(const string& input, char delimiter) {
    istringstream stream(input);
    string field;
    vector<string> result;
    while (getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}

int main (int argc, char *argv[]) {
    map<string, int> mp{
        {"yotta", 24},
        {"zetta", 21},
        {"exa", 18},
        {"peta", 15},
        {"tera", 12},
        {"giga", 9},
        {"mega", 6},
        {"kilo", 3},
        {"hecto", 2},
        {"deca", 1},
        {"deci", -1},
        {"centi", -2},
        {"milli", -3},
        {"micro", -6},
        {"nano", -9},
        {"pico", -12},
        {"femto", -15},
        {"ato", -18},
        {"zepto", -21},
        {"yocto", -24}
    };

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string str;
        getline(cin, str);
        vector<string> vs = split(str, ' ');
        string num = vs[0];
        string prefix = (vs.size() == 2) ? "*" : vs[1];
        string unit = (vs.size() == 2) ? vs[1] : vs[2];
        // cout << vs[0] << " " << prefix << " " << unit << endl;

        
    }

    return 0;
}