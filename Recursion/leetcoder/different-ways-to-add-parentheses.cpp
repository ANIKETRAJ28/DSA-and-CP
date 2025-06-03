#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/different-ways-to-add-parentheses/description/

class Solution
{
public:
  vector<int> diffWaysToCompute(string expression)
  {
    int n = expression.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
      if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
      {
        string lft_str = expression.substr(0, i);
        string rgt_str = expression.substr(i + 1);
        vector<int> lft_ans = diffWaysToCompute(lft_str);
        vector<int> rgt_ans = diffWaysToCompute(rgt_str);
        for (int num_l : lft_ans)
        {
          for (int num_r : rgt_ans)
          {
            if (expression[i] == '+')
            {
              ans.push_back(num_l + num_r);
            }
            else if (expression[i] == '-')
            {
              ans.push_back(num_l - num_r);
            }
            else
            {
              ans.push_back(num_l * num_r);
            }
          }
        }
      }
    }
    if (ans.empty())
    {
      int num = stoi(expression);
      ans.push_back(num);
    }
    return ans;
  }
};

int main()
{

  return 0;
}