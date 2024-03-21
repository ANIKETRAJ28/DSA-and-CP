#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/description/

class Solution {
public:
    int dp[26][26];
    int solve(int i, int j, vector<int> &freq, int k) {
        if(i == j or freq[j]-freq[i] <= k) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = min(freq[i]+solve(i+1, j, freq, k), freq[j]-freq[i]-k+solve(i, j-1, freq, k));
    }
    int minimumDeletions(string word, int k) {
        memset(dp, -1, sizeof(dp));
        vector<int> freq(26, 0);
        for(int i = 0 ; i < word.size() ; i++) {
            freq[word[i]-'a']++;
        }
        sort(freq.begin(), freq.end());
        int i = 0;
        while(freq[i] == 0) {
            i++;
        }
        return solve(i, 25, freq, k);
    }
};

int main() {
    
    return 0;
}