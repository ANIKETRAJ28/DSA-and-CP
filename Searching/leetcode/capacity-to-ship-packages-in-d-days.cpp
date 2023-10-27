#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int lo = 0, hi = 0;
        for (int i = 0; i < n; i++)
        {
            lo = max(lo, weights[i]);
            hi += weights[i];
        }
        int ans = hi;
        while (lo <= hi)
        {
            int count = 1;
            int wts = 0;
            int mid = lo + (hi - lo) / 2;
            for (int i = 0; i < n; i++)
            {
                wts += weights[i];
                if (wts > mid)
                {
                    count++;
                    wts = weights[i];
                }
            }
            if (count <= days)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};

int main()
{

    return 0;
}