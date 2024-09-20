#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void combinations(vector<int> &candidates, vector<vector<int>> &result, vector<int> ans, int target, int i) {
        int n = candidates.size();
        if(target <= 0 || i == n) {
            if(target == 0) result.push_back(ans);
            return;
        }
        for(int j = i ; j < n ; j++) {
            ans.push_back(candidates[j]);
            combinations(candidates, result, ans, target-candidates[j], j);
            ans.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        combinations(candidates, result, {}, target, 0);
        return result;
    }
};

class Solution
{
public:
    void combination(vector<vector<int>> &v, vector<int> ans, vector<int> c, int t, int idx)
    {
        if (t == 0)
        {
            v.push_back(ans);
            return;
        }
        if (t < 0)
        {
            return;
        }
        for (int i = idx; i < c.size(); i++)
        {
            ans.push_back(c[i]);
            combination(v, ans, c, t - c[i], i);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &c, int t)
    {
        vector<vector<int>> v;
        vector<int> ans;
        combination(v, ans, c, t, 0);
        return v;
    }
};

class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int> &c, vector<int> sum, int i, int t) {
        if(t == 0) {
            ans.push_back(sum);
            return;
        }
        if(t < 0) return;

        int n = c.size();
        for(int j = i ; j < n ; j++) {
            t -= c[j];
            sum.push_back(c[j]);
            f(c, sum, j, t);
            t += c[j];
            sum.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sum;
        f(candidates, sum, 0, target);
        return ans;
    }
};

int main()
{

    return 0;
}