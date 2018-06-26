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
    double lhs, rhs;
    int al = 0;
    int ar = 0;
    int bl = 0;
    int br = 0;
    int cl = 0;
    int cr = 0;
    int dl = 0;
    int dr = 0;
    while (cin>>lhs>>rhs) {
        if (lhs >= 1.1) al++;
        if (rhs >= 1.1) ar++;
        if (1.1 > lhs && lhs >= 0.6) bl++;
        if (1.1 > rhs && rhs >= 0.6) br++;
        if (0.6 > lhs && lhs >= 0.2) cl++;
        if (0.6 > rhs && rhs >= 0.2) cr++;
        if (0.2 > lhs && lhs >= 0.1) dl++;
        if (0.2 > rhs && rhs >= 0.1) dr++;
    }
    cout<<al<<" "<<ar<<endl;
    cout<<bl<<" "<<br<<endl;
    cout<<cl<<" "<<cr<<endl;
    cout<<dl<<" "<<dr<<endl;
    return 0;
}