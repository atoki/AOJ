#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, M, r, q;
bool use[1261] = {false};

class Log {
private:
    int t_;
    int n_;
    int m_;
    int s_;
public:
    Log(int t, int n, int m, int s) :
        t_(t), n_(n), m_(m), s_(s) {}

    int t() {
        return t_;
    }

    int n() {
        return n_;
    }

    int m() {
        return m_;
    }

    int s() {
        return s_;
    }
};

class Question {
private:
    int ts_;
    int te_;
    int m_;
public:
    Question(int ts, int te, int m) :
        ts_(ts), te_(te), m_(m) {}
};

int solve(vector<Log>& logs, int ts, int te, int m) {
    int ans = 0;
    vector<int> login;
    vector<int> logout;

    for (int i = 0; i < 1261; ++i) {
        use[i] = false;
    }

    for (int i = 1; i < N + 1; ++i) {
        for (auto& e : logs) {
            if (e.m() == m && e.s() == 0 && e.n() == i) {
                logout.push_back(e.t());
            }
            else if (e.m() == m && e.s() == 1 && e.n() == i) {
                login.push_back(e.t());
            }
        }
    }

    const int size = login.size();

    // for (int i = 0; i < size; ++i) {
    //     cout<<login[i]<<" - "<<logout[i]<<endl;
    // }
    

    for (int i = 0; i < size; ++i) {
        for (int j = login[i]; j < logout[i]; ++j) {
            use[j] = true;
        }
    }

    for (int time = 540; time <= 1260; ++time) {
        if  (use[time] && ts <= time && time < te) {
            ans++;
            //cout<<"time : "<<time<<", ans : "<<ans<<endl;
        }
    }

    return ans;
}

int main() {
    int t, n, m, s;
    int ts, te;
    vector<Log> log;

    while(cin>>N>>M, N||M) {
        cin>>r;
        for (int i = 0; i < r; ++i) {
            cin>>t>>n>>m>>s;
            log.push_back(Log(t, n, m, s));
        }

        cin>>q;
        for (int i = 0; i < q; ++i) {
            cin>>ts>>te>>m;
            cout<<solve(log, ts, te, m)<<endl;
        }
        
        log.clear();
    }

    return 0;
}