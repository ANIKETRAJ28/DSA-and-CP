#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        /*
        Individual taps cannot fill the whole garden, i.e we need to fill the gaps between the garden
        which will be done by overlapping taps.
        So, the intution behind the question is that we will get the left and right range of the taps and
        will find the minimum taps which whill fill that ith area. So, this ensures that the area ith will
        be filled for sure.
        And we know the that ith tap will fill water till (i+ranges[i]), So, we will add +1 at the (i+ranges[i])
        But why?
        Because this will ensure that there are some number of taps which can fill the (i+ranges[i])
        So, whenever in future we will be at that position calculation min. taps for it, we will just add +1
        to its right most edge, this will ensure these are the min. taps to fill that location and +1 for
        any other who can come up to that tap
        */
        vector<int> dp(n + 1, INT_MAX);
        // dp[0] will ensure there are no taps previous to 0th tap which can 0th tap
        dp[0] = 0;
        for (int i = 0; i <= n; i++)
        {
            int lft = max(0, i - ranges[i]);
            int rgt = min(n, i + ranges[i]);
            int ans = INT_MAX;
            for (int k = lft; k <= rgt; k++)
            {
                ans = min(ans, dp[k]);
            }
            if (ans != INT_MAX)
            {
                // this ensures that the area till dp[rgt] is filled by min taps
                // andif ans is the min then +1 for any tap which can it in future.
                // Which ensures min taps till that tap.
                dp[rgt] = min(dp[rgt], 1 + ans);
            }
        }
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};

int main()
{

    return 0;
}