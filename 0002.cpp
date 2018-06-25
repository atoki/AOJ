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
    int a, b;
    while (cin>>a>>b) {
        int sum = a + b;
        int cnt = 1;
        while (sum /= 10) {
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}