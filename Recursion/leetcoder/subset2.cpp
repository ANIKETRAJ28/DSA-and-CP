#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/subsets-ii/

class Solution
{
public:
    void subset(vector<vector<int>> &final_ans, vector<int> &v, vector<int> ans, int i)
    {
        if (i == v.size())
        {
            final_ans.push_back(ans);
            return;
        }
        if (ans.size() == 0)
        {
            subset(final_ans, v, ans, i + 1);
            ans.push_back(v[i]);
            subset(final_ans, v, ans, i + 1);
        }
        else
        {
            if (ans[ans.size() - 1] != v[i])
            {
                subset(final_ans, v, ans, i + 1);
            }
            ans.push_back(v[i]);
            subset(final_ans, v, ans, i + 1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> final_ans;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        subset(final_ans, nums, ans, 0);
        return final_ans;
    }
};

int main()
{

    return 0;
}