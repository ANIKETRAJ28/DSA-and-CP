#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// https://leetcode.com/problems/maximum-xor-product/description/

class Solution {
public:
  #define ll long long
  // const int mod = 1e9+7;
  int maximumXorProduct(long long a, long long b, int n) {
    ll xor_a = 0;
    ll xor_b = 0;
    for(int i = 49 ; i >= n ; i--) {
      bool a_ith_bit = (a >> i) & 1;
      bool b_ith_bit = (b >> i) & 1;
      if(a_ith_bit) {
        xor_a = (xor_a ^ (1ll << i));
      }
      if(b_ith_bit) {
        xor_b = (xor_b ^ (1ll << i));
      }
    }
    for(int i = n-1 ; i >= 0 ; i--) {
      bool a_ith_bit = (a >> i) & 1;
      bool b_ith_bit = (b >> i) & 1;
      if(a_ith_bit == b_ith_bit) {
        xor_a = (xor_a ^ (1ll << i));
        xor_b = (xor_b ^ (1ll << i));
      } else if(xor_a > xor_b) {
        xor_b = (xor_b ^ (1ll << i));
      } else {
        xor_a = (xor_a ^ (1ll << i));
      }
    }
    xor_a = xor_a%mod;
    xor_b = xor_b%mod;
    return (xor_a*xor_b)%mod;
  }
};

int main() {
  fast_io();
  
  return 0;
}