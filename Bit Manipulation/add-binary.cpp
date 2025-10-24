#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// https://leetcode.com/problems/add-binary/

class Solution {
public:
  string addBinary(string a, string b) {
    int n = a.size();
    int m = b.size();
    string res = "";
    int i = n-1, j = m-1;
    bool carry = false;
    while(i >= 0 && j >= 0) {
      char c_a = a[i];
      char c_b = b[j];
      bool curr_carry = false;
      if(c_a == '1' && c_b == '1') curr_carry = true;
      if(curr_carry) {
        if(carry == false) {
          res += '0';
          carry = true;
        } else {
          res += '1';
        }
      } else if(c_a == '1' || c_b == '1') {
        if(carry) {
          res += '0';
        } else {
          res += '1';
          carry = false;
        }
      } else {
        if(carry) {
          res += '1';
          carry = false;
        } else {
          res += '0';
        }
      }
      i--; j--;
    }
    if(i == -1) {
      while(j >= 0) {
        char c = b[j];
        if(c == '1' && carry) {
          res += '0';
        } else if(carry) {
          res += '1';
          carry = false;
        } else {
          res += c;
        }
        j--;
      }
    }
    if(j == -1) {
      while(i >= 0) {
        char c = a[i];
        if(c == '1' && carry) {
          res += '0';
        } else if(carry) {
          res += '1';
          carry = false;
        } else {
          res += c;
        }
        i--;
      }
    }
    if(carry) {
      res += '1';
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  fast_io();
  
  return 0;
}