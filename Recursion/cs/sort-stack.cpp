#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/sort-stack_1229505?leftPanelTabValue=PROBLEM

stack<int> f(stack<int> st) {
	int val = st.top();
	st.pop();
	
	if(st.empty()) {
		st.push(val);
		return st;
	}

	st = f(st);
	stack<int> dummy;
	while(not st.empty() and st.top() > val) {
		dummy.push(st.top());
		st.pop();
	}
	st.push(val);
	while(not dummy.empty()) {
		st.push(dummy.top());
		dummy.pop();
	}
	return st;
}
stack<int> sortStack(stack<int> &s)
{
	// Write code here.
	s = f(s);
	return s;
}

int main(){
    
    return 0;
}