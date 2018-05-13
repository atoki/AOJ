#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int n;
string w;
vector<string> vw;

bool solve(int p, int size) {
    int w_count = p;
    int tmp_count = 0;
    
    // 5
    for (int i = w_count; i < size; ++i, ++w_count) {
        tmp_count += vw[w_count].length();
        if (tmp_count == 5) break;
        if (tmp_count > 5) return false;
    }
    w_count++;

    // 7
    tmp_count = 0;
    for (int i = w_count; i < size; ++i, ++w_count) {
        tmp_count += vw[w_count].length();
        if (tmp_count == 7) break;
        if (tmp_count > 7) return false;
    }
    w_count++;

    // 5
    tmp_count = 0;
    for (int i = w_count; i < size; ++i, ++w_count) {
        tmp_count += vw[w_count].length();
        if (tmp_count == 5) break;
        if (tmp_count > 5) return false;
    }
    w_count++;

    // 7
    tmp_count = 0;
    for (int i = w_count; i < size; ++i, ++w_count) {
        tmp_count += vw[w_count].length();
        if (tmp_count == 7) break;
        if (tmp_count > 7) return false;
    } 
    w_count++; 
    
    // 7
    tmp_count = 0;
    for (int i = w_count; i < size; ++i, ++w_count) {
        tmp_count += vw[w_count].length();
        if (tmp_count == 7) break;
        if (tmp_count > 7) return false;
    }

    return true;
}

int main (int argc, char *argv[]) {
    while (cin>>n, n) {
        for (int i = 0; i < n; ++i) {
            cin>>w;
            vw.push_back(w);
        }
        for (int i = 0; i < n; ++i) {
            if (solve(i, n)) {
                cout<<i+1<<endl;
                break;
            }   
        }
        vw.clear();
    }

    return 0;
}