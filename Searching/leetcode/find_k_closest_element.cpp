#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-k-closest-elements/

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int lo = 0;
        int hi = arr.size() - 1;
        vector<int> ans;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == x)
            {
                ans.push_back(arr[mid]);
                lo = mid - 1;
                hi = mid + 1;
                k--;
                break;
            }
            else if (arr[mid] < x)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        if (lo < hi)
        {
            while (lo >= 0 and hi < arr.size() and k > 0)
            {
                if (abs(arr[lo] - x) <= abs(arr[hi] - x))
                {
                    ans.push_back(arr[lo]);
                    lo--;
                }
                else
                {
                    ans.push_back(arr[hi]);
                    hi++;
                }
                k--;
            }
            if (k > 0)
            {
                if (lo < 0)
                {
                    while (k--)
                    {
                        ans.push_back(arr[hi]);
                        hi++;
                    }
                }
                else
                {
                    while (k--)
                    {
                        ans.push_back(arr[lo]);
                        lo--;
                    }
                }
                k--;
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
        else
        {
            while (hi >= 0 and lo < arr.size() and k > 0)
            {
                if (abs(arr[hi] - x) <= abs(arr[lo] - x))
                {
                    ans.push_back(arr[hi]);
                    hi--;
                }
                else
                {
                    ans.push_back(arr[lo]);
                    lo++;
                }
                k--;
            }
            if (k > 0)
            {
                if (hi < 0)
                {
                    while (k--)
                    {
                        ans.push_back(arr[lo]);
                        lo++;
                    }
                }
                else
                {
                    while (k--)
                    {
                        ans.push_back(arr[hi]);
                        hi--;
                    }
                }
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}