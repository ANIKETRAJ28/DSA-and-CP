#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/vowels-of-all-substrings/

class Solution
{
public:
  bool check(char c)
  {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      return true;
    return false;
  }

  long long countVowels(string word)
  {
    long long ans = 0;
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
      if (!check(word[i]))
        continue;
      ans += (long long)(n - i) * (long long)(i + 1);
    }
    return ans;
  }
};

int main()
{

  return 0;
}