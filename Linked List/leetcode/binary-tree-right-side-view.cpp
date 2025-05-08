#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/binary-tree-right-side-view/description/

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  vector<int> rightSideView(TreeNode *root)
  {
    if (!root)
      return {};
    queue<pair<TreeNode *, int>> qu;
    vector<int> res;
    qu.push({root, 0});
    while (!qu.empty())
    {
      auto &temp = qu.front();
      TreeNode *node = temp.first;
      int value = temp.second;
      qu.pop();
      if (res.size() == value)
      {
        res.push_back(node->val);
      }
      if (node->right)
        qu.push({node->right, value + 1});
      if (node->left)
        qu.push({node->left, value + 1});
    }
    return res;
  }
};

int main()
{

  return 0;
}