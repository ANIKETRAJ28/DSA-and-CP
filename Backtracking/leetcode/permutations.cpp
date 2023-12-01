#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/permutations/description/

class Solution
{
public:
    void f(vector<vector<int>> &final_ans, vector<int> &nums, int i)
    {
        int n = nums.size();
        if (i == n - 1)
        {
            final_ans.push_back(nums);
            return;
        }
        for (int idx = i; idx < n; idx++)
        {
            swap(nums[i], nums[idx]);
            f(final_ans, nums, i + 1);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> final_ans;
        f(final_ans, nums, 0);
        return final_ans;
    }
};

int main()
{

    return 0;
}