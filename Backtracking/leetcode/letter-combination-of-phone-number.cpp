#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> ans;
    void f(string &s, string &str, int idx) {
        // base case
        if(idx == s.size()) {
            ans.push_back(str);
            return;
        }
        string s1 = mp[s[idx]];
        for(int i = 0 ; i < s1.size() ; i++) {
            str += s1[i];
            f(s, str, idx+1);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        string str = "";
        f(digits, str, 0);
        return ans;   
    }
};

int main(){
    
    return 0;
}