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
    cin>>str;
    if (str.length() < 6) {
        cout<<"INVALID"<<endl;
        return 0;
    }
    bool contn = false;
    bool contb = false;
    bool conts = false;
    for (int i = 0; i < str.length(); ++i) {
        if ('0' <= str[i] && str[i] <= '9') contn = true;
        if ('A' <= str[i] && str[i] <= 'Z') contb = true;
        if ('a' <= str[i] && str[i] <= 'z') conts = true;
    }
    if (contn && contb && conts) {
        cout<<"VALID"<<endl;
    }
    else cout<<"INVALID"<<endl;
    return 0;
}