#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-units-on-a-truck/description/

class Solution
{
public:
    static bool cmp(vector<int> &p1, vector<int> &p2)
    {
        return p1[1] > p2[1];
    }

    int maximumUnits(vector<vector<int>> &boxTypes, int W)
    {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        for (int i = 0; i < boxTypes.size(); i++)
        {
        }
        int ans = 0;
        for (int i = 0; i < boxTypes.size(); i++)
        {
            if (W == 0)
                return ans;
            if (W >= boxTypes[i][0])
            {
                ans += boxTypes[i][1] * boxTypes[i][0];
                W -= boxTypes[i][0];
            }
            else
            {
                ans += boxTypes[i][1] * W;
                W = 0;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int n = s.size(), i = 0, j = 0;
        while (j < n)
        {
            if (s[j] == '1')
            {
                swap(s[i], s[j]);
                i++;
            }
            j++;
        }
        swap(s[i - 1], s[n - 1]);
        return s;
    }
};

int main()
{

    return 0;
}