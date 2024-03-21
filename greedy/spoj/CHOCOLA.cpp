#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.spoj.com/problems/CHOCOLA/

ll cost(vector<ll> &row, vector<ll> &col) {
    sort(col.begin(), col.end(), greater<int>());
    sort(row.begin(), row.end(), greater<int>());
    int r = 0, c = 0, n = row.size(), m = col.size();
    int hcut = 1; // will impact row cuts
    int vcut = 1; // will impace col cuts
    ll ans = 0;
    while(r < n and c < m) {
        if(row[r] >= col[c]) {
            ans += hcut*row[r];
            vcut++;
            r++;
        } else {
            ans += vcut*col[c];
            hcut++;
            c++;
        }
    }
    if(r == n) {
        while(c < m) {
            ans += vcut*col[c];
            c++;
        }
    }
    if(c == m) {
        while(r < n) {
            ans += hcut*row[r];
            r++;
        }
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        vector<ll> row(n-1), col(m-1);
        for(int i = 0 ; i < n-1 ; i++) cin>>row[i];
        for(int i = 0 ; i < m-1 ; i++) cin>>col[i];
        cout<<cost(row, col)<<"\n";
    }
    return 0;
}