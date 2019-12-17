#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    cin >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    vector<int> cell(2020, 0);
    for (int i = 0; i < N; i++) {
        cell[X[i]] = 1;
    }


    for (int i = 0; i < M; i++) {
        int pos = X[A[i]-1];
        if (cell[pos+1] == 0 && pos < 2019){
            X[A[i]-1] = pos + 1;
            cell[pos] = 0;
            cell[pos+1] = 1;
        } 
    }
    
    for (int i = 0; i < N; i++) {
        cout << X[i] << endl;
    }

    return 0; 
}