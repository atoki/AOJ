#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> memory;

string addZero(string num, int cnt) {
    string str = num;
    int size = num.size();

    for (int i = 0; i < cnt - size; ++i) {
        str = '0' + str;   
    }    
    return str;
}

string createMaxNumber(string num) {
    sort(begin(num), end(num), greater<char>());
    return num;
}

string createMinNumber(string num) {
    sort(begin(num), end(num));
    return num;
}

int equalNumber(int num) {
    int ans = 0;
    for(auto e : memory) {
        if (e == num) {
            return ans;
        }
        ans++;
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    string a;
    int L;

    while(cin>>a>>L, a != "0" || L) {
        memory.clear();
        int j = 0;
        a = addZero(a, L);
        memory.push_back(stoi(a));

        while(1) {
            j++;
            int max = stoi(createMaxNumber(a));
            int min = stoi(createMinNumber(a));
            int diff = max - min;
            int i = equalNumber(diff);

            if (i >= 0) {
                cout<<i<<" "<<diff<<" "<<j-i<<endl;
                break;
            }

            memory.push_back(diff);
            a = to_string(diff);
            a = addZero(a, L);
        }
    }
    return 0;
}