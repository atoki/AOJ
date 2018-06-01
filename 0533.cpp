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
    vector<int> v1(10, 0);
    vector<int> v2(10, 0);
    for (int i = 0; i < 10; ++i) {
        cin>>v1[i];
    }
    for (int i = 0; i < 10; ++i) {
        cin>>v2[i];
    }
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());
    cout<<v1[0]+v1[1]+v1[2]<<" "<<v2[0]+v2[1]+v2[2]<<endl;
    return 0;
}

if (k < n-1 || i < 7) 