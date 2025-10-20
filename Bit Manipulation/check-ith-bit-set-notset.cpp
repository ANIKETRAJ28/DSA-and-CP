#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  int n, bit;
  cin>>n>>bit;
  // left shift
  cout<<((n & (1 << bit)) > 0)<<endl;
  // right shift
  cout<<((1 & (n >> bit)) == 1)<<endl;
  return 0;
}