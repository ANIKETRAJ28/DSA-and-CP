#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/balanced-binary-tree/description/

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
    int check(TreeNode *root, bool &flag) {
        if(!root || !flag) return 0;
        int lft = check(root->left, flag);
        int rgt = check(root->right, flag);
        if(abs(lft-rgt) > 1) flag = false;
        return 1 + max(lft, rgt);
    }
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        check(root, flag);
        return flag;
    }
};

int main() {
    
    return 0;
}