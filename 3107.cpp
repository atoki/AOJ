#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    int cnt = 0;
    cin >> n >> m;
    vector<string> A(n);
    vector<string> B(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) {
                cnt++;
            }
        }
    }
    
    cout << cnt << endl;

    return 0; 
}