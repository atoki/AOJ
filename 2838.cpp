#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[]) 
{
    string al("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string str;
    int al_index = 1;
    int st_index = 0;
    int count = 0;
    int size = al.length();

    cin >> str;

    while (true)
    {
        if (al[al_index] == str[st_index])
        {
            // cout << str[st_index] << ":" << count << endl;
            st_index++;
        }

        if (al[al_index] == 'A')
        {
            count++;
        }

        if (st_index >= str.length())
        {
            break;
        }

        al_index++;
        al_index %= size;
    }

    cout << count << endl;
    
    return 0;
}