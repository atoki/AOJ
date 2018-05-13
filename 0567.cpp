#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Node {
    int no_;
    int calorie_;
    int price_;

    Node(int n, int c, int p) 
        : no_(n), calorie_(c), price_(p) {}
};

int N, A, B, C;
vector<int> calorie;

int calcBestPizza() {
    int ans = 0;

    stack<Node> st;
    st.push(Node(0, C, A));
    st.push(Node(0, calorie[0]+C, A+B));

    while(!st.empty()) {
        auto node = st.top();
        st.pop();

        int n = node.no_;
        int total_calorie = node.calorie_;
        int total_price = node.price_;
        int tmp = total_calorie / total_price;

        if ( tmp > ans ) {
            ans = tmp;
        }

        if (n < N - 1) {
            st.push(Node(n+1, total_calorie, total_price));
            st.push(Node(n+1, total_calorie + calorie[n+1], total_price+B));
        }
    }

    return ans;
}

int main(int argc, char const *argv[]) {
    cin>>N;
    cin>>A>>B;
    cin>>C;

    for (int i = 0; i < N; ++i) {
        int c;
        cin>>c;
        calorie.push_back(c);
    }

    sort(calorie.begin(), calorie.end(), greater<int>());
    int total_calorie = C;
    int total_price = A;
    int ans = C / A;
    for (int i = 0; i < N; ++i) {
        total_calorie += calorie[i];
        total_price += B;
        ans = max(ans, total_calorie/total_price);
    }

    cout<<ans<<endl;

    return 0;
}