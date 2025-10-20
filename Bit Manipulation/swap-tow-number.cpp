#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  int a, b;
  cin>>a>>b;
  a = a^b;
  b = b^a;
  a = a^b;
  cout<<a<<" "<<b<<endl;
  return 0;
}