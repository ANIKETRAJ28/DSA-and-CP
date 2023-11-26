#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/frog-jump/description/

class Solution
{
public:
    unordered_map<int, int> mp;
    vector<vector<int>> dp;
    bool f(vector<int> &stones, int curr_stone_idx, int prev_jump)
    {
        int n = stones.size();
        if (curr_stone_idx == n - 1)
            return true;
        if (curr_stone_idx >= n)
            return false;
        if (dp[curr_stone_idx][prev_jump] != -1)
            return dp[curr_stone_idx][prev_jump];
        bool res = false;
        for (int next_jump = prev_jump - 1; next_jump <= prev_jump + 1; next_jump++)
        {
            if (next_jump > 0)
            {
                int next_stone = stones[curr_stone_idx] + next_jump;
                if (mp.find(next_stone) != mp.end())
                {
                    res = res or f(stones, mp[next_stone], next_jump);
                }
            }
        }
        return dp[curr_stone_idx][prev_jump] = res;
    }
    bool canCross(vector<int> &stones)
    {
        if (stones[1] != 1)
            return false;
        for (int i = 0; i < stones.size(); i++)
        {
            mp[stones[i]] = i;
        }
        dp.resize(2001, vector<int>(2001, -1));
        return f(stones, 0, 0);
    }
};

int main()
{

    return 0;
}