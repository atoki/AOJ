#include<iostream>

using namespace std;

int main()
{
    string red, green, bottom;

    while (cin >> red, red != "-")
    {
        cin >> green;
        cin >> bottom;

        int p = 0;
        int pred = 0;
        int pgreen = 1;
        char current = green[0];
        string result;

        while (p < bottom.length())
        {
            if (current == bottom[p])
            {
                current = red[pred];
                pred++;
                p++;
            }
            else 
            {
                result += current;
                current = green[pgreen];
                pgreen++;
            }
        }
        
        result += current + green.substr(pgreen);

        cout << result << endl;

    }
    
    return 0;

}