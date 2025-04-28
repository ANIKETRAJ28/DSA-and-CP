#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

class Node
{
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val)
  {
    val = _val;
  }

  Node(int _val, vector<Node *> _children)
  {
    val = _val;
    children = _children;
  }
};

class Solution
{
public:
  vector<int> ans;
  vector<int> postorder(Node *root)
  {
    stack<Node *> st;
    if (root)
      st.push(root);
    while (!st.empty())
    {
      Node *temp = st.top();
      st.pop();
      ans.push_back(temp->val);
      vector<Node *> v = temp->children;
      for (int i = 0; i < v.size(); i++)
      {
        st.push(v[i]);
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{

  return 0;
}