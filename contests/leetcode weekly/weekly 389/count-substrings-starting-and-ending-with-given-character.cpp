#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/description/

class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans = 0;
        int n = s.size();
        vector<int> arr(n, 0);
        arr[0] = (s[0] == c) ? 1 : 0;
        for(int i = 1 ; i < n ; i++) {
            arr[i] = arr[i-1];
            if(s[i] == c) arr[i]++;
        }
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == c) ans += arr[i];
        }
        return ans;
    }
};

int main() {
    
    return 0;
}