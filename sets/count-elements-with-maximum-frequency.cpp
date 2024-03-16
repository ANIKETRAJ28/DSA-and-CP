#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-elements-with-maximum-frequency/description

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0 ; i < nums.size() ; i++) {
            mp[nums[i]]++;
        }
        int cnt = 1;
        int ans = 0;
        for(auto el : mp) {
            int freq = el.second;
            if(cnt == freq) ans += freq;
            else if(cnt < freq) {
                ans = freq;
                cnt = freq;
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}