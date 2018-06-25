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
    int a, b, c, d, p;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>p;
    int t1 = p * a;
    int t2 = b + max((p - c), 0) * d;
    cout<<min(t1, t2)<<endl;
    return 0;
}