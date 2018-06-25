#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a[4], b[4];
    int c[4] = {10,50,100,500};
    int d, e = 0, ju, i;
    while (cin>>d, d){
        if( e ) cout<<endl;
        e++;
        int sum = 0;
        for(i = 0; i < 4; i++) {
            cin>>a[i];
            sum += a[i] * c[i];
        }
        sum -= d;
        for (i = 4; i--;) {
            b[i] = sum / c[i];
            sum %= c[i];
        }
        for (i = 0; i < 4; i++) {
            ju = a[i] - b[i];
            if (ju>0) cout<<c[i]<<' '<<ju<<endl;
        }
    }
}