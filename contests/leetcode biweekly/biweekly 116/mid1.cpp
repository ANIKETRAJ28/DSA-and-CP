#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

class Solution
{
public:
    int minChanges(string s)
    {
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n - 1; i += 2)
        {
            if (s[i] != s[i + 1])
                cnt++;
        }
        return cnt;
    }
};

int main()
{

    return 0;
}