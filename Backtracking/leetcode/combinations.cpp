#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/combinations/description/

class Solution
{
public:
    vector<vector<int>> ans;
    void combination(int i, int n, int k, vector<int> v)
    {
        // base case
        if (v.size() == k)
        {
            ans.push_back(v);
            return;
        }

        for (int j = i; j <= n; j++)
        {
            v.push_back(j);
            combination(j + 1, n, k, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> v;
        combination(1, n, k, v);
        return ans;
    }
};

class Solution
{
public:
    void combination(vector<vector<int>> &ans, vector<int> &nums, vector<int> &res, int k, int i)
    {
        int n = nums.size();
        if (res.size() == k)
        {
            ans.push_back(res);
            return;
        }
        if (i == n)
            return;
        // pick
        res.push_back(nums[i]);
        combination(ans, nums, res, k, i + 1);
        res.pop_back();
        // not pick
        combination(ans, nums, res, k, i + 1);
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> res;
        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        combination(ans, nums, res, k, 0);
        return ans;
    }
};

int main()
{

    return 0;
}