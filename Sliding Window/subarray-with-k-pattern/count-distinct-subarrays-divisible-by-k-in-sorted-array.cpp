#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// https://leetcode.com/problems/count-distinct-subarrays-divisible-by-k-in-sorted-array/description/

class Solution {
public:
  #define ll long long
  long long numGoodSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<ll> prefix(n, 0);
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
      prefix[i] = nums[i];
      if (i) prefix[i] += prefix[i-1];
      prefix[i] %= k;
      freq[nums[i]]++;
    }
    ll ans = 0;
    for (auto e : freq) {
      int ele = e.first;
      int cnt = e.second;
      ll sum = 0;
      while (cnt--) {
        sum += ele;
        sum %= k;
        if (sum == 0) ans++;
      }
    }
    map<ll, ll> mp;
    map<ll, ll> temp;
    for (int i = 0; i < n; i++) {
      ans += mp[prefix[i]];
      if (i < n-1 && nums[i] != nums[i+1]) {
        if (mp[0] == 0) mp[0]++;
        for (auto e : temp) {
          ll ele = e.first;
          ll cnt = e.second;
          mp[ele] += cnt;
        }
        temp.clear();
      }
      temp[prefix[i]]++;
    }
    return ans;
  }
};

int main() {
  fast_io();
  
  return 0;
}