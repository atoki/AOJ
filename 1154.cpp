#include <iostream>
#include <vector>
using namespace std;

vector<int> msnums;

void make();
void solve(int n);
bool check(int n);

int main(int argc, char const *argv[]){
    int msnum;
    make();
    while(1){
        cin>>msnum;
        if (msnum == 1) break;
        solve(msnum);
    }
    return 0;
}


void make(){
    const int max = 300000;
    for (int i = 2; i < max; i++){
        int var = i % 7;
        if (var == 1 || var == 6){
            msnums.push_back(i);
        }
    }
}

void solve(int n){
    vector<int> prime;
    for (const auto& it : msnums){
        if (n % it == 0){
            if(check(it)) prime.push_back(it);
        }
    }
    cout<<n<<":";
    for ( const auto& it : prime){
        cout<<" "<<it;
    }
    cout<<'\n';
}

bool check(int n){
    for (const auto& it : msnums){
        if (it==n) break;
        if (n % it == 0) return false;
    }
    return true;
}