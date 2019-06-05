#include<iostream>
#include<vector>

using namespace std;


int main() 
{
    vector<bool> prime(1000000, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i < 1000000; i++)
    {
        if (prime[i])
        {
            for (int j = i + i; j < 1000000; j+=i)
            {
                prime[j] = false;
            }
        }
    }

    int n;
    while (cin>>n, n)
    {
        int count = 0;
        int index = 0;
        int sum = 0;
        while (count != n)
        {
            if (prime[index])
            {
                sum += index;
                count++;
            }
            index++;
        }

        cout << sum << endl;
        
    }
    

    
    return 0;

}