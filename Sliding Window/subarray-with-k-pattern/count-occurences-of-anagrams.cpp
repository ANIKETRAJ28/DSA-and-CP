//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

// } Driver Code Ends

// User function template for C++
class Solution
{
public:
  bool isContaining(unordered_map<char, int> &mp1, unordered_map<char, int> &mp2)
  {
    bool contains = true;
    for (auto it : mp2)
    {
      if (mp1[it.first] != it.second)
      {
        contains = false;
        break;
      }
    }
    return contains;
  }
  int search(string &pat, string &txt)
  {
    // code here
    int m = pat.size();
    int n = txt.size();
    unordered_map<char, int> mp1, mp2;
    for (int i = 0; i < m; i++)
    {
      mp1[pat[i]]++;
      mp2[txt[i]]++;
    }
    int i = 0, j = m;
    int cnt = 0;
    if (isContaining(mp1, mp2))
      cnt++;
    while (j < n)
    {
      mp2[txt[i]]--;
      if (mp2[txt[i]] == 0)
        mp2.erase(txt[i]);
      mp2[txt[j]]++;
      if (isContaining(mp1, mp2))
        cnt++;
      i++;
      j++;
    }
    return cnt;
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string pat, txt;
    cin >> txt >> pat;
    Solution ob;
    auto ans = ob.search(pat, txt);
    cout << ans << "\n";

    cout << "~"
         << "\n";
  }
  return 0;
}
// } Driver Code Ends