#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Node {
    int no_;
    int sum_;
    int cap_;

    Node(int n, int s, int c) 
        : no_(n), sum_(s), cap_(c) {}
};

int n, k;
vector<int> num;

int calcMaxmumSum() {
    int ans = 0;

    stack<Node> st;
    st.push(Node(0, 0, k));
    st.push(Node(0, num[0], k-1));

    while(!st.empty()) {
        auto node = st.top();
        st.pop();

        int no = node.no_;
        int sum = node.sum_;
        int cap = node.cap_;

        cout<<no<<"段目 "<<"sum = "<<sum<<" cap = "<<cap<<endl;

        if ( cap == 0 && sum > ans ) {
            ans = sum;
        }

        if (cap > 0 && no < n-1) {
            st.push(Node(no+1, sum, cap));
            st.push(Node(no+1, sum+num[n+1], cap-1));
        }
    }

    return ans;
}

int main(int argc, char const *argv[]) {
    cin>>n>>k;

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin>>tmp;
        num.push_back(tmp);
    }

    cout<<calcMaxmumSum()<<endl;

    return 0;
}