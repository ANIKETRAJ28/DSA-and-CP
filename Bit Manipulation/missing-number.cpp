#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// https://leetcode.com/problems/missing-number/

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int xorr = 0;
    for(int i = 0 ; i < n ; i++) {
      xorr ^= (i ^ nums[i]);
    }
    return xorr ^ n;
  }
};

int main() {
  fast_io();
  
  return 0;
}