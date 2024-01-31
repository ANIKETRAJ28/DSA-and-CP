#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/palindrome-partitioning/submissions/

//! TC = O(2^(n)*n) SC = O(n)
class Solution {
public:
    vector<vector<string>> ans;

    bool check(string &s, int idx1, int idx2) {
        int i = idx1, j = idx2;
        while(i <= j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    } 

    void palindrome(string &s, int idx, vector<string> &str) {
        // base case
        if(idx == s.size()) {
            ans.push_back(str);
            return;
        }

        // backtracking
        for(int i = idx ; i < s.size() ; i++) {
            if(check(s, idx, i)) { // the string is palindrome
                // store the palindrome string of the partition
                str.push_back(s.substr(idx, i-idx+1)); 
                palindrome(s, i+1, str);
                str.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<string> str;
        palindrome(s, 0, str);
        return ans;
    }
};

int main(){
    
    return 0;
}