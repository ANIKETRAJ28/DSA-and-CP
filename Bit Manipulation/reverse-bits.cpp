#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// https://leetcode.com/problems/reverse-bits/description/

class Solution {
public:
  int reverseBits(int n) {
    n = ~n;
    int num = 0;
    for(int i = 31 ; i >= 0 ; i--) {
      if(n & 1) {
        num = (num | (1 << i));
      }
      n >>= 1;
    }
    num = ~num;
    return num;
  }
};

int main() {
  fast_io();
  
  return 0;
}