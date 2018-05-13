#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    int t, n, s, f;
    int total;
    while (cin>>t, t) {
        total = 0;
        cin>>n;
        for (int i = 0; i < n; ++i) {
            cin>>s>>f;
            int tmp = f - s;
            total += tmp;
        }

        if (total >= t) cout<<"OK"<<endl;
        else cout<< t - total << endl;

    }
    return 0;
}