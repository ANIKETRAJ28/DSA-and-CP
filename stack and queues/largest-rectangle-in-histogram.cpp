#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:
    int largestRectangleArea(vector<int>& v){
        int n = v.size();
        int nsI[n];
        nsI[n-1] = n;
        stack<int> st;
        st.push(n-1);
        // next smallest index
        for(int i = n-2 ; i >= 0 ; i--){
            while(st.size() > 0 && v[st.top()] >= v[i]) st.pop();
            if(st.size() == 0) nsI[i] = n;
            else nsI[i] = st.top();
            st.push(i);
        }
        // reset stack
        while(st.size() > 0) st.pop();

        int psI[n];
        psI[0] = -1;
        st.push(0);
        // previous smallest index
        for(int i = 1 ; i < n ; i++){
            while(st.size() > 0 && v[i] <= v[st.top()]) st.pop();
            if(st.size() == 0) psI[i] = -1;
            else psI[i] = st.top();
            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0 ; i < n ; i++){
            int height = v[i];
            int breadth = nsI[i]-psI[i]-1;
            int area = height*breadth;
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
};

int main() {
    
    return 0;
}