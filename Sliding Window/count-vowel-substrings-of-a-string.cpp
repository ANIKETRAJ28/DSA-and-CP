#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-vowel-substrings-of-a-string/

class Solution
{
public:
  int countVowelSubstrings(string word)
  {
    int n = word.size();
    int i = 0, j = 0;
    unordered_map<char, int> mp;
    int cnt = 0;
    while (j < n)
    {
      if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u')
      {
        mp[word[j]] = j;
      }
      else
      {
        mp.clear();
        i = j + 1;
      }
      if (mp.size() == 5)
      {
        int minIdx = INT_MAX;
        for (auto it = mp.begin(); it != mp.end(); it++)
          minIdx = min(minIdx, it->second);
        cnt += minIdx - i + 1;
      }
      j++;
    }
    return cnt;
  }
};

int main()
{

  return 0;
}