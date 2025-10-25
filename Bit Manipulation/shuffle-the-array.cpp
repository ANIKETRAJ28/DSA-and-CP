#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// https://leetcode.com/problems/shuffle-the-array/description/

class Solution {
public:
  vector<int> shuffle(vector<int>& nums, int n) {
    for(int i = 0 ; i < n ; i++) {
      nums[i] = ((nums[i] << 10) | nums[i+n]);
    }
    int j = 2*n-1;
    for(int i = n-1 ; i >= 0 ; i--, j--) {
      int y = (nums[i] & ((1<<10)-1));
      int x = nums[i] >> 10;
      nums[j] = y;
      j--;
      nums[j] = x;
    }
    return nums;
  }
};

int main() {
  fast_io();
  
  return 0;
}