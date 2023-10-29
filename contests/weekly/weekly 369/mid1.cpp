#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/

class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        long long s1 = 0, z1 = 0, s2 = 0, z2 = 0;
        for (int i = 0; i < n1; i++)
        {
            if (nums1[i] == 0)
                z1++;
            s1 += nums1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            if (nums2[i] == 0)
                z2++;
            s2 += nums2[i];
        }
        for (int i = 0; i < z1; i++)
        {
            s1++;
        }
        for (int i = 0; i < z2; i++)
        {
            s2++;
        }
        if (s1 == s2)
            return s1;
        if (s2 > s1)
        {
            swap(s1, s2);
            swap(z1, z2);
        }
        if (z2 == 0)
            return -1;
        if (s1 - s2 == 1 and z2 > 1)
            return -1;
        return s1;
    }
};

int main()
{

    return 0;
}