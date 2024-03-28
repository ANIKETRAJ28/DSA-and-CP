#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/existence-of-a-substring-in-a-string-and-its-reverse/description/

class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.size();
        if(n == 1) return false;
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        for(int i = 0 ; i < n-1 ; i++) {
            string str = s.substr(i, 2);
            for(int j = 0 ; j < n-1 ; j++) {
                string rev_str = s_rev.substr(j, 2);
                if(rev_str == str) return true;
            }
        }
        return false;
    }
};

int main() {
    
    return 0;
}