#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define vec vector<ll>
#define vecvec vector<vector<ll>>
using namespace std;
// https://cses.fi/problemset/task/1745/

int main(){
    int n;
    cin>>n;

    set<ll> s;
    while(n--){
        int x;
        cin>>x;
        if(s.size() == 0){
            // with one element there's only one choice -> the element itself
            s.insert(x);
        }
        else{
            vector<int> v;
            v.push_back(x);
            // find all the combinations with all the elements
            for(auto ele : s){
                v.push_back(ele+x);
            }
            for(int i = 0 ; i < v.size() ; i++){
                s.insert(v[i]);
            }
        }
    }

    cout<<s.size()<<"\n";
    for(auto ele : s){
        cout<<ele<<" ";
    }
    return 0;
}