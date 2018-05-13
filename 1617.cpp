#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    while (1) {
        cin >> s1;
        if (s1[0] == '.') break;
        cin >> s2;
        int count = 0;
        if (s1 == s2) {
            cout << "IDENTICAL" << endl;
            continue;
        }
        int n1 = 0;
        int n2 = 0;
        int size1 = s1.size();
        int size2 = s2.size();
        while (1) {
            if (n1 == size1 - 1 && n2 == size2 - 1) {
                if (count == 1) {
                    cout << "CLOSE" <<endl;
                }
                break;
            }
            if (s1[n1] == '"' && s2[n2] == '"') {
                int c1 = n1 + 1;
                int c2 = n2 + 1;
                bool diff = false;
                while (1) {
                    if (s1[c1] == '"' && s2[c2] == '"') {
                        n1 = c1;
                        n2 = c2;
                        break;
                    }
                    if (s1[c1] != s2[c2] && !diff) {
                        count++;
                        diff = true;
                    }
                    if (s1[c1] != '"') c1++;
                    if (s2[c2] != '"') c2++;
                }
            }
            if (s1[n1] != s2[n2]) {
                cout << "DIFFERENT" << endl;
                break;
            }
            if (count >= 2) {
                cout << "DIFFERENT" <<endl;
                break;
            }

            if (n1 != size1 - 1) n1++;
            if (n2 != size2 - 1) n2++;
        }
    }
    return 0;
}