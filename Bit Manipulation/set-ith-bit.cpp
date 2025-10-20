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
  cout<<(n | (1 << bit))<<endl;
  return 0;
}