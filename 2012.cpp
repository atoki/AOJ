#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main (int argc, char *argv[]) {
    int e;
    while (cin>>e, e) {
        int m = e;
        for (int z = 0; z * z * z <= e; ++z) {
            for (int y = 0; y * y <= e - z * z * z; ++y) {
                int x = e - y * y - z * z * z;
                m = min(m, x + y + z);
            }
        }
        cout<<m<<endl;
    }
    return 0;
}

// int main (int argc, char *argv[]) {
//     int e;
//     while (cin>>e, e) {
//         int m = 1000000000;
//         for (int x = 0; x <= e; ++x) {
//             for (int y = 0; pow(y, 2) <= e; ++y) {
//                 for (int z = 0; pow(z, 3) <= e; ++z) {
//                     if (x + pow(y, 2) + pow(z, 3) == e) {
//                         m = min(m, x + y + z);
//                     }
//                 }
//             }
//         }
//         cout<<m<<endl;
//     }
//     return 0;
// }