#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int h, w;
    int ans = -1;
    cin >> h >> w;
    vector<pair<int, int>> v2a;

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            char tmp;
            cin >> tmp;
            if (tmp == 'B')
            {
                v2a.push_back(make_pair(x, y));
            }
        }
    }

    for (int i = 0; i < v2a.size(); i++)
    {
        for (int j = i + 1; j < v2a.size(); j++)
        {
            ans = max(ans, abs(v2a[i].first - v2a[j].first) + abs(v2a[i].second - v2a[j].second));   
        }
    }

    cout << ans << endl;

    return 0;
}