#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

vec<int> dp;

int f(int k) {
    if(k == 0 or k == 1) return 1;
    if(dp[k] != -1) return dp[k];
    return dp[k] = f(k-1) + f(k-2);
}

int main() {
    int n;
    cin>>n;
    dp.resize(n+1, -1);
    cout<<f(n);
    return 0;
}