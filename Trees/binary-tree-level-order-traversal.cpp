#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> lvl;
        queue<TreeNode*> lvlOdr;
        lvlOdr.push(root);
        while(!lvlOdr.empty()) {
            int size = lvlOdr.size();
            vector<int> lvls;
            while(size--) {
                TreeNode *temp = lvlOdr.front();
                lvlOdr.pop();
                lvls.push_back(temp->val);
                if(temp->left) lvlOdr.push(temp->left);
                if(temp->right) lvlOdr.push(temp->right);
            }
            lvl.push_back(lvls);
        }
        return lvl;
    }
};

int main() {
    
    return 0;
}