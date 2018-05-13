#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    auto comp = [](auto& lhs, auto& rhs) -> bool {
            if (lhs.size() < rhs.size()) return true;
            else if (lhs.size() > rhs.size()) return false;
            else if (lhs < rhs) return true;
            else return false;
            };
    map<string, int, decltype(comp)> products(comp);
    vector<pair<string, int> > p;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string name;
        int num;
        cin>>name>>num;

        if (products[name] > 0) {
            products[name] += num;
        }
        else {
            products[name] = num;
        }
    }

    for (auto& e : products) {
        p.push_back(make_pair(e.first, e.second));
    }

    sort(p.begin(), p.end(), [](auto& lhs, auto& rhs) -> bool {
            if (lhs.first.size() < rhs.first.size()) return true;
            else if (lhs.first.size() > rhs.first.size()) return false;
            else if (lhs.first < rhs.first) return true;
            else return false;
            });


    for (auto& e : p) {
        cout<<e.first<<" "<<e.second<<endl;
    }

    return 0;
}

