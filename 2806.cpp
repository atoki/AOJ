#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    int ans = 0;
    cin >> n >> m;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int index = 0;
    bool first = true;
    while (true)
    {   
        // if (index == n) break;

        int begin = index;
        int end = (index + m) % (n + 1);
        int mx = -1;
        int mi = 10000;
        if (end < index)
        {
            for (int i = begin; i < n; i++)
            {
                mx = max(mx, v[i]);
                mi = min(mi, v[i]);
            }
            for (int i = 0; i < end + 1; i++)
            {
                mx = max(mx, v[i]);
                mi = min(mi, v[i]);
            }
            ans += mx - mi;
        }
        else
        {
            for (int i = begin; i < end; i++)
            {
                mx = max(mx, v[i]);
                mi = min(mi, v[i]);
            }
            ans += mx - mi;
        }

        if (end == n) break;
        index = (index + m) % n;
    }

    cout << ans << endl;

    return 0;
}