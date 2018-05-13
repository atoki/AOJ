#include <iostream>
#include <vector>

using namespace std;

int count( int p, int q, int a, int n );

int int main(int argc, char const *argv[]) {
    int p, q, a, n;
    vector<int> results;

    while(1){
        cin >> p >> q >> a >> n;
        if( p == 0 && q == 0 && a == 0 && n == 0 ) break;


        results.push_back( count( p, q, a, n ) );
    }
    return 0;
}

int count( int p, int q, int a, int n ){
    int n = 1;
    int result;
    const int r = p / q;

    if( r = 0)
    while( r < 1/n ) i++;


}
