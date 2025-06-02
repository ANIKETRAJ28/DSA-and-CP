#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/unique-binary-search-trees-ii/description

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
  map<pair<int, int>, vector<TreeNode *>> dp;
  vector<TreeNode *> generate(int start, int end)
  {
    if (start > end)
    {
      return {NULL};
    }
    if (start == end)
    {
      TreeNode *root = new TreeNode(start);
      return {root};
    }
    if (dp.find({start, end}) != dp.end())
      return dp[{start, end}];
    vector<TreeNode *> ans;
    for (int i = start; i <= end; i++)
    {
      vector<TreeNode *> left_tree = generate(start, i - 1);
      vector<TreeNode *> right_tree = generate(i + 1, end);
      for (TreeNode *lft_node : left_tree)
      {
        for (TreeNode *rgt_node : right_tree)
        {
          TreeNode *node = new TreeNode(i);
          node->left = lft_node;
          node->right = rgt_node;
          ans.push_back(node);
        }
      }
    }
    return dp[{start, end}] = ans;
  }
  vector<TreeNode *> generateTrees(int n)
  {
    vector<TreeNode *> ans = generate(1, n);
    return ans;
  }
};

int main()
{

  return 0;
}