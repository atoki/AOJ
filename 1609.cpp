#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    pair<string, int> ans;
    vector<string> votes;
    map<string, int> candidates;
    vector<pair<string, int>> cmp_candidates;
    bool update = false;

    auto cmp = [](pair<string ,int> const & a, pair<string, int> const & b) { 
        return a.second != b.second ? a.second > b.second : a.first > b.first; 
    };


    while(cin>>n, n) {
        update = false;
        for (int i = 0; i < n; ++i) {
            string tmp;
            cin>>tmp;
            candidates[tmp]++;

            // comp
            int m = 0;
            string c;
            for (auto e : candidates) {
                cmp_candidates.push_back(e);
                if (e.second > m) {
                    m = e.second;
                    c = e.first;
                }
            }

            sort(cmp_candidates.begin(), cmp_candidates.end(), cmp);

            // cout<<endl;
            // for (auto e : cmp_candidates) {
            //     cout<<e.first<<" : "<<e.second<<endl;
            // }

            if (!update && cmp_candidates.size() == 1 
                && m > n - i - 1) {
                ans = make_pair(c, i+1);
                update = true;
                //cout<<"pre update"<<endl;
            } 
            else if (!update && m > cmp_candidates[1].second + (n - i - 1)) {
                ans = make_pair(c, i+1);
                update = true;
                //cout<<"update"<<endl;
            }

            cmp_candidates.clear();


        }

        if (update) cout<<ans.first<<" "<<ans.second<<endl;
        else cout<<"TIE"<<endl;

        candidates.clear();
        cmp_candidates.clear();
        votes.clear();
    }
    return 0;
}