#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}


// https://leetcode.com/problems/find-the-difference/description/

class Solution {
public:
  char findTheDifference(string s, string t) {
    int n = s.size();
    int xorr = 0;
    for(int i = 0 ; i < n ; i++) {
      xorr = xorr ^ (s[i]-'a') ^ (t[i]-'a');
    }
    xorr ^= (t[n]-'a');
    return xorr + 'a';
  }
};

int main() {
  fast_io();
  
  return 0;
}