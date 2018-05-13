#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    string num;

    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>num;
        string tmp = num;
        sort(begin(tmp), end(tmp), greater<int>());
        sort(begin(num), end(num));
        int max = stoi(tmp);
        int min = stoi(num);
        cout<<max-min<<endl;
    }
    return 0;
}