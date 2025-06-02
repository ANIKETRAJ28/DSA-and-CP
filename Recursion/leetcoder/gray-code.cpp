#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/gray-code/description

class Solution
{
public:
  vector<string> generate(int n)
  {
    if (n == 1)
    {
      return {"0", "1"};
    }
    vector<string> ans;
    vector<string> temp = generate(n - 1);
    for (int i = 0; i < temp.size(); i++)
    {
      ans.push_back('0' + temp[i]);
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
      ans.push_back('1' + temp[i]);
    }
    return ans;
  }
  vector<int> grayCode(int n)
  {
    vector<string> temp = generate(n);
    vector<int> ans;
    for (string s : temp)
    {
      ans.push_back(stoi(s, NULL, 2));
    }
    return ans;
  }
};

int main()
{

  return 0;
}