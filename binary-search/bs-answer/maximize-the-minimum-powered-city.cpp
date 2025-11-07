#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// https://leetcode.com/problems/maximize-the-minimum-powered-city/

class Solution {
public:
  bool check(vector<long long> &arr, long long need, int k, int r) {
    int n = arr.size();
    long long count = 0;
    queue<pair<int, long long>> qu;
    for(int i = 0 ; i < n ; i++) {
      long long curr = arr[i];
      while(!qu.empty()) {
        int idx = qu.front().first;
        long long cnt = qu.front().second;
        if(idx < i) {
            count -= cnt;
            qu.pop();
        } else {
            break;
        }
      }
      curr += count;
      if(curr < need) {
        if(k < need-curr) return false;
        int req = min((long long)k, need-curr);
        k -= req;
        count += req;
        int expire = min(n-1, i+2*r);
        qu.push({expire, req});
      }
    }
    return true;
  } 
  long long maxPower(vector<int>& stations, int r, int k) {
    int n = stations.size();
    vector<long long> prefix(n);
    vector<long long> arr(n);
    for(int i = 0 ; i < n ; i++) {
      prefix[i] = stations[i];
      if(i) prefix[i] += prefix[i-1];
    }
    for(int i = 0 ; i < n ; i++) {
      int preIdx = i-r-1;
      int sufIdx = min(n-1, i+r);
      long long preSum = preIdx < 0 ? 0 : prefix[preIdx];
      long long sufSum = prefix[sufIdx];
      arr[i] = sufSum-preSum;
    }
    long long lo = 0, hi = 1e11;
    long long ans = 0;
    while(lo <= hi) {
      long long mid = lo + ((hi-lo) >> 1);
      if(check(arr, mid, k, r)) {
        ans = mid;
        lo = mid+1;
      } else {
        hi = mid-1;
      }
    }
    return ans;
  }
};

int main() {
  fast_io();
  
  return 0;
}