#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x, y, s;

int main(int argc, char const *argv[]) {
    while(cin>>x>>y>>s, x||y||s) {
        double tax_before = x / 100.0;
        double tax_after = y / 100.0;
        int ans = 0;
        for (int i = 1; i < s; ++i) {
            for (int j = i; j < s; ++j) {
                int before_i = i + i * tax_before;
                int before_j = j + j * tax_before;
                int sum_before = before_i + before_j;
                if ( sum_before == s ) {
                    int after_i = i + i * tax_after;
                    int after_j = j + j * tax_after;
                    int sum_after = after_i + after_j;
                    ans = max (ans, sum_after);
                }
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}