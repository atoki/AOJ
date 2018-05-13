#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int NOT(int x) {
    return 2 - x;
}

int AND(int x, int y) {
    return min(x, y);
}

int OR(int x, int y) {
    return max(x, y);
}

int P, Q, R;

int formula(string&s, int& i) {
    switch(s[i++]) {
        case 'P' : return P;
        case 'Q' : return Q;
        case 'R' : return R;
        case '0' : return 0;
        case '1' : return 1;
        case '2' : return 2;
        case '(' : {
            
        }
    }
}

int main(int argc, char const *argv[]) {
    string str;
    int ans = 0;
    int c = 0;

    while(cin>>str, str[0] != '.') {
        ans = 0;
        for (P = 0; P < 3; ++P) {
            for (Q = 0; Q < 3; ++Q) {
                for (R = 0; R < 3; ++R) {
                    if(formula(str, c) == 2) {
                        ans++;
                    }
                    c = 0;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}