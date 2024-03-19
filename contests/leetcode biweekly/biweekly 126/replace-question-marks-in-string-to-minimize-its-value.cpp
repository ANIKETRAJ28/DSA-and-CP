#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/contest/biweekly-contest-126/problems/replace-question-marks-in-string-to-minimize-its-value/

class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> freq(26, 0);
        int n = s.size();
        for(int i = 0 ; i < n ; i++) {
            if(s[i] != '?')freq[s[i]-'a']++;
        }
        vector<int> emptySpot;
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '?') {
                int mini = INT_MAX;
                char c;
                for(int j = 0 ; j < 26 ; j++) {
                    if(mini > freq[j]) {
                        mini = freq[j];
                        c = char(j + 'a');
                    }
                }
                emptySpot.push_back(c);
                freq[c-'a']++;
            }
        }
        sort(emptySpot.begin(), emptySpot.end());
        int j = 0;
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '?') {
                s[i] = emptySpot[j];
                j++;
            }
        }
        return s;
    }
};

int main() {

    return 0;
}