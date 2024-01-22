#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

// print lexicographically
/**
 * eg.
 * 12 -> 0, 10, 11, 12, 2, 3, 4, 5, 6, 7, 8, 9
*/

using namespace std;
template<typename T>
using vec = vector<T>;

void f(int n, int s) {
    if(s > n) return;
    cout<<s<<"\n";
    for(int i = (s == 0) ? 1 : 0 ; i < 10 ; i++){
        f(n, s*10+i);
    }
    return;
}

int main() {
    int n;
    cin>>n;
    f(n, 0);
    return 0;
}