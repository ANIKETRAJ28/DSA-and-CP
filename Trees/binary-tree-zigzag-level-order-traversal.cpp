#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> qu;
        bool flag = 0;
        vector<vector<int>> ans;
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            vector<int> node;
            while(size--) {
                TreeNode *temp = qu.front();
                qu.pop();
                node.push_back(temp->val);
                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
            }
            if(flag) reverse(node.begin(), node.end());
            ans.push_back(node);
            flag = !flag;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}