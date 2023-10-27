#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/koko-eating-bananas/

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        int lo = 1;
        int hi = 0;
        for (int i = 0; i < n; i++)
        {
            hi = max(hi, piles[i]);
        }
        int ans = 0;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (count > h)
                    break;
                count += piles[i] / mid;
                if (piles[i] % mid)
                    count++;
            }
            if (count > h)
                lo = mid + 1;
            else
            {
                ans = mid;
                hi = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}