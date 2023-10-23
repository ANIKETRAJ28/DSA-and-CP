#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/combination-sum/

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

int main()
{

    return 0;
}