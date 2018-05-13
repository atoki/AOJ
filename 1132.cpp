#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

#define EPS (1e-10)

using namespace std;

int count( vector<complex<double>> &vpos );

int main(int argc, char const *argv[]) {
    int n, result;
    double x, y;
    vector<complex<double>> vpos;
    vector<int> results;

    while(1){
        cin>>n;
        if( n == 0 ) break;
        for(int i = 0; i < n; i++){
            cin>>x>>y;
            vpos.push_back( complex<double> (x,y) );
        }
        results.push_back( count( vpos ) );
        vpos.clear();
    }

    for (auto it = results.begin(); it != results.end(); it++) {
        cout<<*it<<endl;
    }

    return 0;
}

int count( vector<complex<double>> &vpos ){
    int count = 0;
    int tmp_count1, tmp_count2;
    int size = vpos.size();
    bool flag = false;
    complex<double> m, n1, n2, center1, center2;

    if( size == 1 ) return 1;

    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size ; j++){
            if( vpos[i].real() == vpos[j].real() ) continue;
            tmp_count1 = 0;
            tmp_count2 = 0;

            m = ( vpos[i] + vpos[j] ) / 2.0;
            n1 = ( vpos[i] -  vpos[j] ) * complex<double> ( 0.0, 1.0 );
            n1 = n1 / abs(n1);
            n2 = ( vpos[i] -  vpos[j] ) * complex<double> ( 0.0, -1.0 );
            n2 = n2 / abs(n2);

            double x = abs( vpos[i] -  vpos[j] ) / 2.0;
            center1 =  m + n1 * sqrt( 1.0 - x * x );
            center2 =  m + n2 * sqrt( 1.0 - x * x );

            if( center1.real() > 0.0 ) flag = true;
            if( center2.real() > 0.0 ) flag = true;

            for(int k = 0; k < size; k++){
                double dist1 = abs( center1 - vpos[k] );
                double dist2 = abs( center2 - vpos[k] );
                if( dist1 <= 1.0 + EPS ){
                    tmp_count1++;
                }
                if( dist2 <= 1.0 + EPS ){
                    tmp_count2++;
                }
            }
            if( count < max(tmp_count1, tmp_count2) ){
                count = max(tmp_count1, tmp_count2);
            }
        }
    }

    if(!flag) return 1;
    return count;
}
