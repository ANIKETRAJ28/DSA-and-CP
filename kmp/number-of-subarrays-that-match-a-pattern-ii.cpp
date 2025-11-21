#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-ii/description/

class Solution {
public:
  int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
    int n = nums.size();
    int m = pattern.size();
    vector<int> matcher(n), match(m);
    matcher[0] = 0;
    for (int i = 1; i < n; i++) {
      if (nums[i] == nums[i - 1])
        matcher[i] = 0;
      else if (nums[i] < nums[i - 1])
        matcher[i] = -1;
      else
        matcher[i] = 1;
    }
    match[0] = 0;
    int pre = 0, suf = 1, ans = 0;
    while (suf < m) {
      if (pattern[pre] == pattern[suf]) {
        match[suf] = pre + 1;
        pre++;
        suf++;
      } else {
        if (pre == 0) {
          match[suf] = 0;
          suf++;
        } else {
          pre = match[pre - 1];
        }
      }
    }
    suf = 1, pre = 0;
    while (suf < n) {
      if (matcher[suf] == pattern[pre]) {
        suf++;
        pre++;
      } else {
        if (pre == 0) {
          suf++;
        } else {
          pre = match[pre - 1];
        }
      }
      if (pre == m) {
        ans++;
        pre = match[pre - 1];
      }
    }
    if (pre == m)
      ans++;
    return ans;
  }
};

int main() {
  fast_io();
  
  return 0;
}