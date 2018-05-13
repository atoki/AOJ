#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while(cin>>n, n) {
        int loop = n / 4;
        int cnt = 0;
        for (int i = 0; i < loop; ++i) {
            int tmp;
            cin>>tmp;
            cnt += tmp;
        }
        cout<<cnt<<endl;
    }
    return 0;
}