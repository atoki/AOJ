#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[]) 
{
    int n;
    cin >> n;
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = 1e8;
    int sum = 0;
    for (int day = 1; day <= n; ++day) 
    {
        sum += v[day - 1];
        ans = min(ans, sum / day);
    }

    cout << ans << endl;

    return 0;
}