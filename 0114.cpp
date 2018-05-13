#include <iostream>
#include <vector>  

using namespace std;

long long gcd(long long a, long long b) {
    if (b > a) swap(a, b);
    long long r = a % b;
    if ( r == 0 ) return b;
    return gcd(b, r);
}

long long lcm(long long a, long long b) {
    long long x = a * b;
    long long g = gcd(a, b);
    return x/g;
}

long long count(int a, int m) {
    long long n = ( a * 1 ) % m;
    long long cnt = 1;
    while(1) {
        if (n == 1) break;
        cnt++;
        n = ( a * n ) % m;
    }
    return cnt;
}

int main() {
    long long a, b, c;
    long long l, m, n;

    while(cin>>a>>l>>b>>m>>c>>n, a||b||c||l||m||n) {
        long long nx = count(a, l);
        long long ny = count(b, m);
        long long nz = count(c, n);
        long long ans = 0;
        long long tmp = lcm(nx, ny);
        ans = lcm(tmp , nz);
        cout<<ans<<endl;
    }

    return 0;
}