#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve( vector<pair<int, int>> &origin,
            vector<vector<pair<int, int>>> &target,
            vector<vector<int>> &results );

bool equal( vector<pair<int, int>> &origin, vector<pair<int, int>> &tmp );

int get_angle( pair<int, int> lhs, pair<int, int> rhs );
int get_turn( int n_angle, int o_angle );
int get_dist( pair<int, int> lhs, pair<int, int> rhs );

int main(int argc, char const *argv[]) {
    int n, m, rhs, lhs, size, count;
    vector<pair<int, int>> origin;
    vector<pair<int, int>> tmp;
    vector<vector<pair<int, int>>> target;
    vector<vector<int>> results;

    while(1){
        cin>>n;
        if( n == 0 ) break;
        for (int i = 0; i <= n; i++) {
            cin>>m;
            for (int j = 0; j < m; j++) {
                if( i == 0 ){
                    cin>>rhs>>lhs;
                    origin.push_back( pair<int, int> (rhs, lhs) );
                }
                else{
                    cin>>rhs>>lhs;
                    tmp.push_back( pair<int, int> (rhs, lhs) );
                }
            }
            if( i != 0 ) target.push_back( tmp );
            tmp.clear();
        }
        solve( origin, target, results );
        origin.clear();
        target.clear();
    }

    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            cout<<results[i][j]<<endl;
        }
        cout<<"+++++"<<endl;
    }

    return 0;
}

void solve( vector<pair<int, int>> &origin,
            vector<vector<pair<int, int>>> &target,
            vector<vector<int>> &results ){
    vector<pair<int, int>> tmp;
    vector<int> count;

    for (int i = 0; i < target.size(); i++) {
        tmp = target[i];
        if( equal( origin, tmp ) ) count.push_back( i+1 );
    }
    results.push_back( count );
}

bool equal( vector<pair<int, int>> &origin, vector<pair<int, int>> &tmp ){
    int i, j, k, l, dist, x_diff, y_diff;
    vector<int> ori_dist, tmp_dist, rev_dist;
    vector<int> ori_angle, tmp_angle, rev_angle;
    vector<int> ori_turn, tmp_turn, rev_turn;

    for(int i = 1; i < origin.size(); i++){
        ori_dist.push_back( get_dist( origin[i], origin[i-1] ) );
        ori_angle.push_back( get_angle( origin[i], origin[i-1] ) );
        tmp_dist.push_back( get_dist( tmp[i], tmp[i-1] ) );
        tmp_angle.push_back( get_angle( tmp[i], tmp[i-1] ) );
    }

    reverse( tmp.begin(), tmp.end() );
    for(int i = 1; i < tmp.size(); i++){
        rev_dist.push_back( get_dist( tmp[i], tmp[i-1] ) );
        rev_angle.push_back( get_angle( tmp[i], tmp[i-1] ) );
    }

    for(int i = 1; i < ori_angle.size(); i++){
        ori_turn.push_back( get_turn( ori_angle[i], ori_angle[i-1] ) );
        tmp_turn.push_back( get_turn( tmp_angle[i], tmp_angle[i-1] ) );
        rev_turn.push_back( get_turn( rev_angle[i], rev_angle[i-1] ) );
    }

    for(i = 0; i < ori_dist.size(); i++){
        if( ori_dist[i] != tmp_dist[i] ) break;
    }

    for(j = 0; j < ori_turn.size(); j++){
        if( ori_turn[j] != tmp_turn[j] ) break;
    }

    for(k = 0; k < ori_dist.size(); k++){
        if( ori_dist[k] != rev_dist[k] ) break;
    }

    for(l = 0; l < ori_turn.size(); l++){
        if( ori_turn[l] != rev_turn[l] ) break;
    }

    if( ( i == ori_dist.size() && j == ori_turn.size() )
        || ( k == ori_dist.size() && l == ori_turn.size() ) ) return true;

    return false;
}

int get_angle( pair<int, int> lhs, pair<int, int> rhs ){
    int x_diff = lhs.first -  rhs.first;
    int y_diff = lhs.second -  rhs.second;

    if( x_diff > 0 ) return 1;
    if( x_diff < 0 ) return 3;
    if( y_diff > 0 ) return 2;
    if( y_diff < 0 ) return 4;
}

// right 1, left -1
int get_turn( int n_angle, int o_angle ){
    switch( o_angle ){
        case(1):
            if( n_angle == 4 ) return 1;
            if( n_angle == 2 ) return -1;
        case(2):
            if( n_angle == 1 ) return 1;
            if( n_angle == 3 ) return -1;
        case(3):
            if( n_angle == 2 ) return 1;
            if( n_angle == 4 ) return -1;
        case(4):
            if( n_angle == 3 ) return 1;
            if( n_angle == 1 ) return -1;
    }
}

int get_dist( pair<int, int> lhs, pair<int, int> rhs ){
    return abs( lhs.first - rhs.first ) + abs( lhs.second - rhs.second );
}
