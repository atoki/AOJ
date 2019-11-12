#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> score(n, 0);
    
    for (int i = 0; i < n * (n - 1) / 2; i++)
    {
        int lt, rt, ls, rs;
        cin >> lt >> rt >> ls >> rs;

        if (ls > rs) score[lt - 1] += 3;
        if (ls < rs) score[rt - 1] += 3;
        if (ls == rs)
        {
            score[lt - 1]++;
            score[rt - 1]++;
        }
    }

	vector<int> tmp(score);
	sort(tmp.rbegin(), tmp.rend());

	for(int i = 0; i < n; ++i) 
    {
		for(int j = 0; j < n; ++j) 
        {
			if(score[i] == tmp[j])
            {
				cout << j + 1 << endl;
				break;
			}
		}
	}
    
    return 0;
}