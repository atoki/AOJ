#include <iostream>

using namespace std;

int main()
{
    int t1, t2, r1, r2;
    
    cin >> t1 >> t2 >> r1 >> r2;

    if (r1 == -1 || r2 == -1)
    {
        if (t1 < t2)
        {
            cout << "Alice" << endl;
        }
        else if (t1 > t2)
        {
            cout << "Bob" << endl;
        }
        else 
        {
            cout << "Draw" << endl;
        }
    }
    else 
    {
        if (r1 > r2)
        {
            cout << "Alice" << endl;
        }
        else if (r1 < r2)
        {
            cout << "Bob" << endl;
        }
        else 
        {
            cout << "Draw" << endl;
        }
    }

    return 0;
}