#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// https://leetcode.com/problems/find-bottom-left-tree-value/description/

class Solution
{
public:
  int level = -1, ans = -1;
  int findBottomLeftValue(TreeNode *root)
  {
    queue<pair<TreeNode *, int>> qu;
    qu.push({root, 0});
    while (!qu.empty())
    {
      auto &temp = qu.front();
      TreeNode *node = temp.first;
      int value = temp.second;
      qu.pop();
      if (value > level)
      {
        level = value;
        ans = node->val;
      }
      if (node->left)
        qu.push({node->left, value + 1});
      if (node->right)
        qu.push({node->right, value + 1});
    }
    return ans;
  }
};

int main()
{

  return 0;
}