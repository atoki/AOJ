#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

int bfs(string taregt, string origin, int count);
bool checkSameColor(string str);

int main(int argc, char const *argv[]){
    string color;
    int count;

    while(cin>>color, color != "0"){
        count = 0;
        int result = bfs(color, color, count);
        if (result == -1) cout<<"NA"<<endl;
        else cout<<result<<endl;
    }
    return 0;
}

bool checkSameColor(string str){
    char first = str[0];

    for (int i = 0; i < str.size(); i++){
        if (str[i] != first) return false;
    }

    return true;
}

int bfs(string target, string origin, int count){   
    queue<pair<string, int> > que;
    pair<string, int> worm;
    map<string, int> d;

    que.push(make_pair(origin, 0));

    while (!que.empty()){
        worm = que.front();
        que.pop();
        string str = worm.first;
        
        if (d[str]) continue;

        if (checkSameColor(str)){
            return worm.second;
        }

        d[str] = worm.second;

        for (int i = 0; i < str.size()-1; ++i){
            string tmp_str = str;
            if((str[i] == 'r' && str[i+1] == 'b') 
                || (str[i] == 'b' && str[i+1] == 'r')){
                pair<string, int> tmp = make_pair(tmp_str.replace(i, 2, "gg"), worm.second+1);
                que.push(tmp);
            }
            else if((str[i] == 'b' && str[i+1] == 'g') 
                || (str[i] == 'g' && str[i+1] == 'b')){
                pair<string, int> tmp = make_pair(tmp_str.replace(i, 2, "rr"), worm.second+1);
                que.push(tmp);
            }
            else if((str[i] == 'g' && str[i+1] == 'r') 
                || (str[i] == 'r' && str[i+1] == 'g')){
                pair<string, int> tmp = make_pair(tmp_str.replace(i, 2, "bb"), worm.second+1);
                que.push(tmp);
            }
        }
    }
    return -1;
}