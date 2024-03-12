#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximize-happiness-of-selected-children/

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int cnt = 0;
        long long ans = 0;
        sort(happiness.begin(), happiness.end());
        int n = happiness.size();
        for(int i = n-1 ; i >= 0 ; i--) {
            happiness[i] -= cnt;
            if(happiness[i] < 0) happiness[i] = 0;
            cnt++;
        }
        for(int i = n-1 ; i >= 0 ; i--) {
            ans += happiness[i];
            k--;
            if(k == 0) return ans;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}