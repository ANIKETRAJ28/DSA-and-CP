#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i/description/

class Solution
{
public:
  long long validSubstringCount(string word1, string word2)
  {
    int n1 = word1.size();
    int n2 = word2.size();
    if (n2 > n1)
      return 0;
    unordered_map<int, int> mp1, mp2;
    for (int i = 0; i < n2; i++)
      mp1[word2[i]]++;
    int need = mp1.size();
    int have = 0;
    int i = 0;
    long long ans = 0;
    for (int j = 0; j < n1; j++)
    {
      if (mp1.find(word1[j]) != mp1.end())
      {
        mp2[word1[j]]++;
        if (mp1[word1[j]] == mp2[word1[j]])
          have++;
      }
      while (i <= j && have == need)
      {
        ans += n1 - j;
        if (mp1.find(word1[i]) != mp1.end())
        {
          if (mp1[word1[i]] == mp2[word1[i]])
            have--;
          mp2[word1[i]]--;
        }
        i++;
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}