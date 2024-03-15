#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B

/**
 * TC = O(log*n) 
 * SC = O(n)
*/
int find(vec<int> &parent, int x) {
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

/**
 * TC = O(log*n) 
 * SC = O(n)
*/
void Union(vec<int> &parent, vec<int> &size, vec<int> &maxi, vec<int> &mini, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if(a == b) return;

    if(size[a] > size[b]) {
        parent[b] = a;
        maxi[a] = max(maxi[a], maxi[b]);
        mini[a] = min(mini[a], mini[b]);
        size[a]+= size[b];
    } else {
        parent[a] = b;
        maxi[b] = max(maxi[a], maxi[b]);
        mini[b] = min(mini[a], mini[b]);
        size[b]+= size[a];
    }
}

/**
 * Overall TC and SC
 * TC = O(log*n) 
 * SC = O(n)
*/

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {

    file_i_o();
    
    int n, m;
    cin>>n>>m;
    // n -> no. of elements
    // m -> no. of queries
    vector<int> size(n+1, 1);
    vector<int> mini(n+1, 1);
    vector<int> maxi(n+1, 1);
    vector<int> parent(n+1);
    for(int i = 0 ; i <= n ; i++) {
        parent[i] = i;
        maxi[i] = i;
        mini[i] = i;
    }

    while(m--) {
        string str;
        cin>>str;
        if(str == "union") {
            int x, y;
            cin>>x>>y;
            Union(parent, size, maxi, mini, x, y);
        } else {
            int x;
            cin>>x;
            int ele = find(parent, x);
            cout<<mini[ele]<<" "<<maxi[ele]<<" "<<size[ele]<<"\n";
        }
    }
    return 0;
}