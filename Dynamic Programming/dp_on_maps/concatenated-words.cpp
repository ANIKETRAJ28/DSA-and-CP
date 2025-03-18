#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/concatenated-words/description/

class Solution
{
public:
  unordered_map<string, bool> mp;
  unordered_set<string> st;
  bool isConcatinated(string word)
  {
    int n = word.size();
    if (mp.find(word) != mp.end())
      return mp[word];
    for (int i = 0; i < n; i++)
    {
      string prefix = word.substr(0, i + 1);
      string suffix = word.substr(i + 1);
      if ((st.find(prefix) != st.end() && st.find(suffix) != st.end()) ||
          (st.find(prefix) != st.end() && isConcatinated(suffix)))
        return mp[word] = true;
    }
    return mp[word] = false;
  }
  vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
  {
    int n = words.size();
    for (int i = 0; i < n; i++)
    {
      st.insert(words[i]);
    }
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
      if (isConcatinated(words[i]))
      {
        ans.push_back(words[i]);
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}