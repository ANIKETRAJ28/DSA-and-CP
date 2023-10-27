#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://practice.geeksforgeeks.org/problems/aggressive-cows/0

class Solution
{
public:
    int solve(int n, int k, vector<int> &stalls)
    {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int lo = 1;
        int hi = stalls[n - 1] - stalls[0];
        int ans = 0;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int pos = stalls[0];
            int count = 1;
            for (int i = 0; i < n; i++)
            {
                if (pos + mid <= stalls[i])
                {
                    count++;
                    pos = stalls[i];
                    if (count == k)
                        break;
                }
            }
            if (count == k)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return ans;
    }
};

int main()
{

    return 0;
}