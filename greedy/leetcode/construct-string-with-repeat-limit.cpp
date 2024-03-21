#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/construct-string-with-repeat-limit/description/

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> mp;
        int n = s.size();
        for(int i = 0 ; i < n ; i++) {
            mp[s[i]]++;
        }
        priority_queue<pair<char, int>> pq;
        for(auto el : mp) {
            pq.push(el);
        }
        string result = "";
        while(!pq.empty()) {
            auto lstring = pq.top();
            pq.pop();
            int freq = lstring.second;
            char ch = lstring.first;
            int cnt = min(freq, repeatLimit);
            if(freq <= cnt) freq = 0;
            else freq -= cnt;
            while(cnt--) {
                result += ch;
            }
            if(freq) {
                if(!pq.empty()) {
                    auto sstring = pq.top();
                    pq.pop();
                    int sfreq = sstring.second;
                    char sch = sstring.first;
                    result += sch;
                    sfreq--;
                    if(sfreq) pq.push({sch, sfreq});
                } else return result;
            }
            if(freq) pq.push({ch, freq});
        }
        return result;
    }
};

int main() {
    
    return 0;
}