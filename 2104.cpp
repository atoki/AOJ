#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> x;

int solve() {
    if (k >= n) return 0;
    vector<int> diff;

    for (int i = 0; i < static_cast<int>(x.size()) - 1; ++i) {
        diff.push_back(x[i+1] - x[i]);
    }

    sort(diff.begin(), diff.end(), greater<int>());

    int total = 0;
    for (auto e : diff) {
        total += e;
    }

    for (int i = 0; i < k - 1; ++i) {
        total -= diff[i];
    }

    diff.clear();
    return total;
}

int main(int argc, char const *argv[]) {
    int t;
    cin>>t;
    for (int i = 0; i < t; ++i) {
        cin>>n>>k;
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin>>tmp;
            x.push_back(tmp);
        }

        cout<<solve()<<endl;
        x.clear();
    }
    return 0;
}