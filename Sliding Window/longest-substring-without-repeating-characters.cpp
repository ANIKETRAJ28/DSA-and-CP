#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int n = s.size();
    unordered_set<char> st;
    int i = 0, j = 0;
    int maxLen = 0;
    while (j < n)
    {
      if (st.find(s[j]) == st.end())
      {
        st.insert(s[j]);
        j++;
      }
      else
      {
        maxLen = max(maxLen, j - i);
        while (s[i] != s[j])
        {
          st.erase(s[i]);
          i++;
        }
        i++;
        j++;
      }
    }
    return max(maxLen, j - i);
  }
};

int main()
{

  return 0;
}