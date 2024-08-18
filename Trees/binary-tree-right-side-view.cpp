#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<pair<int, TreeNode*>> qu;
        qu.push({0, root});
        while(!qu.empty()) {
            auto ele = qu.front();
            qu.pop();
            int n = ele.first;
            TreeNode *temp = ele.second;
            if(ans.size() == n) ans.push_back(temp->val);
            if(temp->right) qu.push({n+1, temp->right});
            if(temp->left) qu.push({n+1, temp->left});
        }
        return ans;
    }
};

int main() {
    
    return 0;
}