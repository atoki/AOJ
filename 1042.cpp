#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <algorithm>

using namespace std;

string solve(string str) {
    string ans;

    // split
    vector<string> results;    
    stringstream ss(str);
    string buffer;
    char sep = ' ';
    while( std::getline(ss, buffer, sep) ) {
        results.push_back(buffer);
    }

    const int size = results.size();
    for (int i = 0; i < size; ++i) {   
        string tmp = to_string(results[i].length());
        ans += tmp;
    }

    return ans;
}

int main(int argc, char const *argv[]) {
    string str;
    const string end("END OF INPUT");

    while (getline(cin, str), str != end) {
        cout<<solve(str)<<endl;
    }
    return 0;
}