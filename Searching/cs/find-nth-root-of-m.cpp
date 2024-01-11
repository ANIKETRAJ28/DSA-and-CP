#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679?leftPanelTabValue=PROBLEM

int NthRoot(int n, int m) {
  // Write your code here.
  long long int hi = m, lo = 1;
  while(lo <= hi){
    long long int mid = lo + (hi - lo)/2;
    long long int ans = 1;
    for(int i = 0 ; i < n ; i++){
      ans *= mid;
      if(ans > m) break;
    }
    if(ans == m) return mid;
    else if(ans < m) lo = mid+1;
    else hi = mid-1;
  }
  return -1;
}

int main(){
    
    return 0;
}