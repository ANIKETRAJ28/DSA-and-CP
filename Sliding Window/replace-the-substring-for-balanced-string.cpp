#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/replace-the-substring-for-balanced-string/

class Solution {
public:
    bool isBalanced(unordered_map<char, int> &mp, int n) {
        for(auto it = mp.begin() ; it != mp.end() ; it++) {
            if(it->second > n) {
                return 0;
            }
        }
        return 1;
    }
    int balancedString(string s) {
        int n = s.size();
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        for(int i = 0 ; i < n ; i++) mp[s[i]]++;
        if(isBalanced(mp, n/4)) return 0;
        int minLen = 1e9;
        while(r < n) {
            mp[s[r]]--;
            if(isBalanced(mp, n/4)) {
                minLen = min(minLen, r-l+1);
                while(l <= r) {
                    mp[s[l]]++;
                    l++;
                    if(isBalanced(mp, n/4)) {
                        minLen = min(minLen, r-l+1);
                    } else break;
                }
            }
            r++;
        }
        return minLen;
    }
};

int main() {
    
    return 0;
}