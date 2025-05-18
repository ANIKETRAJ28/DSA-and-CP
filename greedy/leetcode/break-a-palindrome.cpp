#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

//  https://leetcode.com/problems/break-a-palindrome/

class Solution
{
public:
  string breakPalindrome(string s)
  {
    int n = s.size();
    if (n == 1)
      return "";
    int i = 0, j = n - 1;
    while (i <= j)
    {
      if (s[i] != s[j])
        return s;
      if (s[i] == s[j])
        break;
      if (s[i] == s[j])
      {
        if (s[i] == 'a')
        {
          i++;
          j--;
          continue;
        }
        s[i] = 'a';
        return s;
        i++;
        j--;
      }
    }
    s[n - 1] = s[n - 1] + 1;
    return s;
  }
};

int main()
{

  return 0;
}