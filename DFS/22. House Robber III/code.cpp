/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,int> dp;
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        if(dp.find(root)!=dp.end()) return dp[root];
        int val=0;
        if(root->left!=NULL) val= val + rob(root->left->left)+rob(root->left->right);
        if(root->right!=NULL) val= val + rob(root->right->left)+rob(root->right->right);
        dp[root]=max(val+root->val, rob(root->left)+rob(root->right));
        return dp[root];
    }
};