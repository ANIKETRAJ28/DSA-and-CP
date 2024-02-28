#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

vec<vec<double>> dp;
vec<double> coins;
int n;

double ftd(int i, int diff, double sum) {
    if(i == n and diff > 0) {
        return sum;
    }
    if(i == n) {
        return 0.0;
    }
    if(dp[i][diff] != -1.0) return dp[i][diff];
    cout<<sum<<"\n";
    double ans = 1.0;
    // head
    ans += ftd(i+1, diff+1, sum*coins[i]);
    // tail
    ans += ftd(i+1, diff-1, sum*(1.0-coins[i]));

    return dp[i][diff] = ans;
}

int main() {
    cin>>n;
    dp.resize(n+1, vec<double> (n+1, -1.0));
    while(n--) {
        int el;
        cin>>el;
        coins.push_back(el);
    }
    cout<<ftd(0, 0, 1.0);
    return 0;
}