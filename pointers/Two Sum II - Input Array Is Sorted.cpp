#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        vector<int> ans;
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (numbers[i] + numbers[j] == target)
            {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                break;
            }
            else if (numbers[i] + numbers[j] > target)
                j--;
            else
                i++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}