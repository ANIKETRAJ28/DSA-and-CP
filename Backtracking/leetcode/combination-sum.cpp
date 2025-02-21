#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/combination-sum/submissions/

class Solution
{
public:
    vector<vector<int>> ans;
    void f(vector<int> &candidates, vector<int> v, int i, int t)
    {
        if (t == 0)
        {
            ans.push_back(v);
            return;
        }

        if (i >= candidates.size())
            return;

        if (candidates[i] <= t)
        {
            // pick
            v.push_back(candidates[i]);
            f(candidates, v, i, t - candidates[i]);
            v.pop_back();
        }
        // not pick
        // while(i+1 < candidates.size() and candidates[i+1] == candidates[i]) i++;
        f(candidates, v, i + 1, t);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        f(candidates, v, 0, target);
        return ans;
    }
};

class Solution
{
public:
    void combinations(vector<vector<int>> &ans, vector<int> &nums, vector<int> &res, int target, int i)
    {
        int n = nums.size();
        if (i >= n)
            return;
        if (target == 0)
        {
            ans.push_back(res);
            return;
        }
        if (nums[i] > target)
            return;
        // pick
        res.push_back(nums[i]);
        combinations(ans, nums, res, target - nums[i], i);
        res.pop_back();
        // not pick
        combinations(ans, nums, res, target, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        combinations(ans, candidates, res, target, 0);
        return ans;
    }
};

int main()
{

    return 0;
}