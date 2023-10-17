#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution
{
public:
    int search(vector<int> &v, int t)
    {
        int n = v.size();
        int lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (v[mid] == t)
                return mid;
            if (v[hi] > t)
            {
                if (v[mid] < t)
                    lo = mid + 1;
                else
                {
                    if (v[mid] > v[hi])
                        lo = mid + 1;
                    else if (v[mid] < v[hi])
                        hi = mid - 1;
                    else
                        return -1;
                }
            }
            else if (v[hi] < t)
            {
                if (v[mid] > t)
                    hi = mid - 1;
                else if (v[mid] < t)
                {
                    if (v[lo] < v[mid])
                        lo = mid + 1;
                    else
                        hi = mid - 1;
                }
            }
            else
                return hi;
        }
        return -1;
    }
};

int main()
{

    return 0;
}