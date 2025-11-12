#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// https://leetcode.com/problems/minimum-time-to-complete-all-deliveries/description/

class Solution {
public:
  bool check(long long delivery1, long long delivery2, long long lcm1, long long lcm2, long long time) {
    long long d1 = time-(time/lcm1);
    long long d2 = time-(time/lcm2);
    long long d1_d2 = time-(time/lcm(lcm1, lcm2));
    return delivery1 <= d1 && delivery2 <= d2 && delivery1+delivery2 <= d1_d2;
  }
  long long minimumTime(vector<int>& d, vector<int>& r) {
    long long lo = 1, hi = 1e15;
    long long ans = -1;
    while(lo <= hi) {
      long long mid = lo + ((hi - lo) >> 1);
      if(check(d[0], d[1], r[0], r[1], mid)) {
        ans = mid;
        hi = mid-1;
      } else {
        lo = mid+1;
      }
    }
    return ans;
  }
};

int main() {
  fast_io();
  
  return 0;
}