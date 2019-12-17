#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    long long N, M;
    cin >> N;
    M = N;
    int cnt_max = 0;
    int cnt_min = 0;

    // max
    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            cnt_min++;
            while (N % i == 0) {
                N /= i;
            }
        }
    }
    if (N > 1) {
        cnt_min++;
    }
    
    //min
    for (long long i = 1; i * i <= M; i++) {
        if (M % i == 0) {
            cnt_max++;
            if(i * i != M) {
                cnt_max++;
            }
        }
    }
    
    cout << cnt_min << " " << cnt_max - 1 << endl;

    return 0; 
}