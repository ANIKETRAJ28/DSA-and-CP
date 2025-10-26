#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// https://leetcode.com/problems/alice-and-bob-playing-flower-game/

class Solution {
public:
  long long flowerGame(int n, int m) {
    int num = n+m;
    if(n > m) swap(n, m);
    long long ans = 0;
    for(int i = 3 ; i <= num ; i+=2) {
      int lo = 1, hi = min(i-1, n);
      int minVal = -1;
      while(lo <= hi) {
        int mid = lo + ((hi-lo)>>2);
        if(i - mid > m) {
          lo = mid+1;
        } else {
          minVal = mid;
          hi = mid-1;
        }
      }
      ans += min(n, i-1)-minVal+1;
    }
    return ans;
  }
};

int main() {
  fast_io();
  
  return 0;
}