#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int ans = 1000000;
    vector<int> p(4, 0);
    vector<int> t(4, 0);

    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> t[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                for (int l = 0; l <= n; l++)
                {
                    if ((i*t[0] + j*t[1] + k*t[2] + l*t[3]) >= n)
                    {
                        ans = min(ans, i*p[0] + j*p[1] + k*p[2] + l*p[3]);
                    }
                }   
            }
        }
    }

    cout << ans << endl;
    
    return 0;   
}