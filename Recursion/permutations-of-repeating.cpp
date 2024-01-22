#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

void f(string s, string ans) {
    if(s == "") {
        cout<<ans<<"\n";
        return;
    }
    unordered_set<char> st;
    for(int i = 0 ; i < s.size() ; i++) {
        if(st.count(s[i]) == 0) {
            st.insert(s[i]);
            f(s.substr(0, i) + s.substr(i+1), ans+s[i]);
        }
    }
    return;
}

int main(){
    string s;
    cin>>s;
    f(s, "");
    return 0;
}