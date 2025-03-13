#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        int j = 0;
        queue<int> qu;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2)
                qu.push(i);
            while (j < i && !qu.empty() && qu.size() > k)
            {
                if (nums[j] % 2)
                    qu.pop();
                j++;
            }
            if (qu.size() == k)
                ans += qu.front() - j + 1;
        }
        return ans;
    }
};

class Solution
{
public:
    int atmost(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int res = 0;
        int sum = 0;
        int i = 0, j = 0;
        while (i < n)
        {
            if (nums[i] % 2 == 1)
                sum++;
            while (sum > goal and j <= i)
            {
                if (nums[j] % 2 == 1)
                    sum--;
                j++;
            }
            res += i - j + 1;
            i++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};

class Solution
{
public:
    int minSumSubarray(vector<int> &nums, int k)
    {
        int odd = 0;
        int ans = 0;
        int n = nums.size();
        int i = 0, j = 0;
        while (j < n)
        {
            if (nums[j] % 2)
                odd++;
            while (odd > k)
            {
                ans += j - i;
                if (nums[i] % 2)
                    odd--;
                i++;
            }
            j++;
        }
        while (i < n)
        {
            ans += j - i;
            i++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return minSumSubarray(nums, k) - minSumSubarray(nums, k - 1);
    }
};

int main()
{

    return 0;
}