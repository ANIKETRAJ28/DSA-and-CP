#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

int main() {
    int n;
    cin>>n;
    vector<char> arr(n);
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    vector<int> check(n);
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        if(arr[i] == 'A') sum++;
        else sum--;
        check[i] = sum;
    }
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sum = 0;
    for(int i = 0; i < n ; i++) {
        if(mp.find(mp[check[i]]) == mp.end()) mp[check[i]] = 1;
        else sum = max(sum, i-mp[check[i]]);
    }
    cout<<sum;

    return 0;
}