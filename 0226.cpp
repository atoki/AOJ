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
    string str1, str2;
    while (cin>>str1>>str2, str1.length() != 1) {
        int hit = 0;
        int blow = 0;
        for (int i = 0; i < 4; ++i) {
            if (str1[i] == str2[i]) hit++;
            for (int j = 0; j < 4; ++j) {
                if (i == j) continue;
                if (str1[i] == str2[j]) blow++;
            }
        }
        cout<<hit<<" "<<blow<<endl;
    }
    return 0;
}