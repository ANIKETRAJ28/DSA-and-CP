#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-number-of-homogenous-substrings/description/

class Solution {
public:
    #define mod 1000000007
    int countHomogenous(string s) {
        int n = s.size();
        if(n == 1) return 1;
        int i = 0, j = 1;
        int len = 0;
        while(j < n) {
            while(i < j && s[i] != s[j]) {
                len = (len%mod+j-i)%mod;
                i++;
            }
            j++;
        }
        while(i < n) {
            len = (len%mod+j-i)%mod;
            i++;
        }
        return len;
    }
};

int main() {
    
    return 0;
}