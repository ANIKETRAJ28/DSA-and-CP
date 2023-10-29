#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/

class Solution
{
public:
    int sumCounts(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> st;
            for (int j = i; j < n; j++)
            {
                for (int k = i; k <= j; k++)
                {
                    st.insert(nums[k]);
                }
                ans += (st.size() * st.size());
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}