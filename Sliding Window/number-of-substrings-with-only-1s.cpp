#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-substrings-with-only-1s/description/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int prod = 1, cnt = 0;
        while(i < n) {
            prod *= nums[i];
            while(j < i && prod >= k) {
                cnt += i-j;
                prod /= nums[j];
                j++;
            }
            while(j <= i && prod >= k) {
                prod /= nums[j];
                j++;
            }
            i++;
        }
        while(j < n && prod < k) {
            cnt+= i-j;
            prod /= nums[j];
            j++;
        }
        return cnt;
    }
};

class Solution {
public:
    #define mod 1000000007
    int numSub(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int ans = 0;
        while(j < n) {
            if(s[j] == '0') {
                while(i <= j) {
                    ans = (ans%mod+j-i)%mod;
                    i++;
                }
            }
            j++;
        }
        while(i < n) {
            ans = (ans%mod+j-i)%mod;
            i++;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}