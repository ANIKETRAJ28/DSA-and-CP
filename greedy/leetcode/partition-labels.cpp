#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/partition-labels/description/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i = 0 ; i < n ; i++) mp[s[i]] = i;
        vector<int> ans;
        int prv = -1, curr = 0;
        for(int i = 0 ; i < n ; i++) {
            curr = max(curr, mp[s[i]]);
            if(curr == i) {
                prv == -1 ? ans.push_back(curr-prv) : ans.push_back(curr-prv+1);
                curr = i+1;
                prv = i+1;
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}