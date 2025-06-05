#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/word-ladder/description/

class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {
    int n = wordList.size();
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> qu;
    qu.push({beginWord, 1});
    while (!qu.empty())
    {
      auto word = qu.front().first;
      auto count = qu.front().second;
      qu.pop();
      if (word == endWord)
        return count;
      st.erase(word);
      for (int i = 0; i < word.size(); i++)
      {
        for (int j = 0; j < 26; j++)
        {
          string new_word = word;
          new_word[i] = 'a' + j;
          if (!st.count(new_word))
            continue;
          qu.push({new_word, count + 1});
        }
      }
    }
    return 0;
  }
};

int main()
{

  return 0;
}