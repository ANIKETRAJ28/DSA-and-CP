#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// https://leetcode.com/problems/stable-subarrays-with-equal-boundary-and-interior-sum/

class Solution {
public:
  #define ll long long
  long long countStableSubarrays(vector<int>& capacity) {
    int n = capacity.size();
    vector<ll> prefix(n, 0);
    for (int i = 0; i < n; i++) {
      prefix[i] = capacity[i];
      if (i > 0) prefix[i] += prefix[i-1];
    }
    ll ans = 0;
    map<pair<int, ll>, int> mp;
    // c[r] = c[l] = sum(c[l+1]...c[r-1])
    // c[r] = p[r-1] - p[l]
    // p[r] - p[l-1] = 3v (v = c[r])
    // p[r] - p[l] = 2v
    // ************p[r] = p[l]+2v*************
    // So, we need to find all the r's where p[r] = p[l]+2v condition meets
    for (int i = n-1; i >= 0; i--) {
      // here finding all r's where 
      ans += mp[{capacity[i], prefix[i]+2*capacity[i]}];
      // deleay addition to assure the min length of 3 exist
      if (i < n-1) mp[{capacity[i+1], prefix[i+1]}]++;
    }

    // c[r] = c[l] = sum(c[l-1]...c[r-1])
    // c[r] = p[r-1] - p[l]
    // p[r] - p[l-1] = 3v (v = c[r])
    // p[r] - p[l] = 2v
    // p[l] = p[r] - 2v
    // ************p[l] = p[r]-2v*************
    /*
    for (int i = 0; i < n; i++) {
        ans += mp[{capacity[i], prefix[i]-2*capacity[i]}];
        if (i > 0) mp[{capacity[i-1], prefix[i-1]}]++;
    }
    */
    return ans;
  }
};

int main() {
  fast_io();
  
  return 0;
}