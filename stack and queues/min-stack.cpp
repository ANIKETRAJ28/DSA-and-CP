#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/min-stack/description/

class MinStack {
public:
    vector<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) st.push_back({val, val});
        else st.push_back({val, min(val, st[st.size()-1].second)});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st[(st.size()-1)].first;
    }
    
    int getMin() {
        return st[st.size()-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    
    return 0;
}