#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/lexicographically-smallest-string-after-operations-with-constraint/description/

class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        int ans = 0;
        int i = 0;
        while(i < n && k > 0) {
            int change = min(26-(s[i]-'a'), s[i]-'a');
            if(change <= k) {
                s[i] = 'a';
                k -= change;
                i++;
            }
            else {
                s[i] = char('a'+(s[i]-'a')-k);
                return s;
            }
        }
        return s;
    }
};

int main() {
    
    return 0;
}