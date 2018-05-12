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
    string str, tmp;
    vector<string> v;
    getline(cin, str);
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ' || str[i] == ',' || str[i] == '.') {
            v.push_back(tmp);
            tmp.clear();
            continue;
        }
        tmp.push_back(str[i]);
    }
    
    bool first = true;
    for (auto ss : v) {
        if (ss.length() > 2 && ss.length() < 7) {
            if (first) {
                cout<<ss; 
                first=false;
            }
            else cout <<" "<<ss;
        }
    }
    cout<<endl;
    return 0;
}