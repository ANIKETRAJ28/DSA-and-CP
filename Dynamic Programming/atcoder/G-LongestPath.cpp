#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://atcoder.jp/contests/dp/tasks/dp_g

vector<int> dp;

int ftd(vector<vector<int>> &graph, int src) {
    // base case
    if(dp[src] != -1) return dp[src];
    bool leaf = 1;
    int maxLen = 0;
    for(auto neig : graph[src]) {
        leaf = 0;
        maxLen = max(maxLen, ftd(graph, neig));
    }
    return dp[src] = (leaf == 1) ? 0 : 1 + maxLen;
}

int main() {
    int v, e;
    cin>>v>>e;
    vector<vector<int>> graph(v+1);
    dp.clear();
    dp.resize(v+1, -1);
    while(e--) {
        int src, dst;
        cin>>src>>dst;
        graph[src].push_back(dst);
    }
    int maxLen = 0;
    for(int i = 1 ; i <= v ; i++) {
        maxLen = max(maxLen, ftd(graph, i));
    }
    cout<<maxLen;
    return 0;
}