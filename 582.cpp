#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    int a4 = 0;

    while(true)
    {
        vector<int> v(3, 0);
        cin >> v[0] >> v[1] >> v[2];

        sort(v.begin(), v.end());

        if((v[0] + v[1] <= v[2]) || (v[0] + v[2] <= v[1]) || (v[1] + v[2] <= v[0])) break;

        a1++;
        if (v[0]*v[0] + v[1]*v[1] > v[2]*v[2]) a2++;
        if (v[0]*v[0] + v[1]*v[1] == v[2]*v[2]) a3++;
        if (v[0]*v[0] + v[1]*v[1] < v[2]*v[2]) a4++;
    }

    printf("%d %d %d %d\n", a1, a3, a2, a4);

    return 0;
}