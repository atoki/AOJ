#include<iostream>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;


int main() 
{
    vector<string> vs{".,!? ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    int n;
    string str;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        int len = str.length();
        int current_vs = 0;
        int current_vs_len = 0;
        int current_vs_index = 0;
        for (int j = 0; j < len; j++)
        {
            int current_n = str[j] - '0';
            if (current_n == 0)
            {
                if (current_vs != 0)
                {
                    cout << vs[current_vs - 1][current_vs_index];
                }
                current_vs = 0;
                current_vs_len = 0;
                current_vs_index = 0;
            }
            else
            {
                if (current_vs == 0) 
                {
                    current_vs = current_n;
                    current_vs_len = vs[current_vs - 1].length();
                    current_vs_index = 0;
                }
                else
                {
                    current_vs_index = (current_vs_index + 1) % current_vs_len;
                }
            }
        }
        cout << endl;
    }
    
    
    return 0;

}