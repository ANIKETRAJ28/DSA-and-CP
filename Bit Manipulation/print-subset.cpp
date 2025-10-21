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
  int arr[n];
  for(int i = 0 ; i < n ; i++) {
    cin>>arr[i];
  }
  int i = 0;
  while(i < (1 << n)) {
    int num = i;
    vector<int> subset;
    int cnt = 0;
    while(num) {
      if(1 & num) {
        subset.push_back(arr[cnt]);
      }
      cnt++;
      num = num >> 1;
    }
    cout<<"[";
    for(int el : subset) {
      cout<<el<<",";
    }
    cout<<"]\n";
    i++;
  }
  return 0;
}