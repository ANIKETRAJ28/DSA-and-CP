#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

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
  int amountOfTime(TreeNode *root, int start)
  {
    vector<list<int>> graph(100001);
    queue<TreeNode *> qu;
    qu.push(root);
    while (!qu.empty())
    {
      TreeNode *node = qu.front();
      qu.pop();
      if (node->left)
      {
        graph[node->val].push_back(node->left->val);
        graph[node->left->val].push_back(node->val);
        qu.push(node->left);
      }
      if (node->right)
      {
        graph[node->val].push_back(node->right->val);
        graph[node->right->val].push_back(node->val);
        qu.push(node->right);
      }
    }
    int ans = 0;
    queue<pair<int, int>> q;
    unordered_set<int> vis;
    q.push({start, 0});
    vis.insert(start);
    while (!q.empty())
    {
      int node = q.front().first;
      int lvl = q.front().second;
      q.pop();
      ans = lvl;
      for (int el : graph[node])
      {
        if (vis.find(el) != vis.end())
          continue;
        vis.insert(el);
        q.push({el, lvl + 1});
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}