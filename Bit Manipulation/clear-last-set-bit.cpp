#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();
  int n;
  cin>>n;
  int i = 0;
  while(true) {
    if((n & (1 << i)) > 0) {
      n &= ~(1 << i);
      break;
    }
    i++;
  }
  cout<<n<<endl;
  return 0;
}