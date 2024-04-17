#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/smallest-string-starting-from-leaf/description/

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
    string ans = "";
    void smallest(TreeNode* root, string s) {
        if(!root ->left && !root->right) {
            s += char(root->val+97);
            reverse(s.begin(), s.end());
            if(ans == "" || ans > s) {
                ans = s;
            }
            return;
        }
        s += char(root->val+97);
        if(root->left) smallest(root->left, s);
        if(root->right) smallest(root->right, s);
    }
    string smallestFromLeaf(TreeNode* root) {
     smallest(root, "");
     return ans;   
    }
};

int main() {
    
    return 0;
}