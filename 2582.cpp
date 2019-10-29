#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<string> str;
        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            str.push_back(tmp);
        }

        int ans = 0;
        string current_str, prev_str;
        for (int i = 1; i < n; i++)
        {
            current_str = str[i];
            prev_str = str[i-1];

            if (current_str == "ru" && prev_str == "lu"
            || current_str == "lu" && prev_str == "ru"
            || current_str == "rd" && prev_str == "ld"
            || current_str == "ld" && prev_str == "rd")
            {
                ans++;
            }  
        }

        cout << ans << endl;
    }
}