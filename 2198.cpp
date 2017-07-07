#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Product {
    Product(string name, double effi) : name_(name), efficiency_(effi) {}

    string name_;
    double efficiency_;
};

int main (int argc, char *argv[]) {
    double N, P, A, B, C, D, E, F, S, M;
    string L;
    vector<Product> pv;

    while (cin>>N, N) {
        for (int i = 0; i < N; ++i) {
            cin>>L>>P>>A>>B>>C>>D>>E>>F>>S>>M;
        
            double total_time = A + B + C + ((D + E) * M);
            double total_value = S * F * M - P;
            double efficiency = total_value / total_time;
            
            pv.push_back(Product(L, efficiency));
        }

        sort(pv.begin(), pv.end(), [](const auto& lhs, const auto& rhs) -> bool {
            if (lhs.efficiency_ != rhs.efficiency_) {
                return lhs.efficiency_ > rhs.efficiency_;
            }
            else {
                return lhs.name_ < rhs.name_;
            }
        });

        for (auto e : pv) {
            cout<<e.name_<<endl;
        }
        cout<<"#"<<endl;
        pv.clear();
    }

    return 0;
}