#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/restore-ip-addresses/description/

class Solution
{
public:
  vector<string> ans;
  void find(string &s, string &res, int i, int dot)
  {
    int n = s.size();
    if (dot == 0)
    {
      if (i == n)
      {
        ans.push_back(res);
      }
      return;
    }
    if (dot < 4)
      res += '.';
    for (int j = i, cnt = 0; j < n && cnt++ < 3; j++)
    {
      string str = s.substr(i, j - i + 1);
      if (str.size() > 1 && str[0] == '0')
        break;
      int num = stoi(str);
      if (num > 255)
        break;
      res += str;
      find(s, res, j + 1, dot - 1);
      for (int k = 0; k < str.size(); k++)
        res.pop_back();
    }
    if (dot < 4)
      res.pop_back();
  }
  vector<string> restoreIpAddresses(string s)
  {
    string res = "";
    find(s, res, 0, 4);
    return ans;
  }
};

int main()
{

  return 0;
}