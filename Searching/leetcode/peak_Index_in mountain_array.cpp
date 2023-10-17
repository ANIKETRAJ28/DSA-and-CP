#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int lo = 1;
        int hi = arr.size() - 2;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if ((arr[mid] > arr[mid - 1]) and (arr[mid] > arr[mid + 1]))
                return mid;
            else if (arr[mid] > arr[mid + 1])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return -1;
    }
};

int main()
{

    return 0;
}