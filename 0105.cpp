#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){
    vector<int> pages;
    map<string, vector<int> > books; 
    string name;
    int page, page_count;

    while (cin>>name>>page){
        auto it = books.find(name);
        if (it != books.end()){
            books[name].push_back(page);
        }
        else{
            vector<int> pages = {page};
            books.insert(make_pair(name, pages));
        }
    }

    for (auto& book : books){
        cout<<book.first<<endl;
        page_count=0;
        sort(book.second.begin(), book.second.end());
        for (int page : book.second){
            if (page_count) cout<<" "<<page;
            else cout<<page;
            page_count++;
        }
        cout<<'\n';
    }
    return 0;
}