#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool check(int num)
{
    for(int i = 1; i * i <= num; i++){
        if((num - i) % (2 * i + 1) == 0){
            return true;
        }
    }  
    return false;
}

int main()
{
    int n, area;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> area;
        if (!check(area)) ans++;
    }
    
    cout << ans << endl;

    return 0;
}