#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Team {
    Team(int team_number) {
        tn_ = team_number;
        n_ = 0;
        t_ = 0;
        pc_ = 0;
    }
    int tn_;
    int n_;
    int t_;
    int pc_;
    vector<int> p_list_;
};

int main (int argc, char *argv[]) {
    int M, T, P, R;
    int m, t, p, j;
    int count = 0;
    vector<Team> tv;

    while (cin>>M>>T>>P>>R) {
        if (count != 0 )cout<<endl;
        count++;
        for (int i = 0; i < T; ++i) {
            tv.push_back(Team(i+1));
        }
        for (int i = 0; i < R; ++i) {
            cin>>m>>t>>p>>j;
            if (j != 0) {
                tv[t-1].p_list_.push_back(p);
            }
            else {
                for (auto e : tv[t-1].p_list_) {
                    if (e == p) {
                        tv[t-1].pc_++;
                    }
                }
                tv[t-1].n_++;
                tv[t-1].t_ += m;
            }
        }
        for (auto& e : tv) {
            e.t_ += e.pc_ * 20;
        }

        sort(tv.begin(), tv.end(), [](const auto& lhs, const auto& rhs) -> bool{
            if (lhs.n_ != rhs.n_ ) {
                return lhs.n_ > rhs.n_;
            }
            else if (lhs.n_ == rhs.n_ && lhs.t_ != rhs.t_) {
                return lhs.t_ < rhs.t_;
            }
            else return lhs.tn_ > rhs.tn_;
        });

        const int size = static_cast<int>(tv.size());
        for (int i = 0; i < size; ++i) {
            cout<<tv[i].tn_;
            if(i != size -1) {
                if (tv[i].n_ != tv[i+1].n_ || tv[i].t_ != tv[i+1].t_ ) {
                    cout<<",";
                }
                else cout<<"=";
            }
        }
        tv.clear();
    }

    return 0;
}