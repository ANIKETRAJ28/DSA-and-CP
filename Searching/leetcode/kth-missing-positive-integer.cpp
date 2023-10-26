#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/kth-missing-positive-number/

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int lo = 0;
        int hi = n - 1;
        int num = -1;
        int missCnt = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if ((arr[mid] - mid - 1) < k)
            {
                missCnt = arr[mid] - mid - 1;
                num = arr[mid];
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return num + k - missCnt;
    }
};

int main()
{

    return 0;
}