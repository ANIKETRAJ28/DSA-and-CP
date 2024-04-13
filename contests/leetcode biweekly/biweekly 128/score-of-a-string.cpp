#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/score-of-a-string/description/

class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0 ; i < n-1 ; i++) {
            ans += abs(s[i] - s[i+1]);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}