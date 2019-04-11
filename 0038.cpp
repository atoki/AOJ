#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[]) {
    int card[5];
    while (~scanf("%d,%d,%d,%d,%d", &card[0], &card[1], 
                                    &card[2], &card[3], &card[4])) {
        int sum[14] = {};
        for (int i = 0; i < 5; ++i) {
            sum[card[i]]++;
        }
        
        int one_pair = false;
        bool three_card = false;
        bool four_card = false;
        bool straight = false;
        for (int i = 0; i < 14; ++i) {
            if (sum[i] == 4) {
                four_card = true;
                break;
            }
            if (sum[i] == 2) one_pair++;
            if (sum[i] == 3) three_card = true;
            if (sum[10] == 1 && sum[11] == 1 
                && sum[12] == 1 && sum[13] == 1 
                && sum[1] == 1) straight = true;
            if(i < 10 && sum[i] == 1 && sum[i+1] == 1 
                && sum[i+2] == 1 && sum[i+3] == 1 
                && sum[i+4] == 1) straight = true;
        }

        if (four_card) {
            cout << "four card" << endl;
            continue;
        }
        if (three_card && one_pair) {
            cout << "full house" <<endl;
            continue;
        }
        if (straight) {
            cout << "straight" << endl;
            continue;
        }
        if (three_card) {
            cout << "three card" << endl;
            continue;
        }
        if (one_pair == 2) {
            cout << "two pair" << endl;
            continue;
        }
        if (one_pair) {
            cout << "one pair" << endl;
            continue;
        }
        cout << "null" << endl;
    }
    return 0;
}