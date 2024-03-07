#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int j = 0, odd = 0, count = 0, total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]%2) {
                odd++;
                if (odd >= k) {
                    count = 1;
                    while (!(nums[j]%2)) {
                        count++;
                        j++;
                    }
                    total += count;
                }
            } else if (odd >= k) total += count;
        }
        return total;
    }
};

int main() {
    
    return 0;
}