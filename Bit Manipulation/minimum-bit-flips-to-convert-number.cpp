#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  int n, m;
  cin>>n>>m;
  int l = n^m;
  int cnt = 0;
  while(l) {
    cnt += l & 1;
    l = l >> 1;
  }
  cout<<cnt;
  return 0;
}