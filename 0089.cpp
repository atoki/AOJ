#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>o
using namespace std;

int main (int argc, char *argv[]) {
    vector<int> v;
    stack<pari<int, int>> nodes;
    string str;
    while(getline(cin, str)) {
        for (int i = 0; i < str.length(); ++i) {
            if (i % 2 == 0) {
                v.push_back(str[i] - '0');
            }
        }
    }

    int sum[v.size() + 1];
    sum[0] = v[0]
    nodes.push(make_pair(0,sum[0]);
    while (!nodes.empty()) {
        auto current = nodes.top();
        // 中央より上
        if (current.first > center) {
            int left = 
        }
        // 中央より下
        else {

        }
    }

    for (auto n : v) {
        cout<<n<<" ";
    }
    cout<<endl;

    return 0;
}