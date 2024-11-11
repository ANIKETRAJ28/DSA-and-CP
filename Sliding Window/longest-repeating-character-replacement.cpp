#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution {
public:
    int maxFreq(unordered_map< char, int> &mp) {
        int maxCnt = 0;
        for(auto it = mp.begin() ; it != mp.end() ; it++) {
            maxCnt = max(maxCnt, it->second);
        }
        return maxCnt;
    }
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        int maxLen = 0;
        unordered_map<char, int> mp;
        while(j < n) {
            mp[s[j]]++;
            if(j-i+1 - maxFreq(mp) <= k) maxLen = max(maxLen, j-i+1);
            while(j-i+1 - maxFreq(mp) > k) {
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return max(maxLen, j-i);
    }
};

int main() {
    
    return 0;
}