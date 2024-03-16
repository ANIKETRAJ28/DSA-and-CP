#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description

class Solution {
public:
    int minimumLength(string s) {
        char ch;
        int i = 0, j = s.size()-1;
        while(i < j) {
            if(s[i] != s[j]) return j-i+1;
            ch = s[i];
            while(j >= 0 and s[j] == ch) j--;
            while(i < s.size() and s[i] == ch) i++;
        }
        return (i == j) ? 1 : 0;
    }
}; 

int main() {
    
    return 0;
}