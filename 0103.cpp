#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
 
int main(int argc, char **argv) {
    int n, out, hit, total;
    string s;
    cin >> n;
     
    for (int i = 0; i < n; ++i) {
        out = 0;
        hit = 0;
        total = 0;

        while (out < 3) {
            cin >> s;

            if (s == "HIT") {
                if (hit == 3) total++;
                else hit++;
            } 
            else if (s == "HOMERUN") {
                total += hit + 1;
                hit = 0;
            } 
            else {
                out++;
            }
        }
        cout<<total<<endl;
    }
    return 0;
}