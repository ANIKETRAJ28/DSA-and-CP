#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/contest/biweekly-contest-126/problems/find-the-sum-of-the-power-of-all-subsequences/

class Solution {
public:
#define ll long long int
#define mod 1000000007
    ll dp[105][105][105];
    ll power(ll n, ll pow) {
        ll res = 1;
        while(pow) {
            if(pow%2) {
                res = (res*n)%mod;
                pow--;
            } else {
                n = (n*n)%mod;
                pow/=2;
            }
        }
        return res%mod;
    }
    ll ftd(vector<int>& nums, ll i, ll sum, ll k, ll cnt) {
        ll n = nums.size();
        if(sum > k) return 0;
        if(dp[i][sum][cnt] != -1) return dp[i][sum][cnt];
        if(sum == k) {
            return dp[i][sum][cnt] = power(2, n-cnt);
        }
        if(i >= n) return 0;
        ll pick = ftd(nums, i+1, sum+nums[i], k, cnt+1)%mod;
        ll notpick = ftd(nums, i+1, sum, k, cnt)%mod;
        return dp[i][sum][cnt] = (pick+notpick)%mod;
    }
    int sumOfPower(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        return ftd(nums, 0, 0, (ll)k, 0);
    }
};

int main() {
    
    return 0;
}