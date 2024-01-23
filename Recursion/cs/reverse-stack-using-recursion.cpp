#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/reverse-stack-using-recursion_631875?leftPanelTabValue=PROBLEM

void reverseStack(stack<int> &st) {
    // Write your code here
    int val = st.top();
    st.pop();
    if(st.empty()) {
        st.push(val);
        return;
    }
    reverseStack(st);
    stack<int> dummy;
    while(not st.empty()) {
        dummy.push(st.top());
        st.pop();
    }
    st.push(val);
    while(not dummy.empty()) {
        st.push(dummy.top());
        dummy.pop();
    }
    return;
}

int main(){
    
    return 0;
}