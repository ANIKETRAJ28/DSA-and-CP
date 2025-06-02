#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
  {
    vector<list<int>> graph(501);
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
    vector<int> ans;
    queue<pair<int, int>> q;
    unordered_set<int> vis;
    q.push({target->val, 0});
    vis.insert(target->val);
    while (!q.empty())
    {
      int node = q.front().first;
      int lvl = q.front().second;
      q.pop();
      if (lvl == k)
      {
        ans.push_back(node);
      }
      else if (lvl < k)
      {
        for (auto el : graph[node])
        {
          if (vis.find(el) != vis.end())
            continue;
          q.push({el, lvl + 1});
          vis.insert(el);
        }
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}