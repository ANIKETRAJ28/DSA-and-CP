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
  cin>>n;
  m = n;
  int cnt1 = 0, cnt2 = 0;
  while(n > 1) {
    cnt1 += n & 1;
    n = n >> 1;
  }
  while(m > 1) {
    cnt2++;
    m &=(m-1);
  }
  if(n == 1) cnt1++;
  if(m == 1) cnt2++;
  cout<<cnt1<<" "<<cnt2;
  return 0;
}