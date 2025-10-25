#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// https://leetcode.com/problems/sum-of-two-integers/description/

class Solution {
public:
  int getSum(int a, int b) {
    while(b) {
      int temp = (a & b) << 1;
      a = a ^ b;
      b = temp;
    }
    return a;
  }
};

int main() {
  fast_io();
  
  return 0;
}