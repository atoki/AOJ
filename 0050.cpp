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
    string a = "apple";
    string p = "peach";
    getline(cin, str);

    auto pos = 0;
    if (str.find(a) < str.find(p)) {
        pos = str.find(a);
        str.replace(pos, a.length(), p);
        pos += a.length();
    }
    else {
        pos = str.find(p);
        str.replace(pos, p.length(), a);
        pos += p.length();
    }

    while (pos < str.length() - 5) {
        int a_pos = str.find(a, pos);
        int p_pos = str.find(p, pos);
        if (a_pos < 0) a_pos = p_pos + 1;
        if (p_pos < 0) p_pos = a_pos + 1;
        if (abs(a_pos) < abs(p_pos)) {
            pos = str.find(a, pos);
            str.replace(pos, a.length(), p);
            pos += a.length();
        }
        else {
            pos = str.find(p, pos);
            str.replace(pos, p.length(), a);
            pos += p.length() ;
        }
    }

    cout << str << endl;
    return 0;
}