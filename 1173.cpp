#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool isPair(char top, char input) {
    if ((top == '(' && input ==')') 
        || (top == '[' && input ==']')) {
        return true;
    } 
    return false;
}

void check(string str) {
    stack<char> st;

    for (int i = 0; i < str.size(); ++i) {
        if (!st.empty()) {
            char top = st.top();
            if (isPair(top, str[i])) {
                st.pop();
                continue;
            }
        }
        
        if (str[i] == '(' || str[i] == ')' 
            || str[i] == '[' || str[i] == ']') {
            st.push(str[i]);
        }
    }

    if( st.empty() ) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}

int main() {
    string str;
    while(getline(cin, str), str.front() != '.') {
        check(str);
    }
    return 0;
}