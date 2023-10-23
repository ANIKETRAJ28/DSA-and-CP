#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/subsets/

class Solution
{
public:
    void subset(vector<int> s, vector<int> &st, vector<vector<int>> &v, int idx)
    {
        if (idx == st.size())
        {
            v.push_back(s);
            return;
        }
        int t = st[idx];
        subset(s, st, v, idx + 1);
        s.push_back(t);
        subset(s, st, v, idx + 1);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> v;
        vector<int> s;
        subset(s, nums, v, 0);
        return v;
    }
};

int main()
{

    return 0;
}