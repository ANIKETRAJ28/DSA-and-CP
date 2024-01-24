#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/-binary-strings-with-no-consecutive-1s._893001?leftPanelTabValue=PROBLEM

void f(int n, string s, vector<string> &ans) {
    if(n == 0) {
        ans.push_back(s);
        return;
    }
    f(n-1, s+'0', ans);
    if(s.size() == 0 or s[s.size()-1] == '0') f(n-1, s+'1', ans);
    return;
}
vector<string> generateString(int N) {
    // Write your code here.
    vector<string> ans;
    f(N, "", ans);
    return ans;
}

int main(){
    
    return 0;
}