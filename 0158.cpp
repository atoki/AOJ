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
    while (cin>>n, n) {
        int cnt = 0;
        while(n != 1) {
            if (n % 2 == 0) {
                n /= 2;
                cnt++;
            }
            else {
                n = n * 3 + 1;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}