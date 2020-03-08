#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[]) 
{
    int n, m;

    cin >> n >> m;
    long long a1 = 0;
    long long a2 = 0;
    for (int i = 0; i < n; ++i) 
    {
       a int tmp;
        cin >> tmp;
        a1 += tmp;

    }
    for (int i = 0; i < m; ++i) 
    {
        int tmp;
        cin >> tmp;
        a2 += tmp;
    }

    cout << a1 * a2 << endl;

    return 0;
}