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
    const int NUM = 60001;
    vector<bool> prime(NUM, true);
    prime[1] = false;
    for (int i = 2; i < NUM; ++i) {
        if (prime[i]) {
            for (int j = i + i; j < NUM; j+=i) {
                prime[j] = false;
            }
        }
    }
    int n, u, d;
    while (cin>>n) {
        for (int i = n-1; i > 1; --i) {
            if (prime[i]) {
                d = i;
                break;
            }
        }
        for (int i = n + 1; i < NUM; ++i) {
            if (prime[i]) {
                u = i;
                break;
            }
        }
        cout << d << " " << u << endl;
    }
    return 0;
}