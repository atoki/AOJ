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
    int n;
    string list = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (cin>>n, n) {
        int key[n] = {};
        string str;
        for (int i = 0; i < n; ++i) {
            cin>>key[i];
        }
        cin>>str;
        for (int i = 0; i < str.length(); ++i) {
            int num = i % n;
            int target = 0;
            for (int j = 0; j < list.length(); ++j) {
                if (str[i] == list[j]) {
                    target = j;
                    break;
                }
            }
            int lt = target - key[num];
            if (lt < 0) lt += 52; 
            str[i] = list[lt];
        }
        cout<<str<<endl;
    }
    return 0;
}