#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

class Solution
{
public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long lo = 0;
        long long hi = 0;
        long long ans = -1;
        for (int i = 0; i < n; i++)
        {
            lo = max(lo, (long long)arr[i]);
            hi += arr[i];
        }
        while (lo <= hi)
        {
            long long mid = lo + (hi - lo) / 2;
            int count = 1;
            long long paint = 0;
            for (int i = 0; i < n; i++)
            {
                paint += arr[i];
                if (paint > mid)
                {
                    count++;
                    paint = arr[i];
                }
            }
            if (count <= k)
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