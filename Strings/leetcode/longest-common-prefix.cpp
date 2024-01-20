#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/longest-common-prefix/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        sort(strs.begin(), strs.end());
        string small = strs[0];
        int n = small.size(), m = strs.size();
        for(int i = 0; i < n ; i++){
            bool flag = true;
            for(int j = 1 ; j < m ; j++){
                if(strs[j][i] != small[i]){
                    flag = false;
                    break;
                }
            }
            if(flag) s += small[i];
            else return s;
        }
        return s;
    }
};

int main(){
    
    return 0;
}