#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/optimal-partition-of-string/description/

class Solution {
public:
    int partitionString(string s) {
        vector<int> freq(26, 0);
        int n = s.size();
        for(int i = 0 ; i < n ; i++) {
            freq[s[i]-'a']++;
        }
        int ans = 1;
        int maxFreq = -1;
        char maxEle;
        for(int i = 0 ; i < 26 ; i++) {
            if(freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxEle = (char)('a'+i);
            }
        }
        unordered_set<char> st;
        for(int i = 0 ; i < n ; i++) {
            if(!st.count(s[i])) {
                st.insert(s[i]);
            } else {
                st.clear();
                st.insert(s[i]);
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}